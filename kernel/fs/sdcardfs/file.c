/*
 * Copyright (c) 1998-2011 Erez Zadok
 * Copyright (c) 2009	   Shrikar Archak
 * Copyright (c) 2003-2011 Stony Brook University
 * Copyright (c) 2003-2011 The Research Foundation of SUNY
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "sdcardfs.h"
#ifdef CONFIG_SDCARD_FS_FADV_NOACTIVE
#include <linux/backing-dev.h>
#endif

static ssize_t sdcardfs_read(struct file *file, char __user *buf,
			   size_t count, loff_t *ppos)
{
	int err;
	struct file *lower_file;
	struct dentry *dentry = file->f_path.dentry;
#ifdef CONFIG_SDCARD_FS_FADV_NOACTIVE
	struct backing_dev_info *bdi;
#endif

	lower_file = sdcardfs_lower_file(file);

#ifdef CONFIG_SDCARD_FS_FADV_NOACTIVE
	if (file->f_mode & FMODE_NOACTIVE) {
		if (!(lower_file->f_mode & FMODE_NOACTIVE)) {
			bdi = lower_file->f_mapping->backing_dev_info;
			lower_file->f_ra.ra_pages = bdi->ra_pages * 2;
			spin_lock(&lower_file->f_lock);
			lower_file->f_mode |= FMODE_NOACTIVE;
			spin_unlock(&lower_file->f_lock);
		}
	}
#endif

	err = vfs_read(lower_file, buf, count, ppos);
	/* update our inode atime upon a successful lower read */
	if (err >= 0)
		fsstack_copy_attr_atime(dentry->d_inode,
					lower_file->f_path.dentry->d_inode);

	return err;
}

static ssize_t sdcardfs_write(struct file *file, const char __user *buf,
			    size_t count, loff_t *ppos)
{
	int err = 0;
	struct file *lower_file;
	struct dentry *dentry = file->f_path.dentry;

#if defined(LOWER_FS_MIN_FREE_SIZE)
	/* check disk space */
	if (!check_min_free_space(dentry, count, 0)) {
		printk(KERN_INFO "No minimum free space.\n");
		return -ENOSPC;
	}
#endif

	lower_file = sdcardfs_lower_file(file);
	err = vfs_write(lower_file, buf, count, ppos);
	/* update our inode times+sizes upon a successful lower write */
	if (err >= 0) {
		fsstack_copy_inode_size(dentry->d_inode,
					lower_file->f_path.dentry->d_inode);
		fsstack_copy_attr_times(dentry->d_inode,
					lower_file->f_path.dentry->d_inode);
	}

	return err;
}

#include <linux/dirent.h>
struct getdents_callback64 {
	struct linux_dirent64 __user * current_dir;
	struct linux_dirent64 __user * previous;
	int count;
	int error;
};

static int sdcardfs_readdir(struct file *file, void *dirent, filldir_t filldir)
{
	int err = 0;
	struct file *lower_file = NULL;
	struct dentry *dentry = file->f_path.dentry;
	struct getdents_callback64* buf = dirent;
	struct linux_dirent64* __user dirent_cur = buf->current_dir;
	int buf_size = buf->count;

	lower_file = sdcardfs_lower_file(file);
	lower_file->f_pos = file->f_pos;
 
	 err = vfs_readdir(lower_file, filldir, buf);

	 /* cts 4.4_r1 has test cases for read/write file on /storage/sdcard0, /storage/sdcard1 and list all folder/file under /storage/sdcard0, /storage/sdcard1 to delete.
			CTS test case: run cts -c com.android.cts.appsecurity.AppSecurityTests -m testExternalStorageWrite
			.android_secure is bindmount on /mnt/secure/asec, which cannot be deleted and is protected by handle_unlink()->check_caller_access_to_name()
			We decide let other user space process not aware of .android_secure existence
	 */  

     if (buf->previous) {
		 int rec_scan_size = 0;
		 struct linux_dirent64* dirent_p;
		 int dirent_p_size = dirent_p_size = ALIGN(sizeof(struct linux_dirent64)+strlen(".android_secure")+1, sizeof(u64));
		 dirent_p = kmalloc(dirent_p_size, GFP_KERNEL);
		 if (!dirent_p) {
			 SDFS_ERR("kmalloc() fail \n");			 
		 }
         else {
			 while ( dirent_cur <=  buf->previous) {
				 if(copy_from_user(dirent_p, dirent_cur, dirent_p_size)) {
					 SDFS_ERR("copy_from_user() fail \n");
					 break;
				 }
				 else {
					//printk("%s#%d: dirent_p=%p, dirent_p->d_name='%s', dirent_p->d_reclen=%d \n", __FUNCTION__, __LINE__, dirent_p, dirent_p->d_name, dirent_p->d_reclen);
					dirent_cur = (void __user *)dirent_cur + dirent_p->d_reclen;
				 }		 
				 //printk("%s#%d: dirent_begin='%p',  dirent_begin=%p \n", __FUNCTION__, __LINE__, dirent_begin, dirent_begin);

				 rec_scan_size += dirent_p->d_reclen;
	             if (!strcasecmp(dirent_p->d_name, ".android_secure")
	              || !strcasecmp(dirent_p->d_name, "android_secure")) {
				
	               int move_size = buf_size - buf->count - rec_scan_size; 
				   void* move_pos = kmalloc(move_size, GFP_KERNEL);
				   if (!move_pos) {
	                  SDFS_ERR("kmalloc() fail \n");
					  break;	   
				   }
	               
				   //printk("%s#%d: move_size='%d',  buf_size=%d, rec_scan_size=%d , buf->count=%d \n", __FUNCTION__, __LINE__, move_size, buf_size, rec_scan_size, buf->count);
	          	   if(copy_from_user(move_pos, dirent_cur, move_size)) {
					   SDFS_ERR("copy_from_user() fail \n");
					   kfree(move_pos);
					   break;
	               }
	               //  printk("%s#%d: rtn='%d',  move_pos=%p \n", __FUNCTION__, __LINE__, rtn, move_pos); 
				   if(copy_to_user((void __user *)dirent_cur -  dirent_p->d_reclen, move_pos, move_size)) {
					   SDFS_ERR("copy_to_user() fail \n");
					   kfree(move_pos);
					   break;
				   }

				   //printk("%s#%d: rtn='%d' \n", __FUNCTION__, __LINE__, rtn); 
				   buf->count += dirent_p->d_reclen;
	               kfree(move_pos);
	               break;
	             }
				
			 }
			 kfree(dirent_p);
         }
     } 

	file->f_pos = lower_file->f_pos;
	if (err >= 0)		/* copy the atime */
		fsstack_copy_attr_atime(dentry->d_inode,
					lower_file->f_path.dentry->d_inode);
	return err;
}

static long sdcardfs_unlocked_ioctl(struct file *file, unsigned int cmd,
				  unsigned long arg)
{
	long err = -ENOTTY;
	struct file *lower_file;

	lower_file = sdcardfs_lower_file(file);

	/* XXX: use vfs_ioctl if/when VFS exports it */
	if (!lower_file || !lower_file->f_op)
		goto out;
	if (lower_file->f_op->unlocked_ioctl)
		err = lower_file->f_op->unlocked_ioctl(lower_file, cmd, arg);

out:
	return err;
}

#ifdef CONFIG_COMPAT
static long sdcardfs_compat_ioctl(struct file *file, unsigned int cmd,
				unsigned long arg)
{
	long err = -ENOTTY;
	struct file *lower_file;

	lower_file = sdcardfs_lower_file(file);

	/* XXX: use vfs_ioctl if/when VFS exports it */
	if (!lower_file || !lower_file->f_op)
		goto out;
	if (lower_file->f_op->compat_ioctl)
		err = lower_file->f_op->compat_ioctl(lower_file, cmd, arg);

out:
	return err;
}
#endif

static int sdcardfs_mmap(struct file *file, struct vm_area_struct *vma)
{
	int err = 0;
	bool willwrite;
	struct file *lower_file;
	const struct vm_operations_struct *saved_vm_ops = NULL;

	/* this might be deferred to mmap's writepage */
	willwrite = ((vma->vm_flags | VM_SHARED | VM_WRITE) == vma->vm_flags);

	/*
	 * File systems which do not implement ->writepage may use
	 * generic_file_readonly_mmap as their ->mmap op.  If you call
	 * generic_file_readonly_mmap with VM_WRITE, you'd get an -EINVAL.
	 * But we cannot call the lower ->mmap op, so we can't tell that
	 * writeable mappings won't work.  Therefore, our only choice is to
	 * check if the lower file system supports the ->writepage, and if
	 * not, return EINVAL (the same error that
	 * generic_file_readonly_mmap returns in that case).
	 */
	lower_file = sdcardfs_lower_file(file);
	if (willwrite && !lower_file->f_mapping->a_ops->writepage) {
		err = -EINVAL;
		printk(KERN_ERR "sdcardfs: lower file system does not "
		       "support writeable mmap\n");
		goto out;
	}

	/*
	 * find and save lower vm_ops.
	 *
	 * XXX: the VFS should have a cleaner way of finding the lower vm_ops
	 */
	if (!SDCARDFS_F(file)->lower_vm_ops) {
		err = lower_file->f_op->mmap(lower_file, vma);
		if (err) {
			printk(KERN_ERR "sdcardfs: lower mmap failed %d\n", err);
			goto out;
		}
		saved_vm_ops = vma->vm_ops; /* save: came from lower ->mmap */
		err = do_munmap(current->mm, vma->vm_start,
				vma->vm_end - vma->vm_start);
		if (err) {
			printk(KERN_ERR "sdcardfs: do_munmap failed %d\n", err);
			goto out;
		}
	}

	/*
	 * Next 3 lines are all I need from generic_file_mmap.  I definitely
	 * don't want its test for ->readpage which returns -ENOEXEC.
	 */
	file_accessed(file);
	vma->vm_ops = &sdcardfs_vm_ops;
	vma->vm_flags |= VM_CAN_NONLINEAR;

	file->f_mapping->a_ops = &sdcardfs_aops; /* set our aops */
	if (!SDCARDFS_F(file)->lower_vm_ops) /* save for our ->fault */
		SDCARDFS_F(file)->lower_vm_ops = saved_vm_ops;

out:
	return err;
}

static int sdcardfs_open(struct inode *inode, struct file *file, bool isdir)
{
	int err = 0;
	struct file *lower_file = NULL;
	struct path lower_path;
    bool has_rw;

	SDFS_DBG("d_name='%s', isdir=%d \n",file->f_path.dentry->d_name.name, isdir);

	/* don't open unhashed/deleted files */
	if (d_unhashed(file->f_path.dentry)) {
		err = -ENOENT;
		goto out_err;
	}

    if (isdir) {
		if (!check_caller_access_to_node(file->f_path.dentry, R_OK, false)) {
			 return -EACCES;
		}
    }
    else {
        unsigned int f_flags = file->f_flags & ~(O_CREAT | O_EXCL | O_NOCTTY);
		SDFS_DBG("f_flags=0x%x \n",file->f_path.dentry->d_name.name, f_flags);
		has_rw = get_caller_has_rw_locked(SDCARDFS_SB(inode->i_sb));
		if (!check_caller_access_to_name(file->f_path.dentry, open_flags_to_access_mode(f_flags), has_rw)) {
			return -EACCES;
		}
    }

	file->private_data =
		kzalloc(sizeof(struct sdcardfs_file_info), GFP_KERNEL);
	if (!SDCARDFS_F(file)) {
		err = -ENOMEM;
		goto out_err;
	}

	/* open lower object and link sdcardfs's file struct to lower's */
	sdcardfs_get_lower_path(file->f_path.dentry, &lower_path);
	lower_file = dentry_open(lower_path.dentry, lower_path.mnt,
				 file->f_flags, current_cred());
	if (IS_ERR(lower_file)) {
		err = PTR_ERR(lower_file);
		lower_file = sdcardfs_lower_file(file);
		if (lower_file) {
			sdcardfs_set_lower_file(file, NULL);
			fput(lower_file); /* fput calls dput for lower_dentry */
		}
	} else {
		sdcardfs_set_lower_file(file, lower_file);
	}

	if (err)
		kfree(SDCARDFS_F(file));
	else {
		fsstack_copy_attr_all(inode, sdcardfs_lower_inode(inode));
		fix_fat_permission(inode); 
		derive_permissions_locked(file->f_path.dentry);	     
	}
out_err:
	return err;
}

static int sdcardfs_dir_open(struct inode *inode, struct file *file)
{
    return sdcardfs_open(inode, file, true);
}

static int sdcardfs_file_open(struct inode *inode, struct file *file)
{
    return sdcardfs_open(inode, file, false);
}


static int sdcardfs_flush(struct file *file, fl_owner_t id)
{
	int err = 0;
	struct file *lower_file = NULL;

	lower_file = sdcardfs_lower_file(file);
	if (lower_file && lower_file->f_op && lower_file->f_op->flush)
		err = lower_file->f_op->flush(lower_file, id);

	return err;
}

/* release all lower object references & free the file info structure */
static int sdcardfs_file_release(struct inode *inode, struct file *file)
{
	struct file *lower_file;

	lower_file = sdcardfs_lower_file(file);
	if (lower_file) {
		sdcardfs_set_lower_file(file, NULL);
		fput(lower_file);
	}

	kfree(SDCARDFS_F(file));
	return 0;
}

static int
sdcardfs_fsync(struct file *file, loff_t start, loff_t end, int datasync)
{
	int err;
	struct file *lower_file;
	struct path lower_path;
	struct dentry *dentry = file->f_path.dentry;

	lower_file = sdcardfs_lower_file(file);
	sdcardfs_get_lower_path(dentry, &lower_path);
	err = vfs_fsync_range(lower_file, start, end, datasync);
	sdcardfs_put_lower_path(dentry, &lower_path);

	return err;
}

static int sdcardfs_fasync(int fd, struct file *file, int flag)
{
	int err = 0;
	struct file *lower_file = NULL;

	lower_file = sdcardfs_lower_file(file);
	if (lower_file->f_op && lower_file->f_op->fasync)
		err = lower_file->f_op->fasync(fd, lower_file, flag);

	return err;
}

const struct file_operations sdcardfs_main_fops = {
	.llseek		= generic_file_llseek,
	.read		= sdcardfs_read,
	.write		= sdcardfs_write,
	.unlocked_ioctl	= sdcardfs_unlocked_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl	= sdcardfs_compat_ioctl,
#endif
	.mmap		= sdcardfs_mmap,
	.open		= sdcardfs_file_open,
	.flush		= sdcardfs_flush,
	.release	= sdcardfs_file_release,
	.fsync		= sdcardfs_fsync,
	.fasync		= sdcardfs_fasync,
};

/* trimmed directory options */
const struct file_operations sdcardfs_dir_fops = {
	.llseek		= generic_file_llseek,
	.read		= generic_read_dir,
	.readdir	= sdcardfs_readdir,
	.unlocked_ioctl	= sdcardfs_unlocked_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl	= sdcardfs_compat_ioctl,
#endif
	.open		= sdcardfs_dir_open,
	.release	= sdcardfs_file_release,
	.flush		= sdcardfs_flush,
	.fsync		= sdcardfs_fsync,
	.fasync		= sdcardfs_fasync,
};
