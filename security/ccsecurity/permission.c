/*
 * security/ccsecurity/permission.c
 *
 * Copyright (C) 2005-2012  NTT DATA CORPORATION
 *
 * Version: 1.8.3+   2012/05/05
 */

#include "internal.h"

/*                                        */

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 32)

/*
                                                                         
                                                                               
                                                                            
                                
 */
#ifdef ACC_MODE
#error ACC_MODE already defined.
#endif
#define ACC_MODE(x) ("\000\004\002\006"[(x)&O_ACCMODE])

#if defined(RHEL_MAJOR) && RHEL_MAJOR == 6
/*                                                          */
#undef ACC_MODE
#define ACC_MODE(x) ("\004\002\006"[(x)&O_ACCMODE])
#endif

#endif

/*                                            */
static const char * const ccs_mounts[CCS_MAX_SPECIAL_MOUNT] = {
	[CCS_MOUNT_BIND]            = "--bind",
	[CCS_MOUNT_MOVE]            = "--move",
	[CCS_MOUNT_REMOUNT]         = "--remount",
	[CCS_MOUNT_MAKE_UNBINDABLE] = "--make-unbindable",
	[CCS_MOUNT_MAKE_PRIVATE]    = "--make-private",
	[CCS_MOUNT_MAKE_SLAVE]      = "--make-slave",
	[CCS_MOUNT_MAKE_SHARED]     = "--make-shared",
};

/*                                                                       */
static const u8 ccs_p2mac[CCS_MAX_PATH_OPERATION] = {
	[CCS_TYPE_EXECUTE]    = CCS_MAC_FILE_EXECUTE,
	[CCS_TYPE_READ]       = CCS_MAC_FILE_OPEN,
	[CCS_TYPE_WRITE]      = CCS_MAC_FILE_OPEN,
	[CCS_TYPE_APPEND]     = CCS_MAC_FILE_OPEN,
	[CCS_TYPE_UNLINK]     = CCS_MAC_FILE_UNLINK,
#ifdef CONFIG_CCSECURITY_FILE_GETATTR
	[CCS_TYPE_GETATTR]    = CCS_MAC_FILE_GETATTR,
#endif
	[CCS_TYPE_RMDIR]      = CCS_MAC_FILE_RMDIR,
	[CCS_TYPE_TRUNCATE]   = CCS_MAC_FILE_TRUNCATE,
	[CCS_TYPE_SYMLINK]    = CCS_MAC_FILE_SYMLINK,
	[CCS_TYPE_CHROOT]     = CCS_MAC_FILE_CHROOT,
	[CCS_TYPE_UMOUNT]     = CCS_MAC_FILE_UMOUNT,
};

/*                                                                        */
const u8 ccs_pnnn2mac[CCS_MAX_MKDEV_OPERATION] = {
	[CCS_TYPE_MKBLOCK] = CCS_MAC_FILE_MKBLOCK,
	[CCS_TYPE_MKCHAR]  = CCS_MAC_FILE_MKCHAR,
};

/*                                                                        */
const u8 ccs_pp2mac[CCS_MAX_PATH2_OPERATION] = {
	[CCS_TYPE_LINK]       = CCS_MAC_FILE_LINK,
	[CCS_TYPE_RENAME]     = CCS_MAC_FILE_RENAME,
	[CCS_TYPE_PIVOT_ROOT] = CCS_MAC_FILE_PIVOT_ROOT,
};

/*
                                                                               
 */
const u8 ccs_pn2mac[CCS_MAX_PATH_NUMBER_OPERATION] = {
	[CCS_TYPE_CREATE] = CCS_MAC_FILE_CREATE,
	[CCS_TYPE_MKDIR]  = CCS_MAC_FILE_MKDIR,
	[CCS_TYPE_MKFIFO] = CCS_MAC_FILE_MKFIFO,
	[CCS_TYPE_MKSOCK] = CCS_MAC_FILE_MKSOCK,
	[CCS_TYPE_IOCTL]  = CCS_MAC_FILE_IOCTL,
	[CCS_TYPE_CHMOD]  = CCS_MAC_FILE_CHMOD,
	[CCS_TYPE_CHOWN]  = CCS_MAC_FILE_CHOWN,
	[CCS_TYPE_CHGRP]  = CCS_MAC_FILE_CHGRP,
};

#ifdef CONFIG_CCSECURITY_NETWORK

/*
                                                                              
                      
 */
static const u8 ccs_inet2mac[CCS_SOCK_MAX][CCS_MAX_NETWORK_OPERATION] = {
	[SOCK_STREAM] = {
		[CCS_NETWORK_BIND]    = CCS_MAC_NETWORK_INET_STREAM_BIND,
		[CCS_NETWORK_LISTEN]  = CCS_MAC_NETWORK_INET_STREAM_LISTEN,
		[CCS_NETWORK_CONNECT] = CCS_MAC_NETWORK_INET_STREAM_CONNECT,
		[CCS_NETWORK_ACCEPT]  = CCS_MAC_NETWORK_INET_STREAM_ACCEPT,
	},
	[SOCK_DGRAM] = {
		[CCS_NETWORK_BIND]    = CCS_MAC_NETWORK_INET_DGRAM_BIND,
		[CCS_NETWORK_SEND]    = CCS_MAC_NETWORK_INET_DGRAM_SEND,
#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG
		[CCS_NETWORK_RECV]    = CCS_MAC_NETWORK_INET_DGRAM_RECV,
#endif
	},
	[SOCK_RAW]    = {
		[CCS_NETWORK_BIND]    = CCS_MAC_NETWORK_INET_RAW_BIND,
		[CCS_NETWORK_SEND]    = CCS_MAC_NETWORK_INET_RAW_SEND,
#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG
		[CCS_NETWORK_RECV]    = CCS_MAC_NETWORK_INET_RAW_RECV,
#endif
	},
};

/*
                                                                              
                      
 */
static const u8 ccs_unix2mac[CCS_SOCK_MAX][CCS_MAX_NETWORK_OPERATION] = {
	[SOCK_STREAM] = {
		[CCS_NETWORK_BIND]    = CCS_MAC_NETWORK_UNIX_STREAM_BIND,
		[CCS_NETWORK_LISTEN]  = CCS_MAC_NETWORK_UNIX_STREAM_LISTEN,
		[CCS_NETWORK_CONNECT] = CCS_MAC_NETWORK_UNIX_STREAM_CONNECT,
		[CCS_NETWORK_ACCEPT]  = CCS_MAC_NETWORK_UNIX_STREAM_ACCEPT,
	},
	[SOCK_DGRAM] = {
		[CCS_NETWORK_BIND]    = CCS_MAC_NETWORK_UNIX_DGRAM_BIND,
		[CCS_NETWORK_SEND]    = CCS_MAC_NETWORK_UNIX_DGRAM_SEND,
#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG
		[CCS_NETWORK_RECV]    = CCS_MAC_NETWORK_UNIX_DGRAM_RECV,
#endif
	},
	[SOCK_SEQPACKET] = {
		[CCS_NETWORK_BIND]    = CCS_MAC_NETWORK_UNIX_SEQPACKET_BIND,
		[CCS_NETWORK_LISTEN]  = CCS_MAC_NETWORK_UNIX_SEQPACKET_LISTEN,
		[CCS_NETWORK_CONNECT] = CCS_MAC_NETWORK_UNIX_SEQPACKET_CONNECT,
		[CCS_NETWORK_ACCEPT]  = CCS_MAC_NETWORK_UNIX_SEQPACKET_ACCEPT,
	},
};

#endif

#ifdef CONFIG_CCSECURITY_CAPABILITY

/*
                                                                              
 */
const u8 ccs_c2mac[CCS_MAX_CAPABILITY_INDEX] = {
	[CCS_USE_ROUTE_SOCKET]  = CCS_MAC_CAPABILITY_USE_ROUTE_SOCKET,
	[CCS_USE_PACKET_SOCKET] = CCS_MAC_CAPABILITY_USE_PACKET_SOCKET,
	[CCS_SYS_REBOOT]        = CCS_MAC_CAPABILITY_SYS_REBOOT,
	[CCS_SYS_VHANGUP]       = CCS_MAC_CAPABILITY_SYS_VHANGUP,
	[CCS_SYS_SETTIME]       = CCS_MAC_CAPABILITY_SYS_SETTIME,
	[CCS_SYS_NICE]          = CCS_MAC_CAPABILITY_SYS_NICE,
	[CCS_SYS_SETHOSTNAME]   = CCS_MAC_CAPABILITY_SYS_SETHOSTNAME,
	[CCS_USE_KERNEL_MODULE] = CCS_MAC_CAPABILITY_USE_KERNEL_MODULE,
	[CCS_SYS_KEXEC_LOAD]    = CCS_MAC_CAPABILITY_SYS_KEXEC_LOAD,
	[CCS_SYS_PTRACE]        = CCS_MAC_CAPABILITY_SYS_PTRACE,
};

#endif

/*                                        */

/*                                                     */
struct ccs_inet_addr_info {
	u16 port;           /*                        */
	const u32 *address; /*                        */
	bool is_ipv6;
};

/*                                                     */
struct ccs_unix_addr_info {
	u8 *addr; /*                                         */
	unsigned int addr_len;
};

/*                                       */
struct ccs_addr_info {
	u8 protocol;
	u8 operation;
	struct ccs_inet_addr_info inet;
	struct ccs_unix_addr_info unix0;
};

/*                                                */

bool ccs_dump_page(struct linux_binprm *bprm, unsigned long pos,
		   struct ccs_page_dump *dump);
void ccs_get_attributes(struct ccs_obj_info *obj);

static bool ccs_alphabet_char(const char c);
static bool ccs_argv(const unsigned int index, const char *arg_ptr,
		     const int argc, const struct ccs_argv *argv, u8 *checked);
static bool ccs_byte_range(const char *str);
static bool ccs_check_entry(struct ccs_request_info *r,
			    struct ccs_acl_info *ptr);
static bool ccs_check_mkdev_acl(struct ccs_request_info *r,
				const struct ccs_acl_info *ptr);
static bool ccs_check_mount_acl(struct ccs_request_info *r,
				const struct ccs_acl_info *ptr);
static bool ccs_check_path2_acl(struct ccs_request_info *r,
				const struct ccs_acl_info *ptr);
static bool ccs_check_path_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr);
static bool ccs_check_path_number_acl(struct ccs_request_info *r,
				      const struct ccs_acl_info *ptr);
static bool ccs_compare_number_union(const unsigned long value,
				     const struct ccs_number_union *ptr);
static bool ccs_condition(struct ccs_request_info *r,
			  const struct ccs_condition *cond);
static bool ccs_decimal(const char c);
static bool ccs_envp(const char *env_name, const char *env_value,
		     const int envc, const struct ccs_envp *envp, u8 *checked);
static bool ccs_file_matches_pattern(const char *filename,
				     const char *filename_end,
				     const char *pattern,
				     const char *pattern_end);
static bool ccs_file_matches_pattern2(const char *filename,
				      const char *filename_end,
				      const char *pattern,
				      const char *pattern_end);
static bool ccs_get_realpath(struct ccs_path_info *buf, struct path *path);
static bool ccs_hexadecimal(const char c);
static bool ccs_number_matches_group(const unsigned long min,
				     const unsigned long max,
				     const struct ccs_group *group);
static bool ccs_path_matches_pattern(const struct ccs_path_info *filename,
				     const struct ccs_path_info *pattern);
static bool ccs_path_matches_pattern2(const char *f, const char *p);
static bool ccs_scan_bprm(struct ccs_execve *ee, const u16 argc,
			  const struct ccs_argv *argv, const u16 envc,
			  const struct ccs_envp *envp);
static bool ccs_scan_exec_realpath(struct file *file,
				   const struct ccs_name_union *ptr,
				   const bool match);
static bool ccs_scan_transition(const struct list_head *list,
				const struct ccs_path_info *domainname,
				const struct ccs_path_info *program,
				const char *last_name,
				const enum ccs_transition_type type);
static const char *ccs_last_word(const char *name);
static const struct ccs_path_info *ccs_compare_name_union
(const struct ccs_path_info *name, const struct ccs_name_union *ptr);
static const struct ccs_path_info *ccs_path_matches_group
(const struct ccs_path_info *pathname, const struct ccs_group *group);
static enum ccs_transition_type ccs_transition_type
(const struct ccs_policy_namespace *ns, const struct ccs_path_info *domainname,
 const struct ccs_path_info *program);
static int __ccs_chmod_permission(struct dentry *dentry,
				  struct vfsmount *vfsmnt, mode_t mode);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 5, 0)
static int __ccs_chown_permission(struct dentry *dentry,
				  struct vfsmount *vfsmnt, kuid_t user,
				  kgid_t group);
#else
static int __ccs_chown_permission(struct dentry *dentry,
				  struct vfsmount *vfsmnt, uid_t user,
				  gid_t group);
#endif
static int __ccs_chroot_permission(struct path *path);
static int __ccs_fcntl_permission(struct file *file, unsigned int cmd,
				  unsigned long arg);
static int __ccs_ioctl_permission(struct file *filp, unsigned int cmd,
				  unsigned long arg);
static int __ccs_link_permission(struct dentry *old_dentry,
				 struct dentry *new_dentry,
				 struct vfsmount *mnt);
static int __ccs_mkdir_permission(struct dentry *dentry, struct vfsmount *mnt,
				  unsigned int mode);
static int __ccs_mknod_permission(struct dentry *dentry, struct vfsmount *mnt,
				  const unsigned int mode, unsigned int dev);
static int __ccs_mount_permission(const char *dev_name, struct path *path,
				  const char *type, unsigned long flags,
				  void *data_page);
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 30)
static int __ccs_open_exec_permission(struct dentry *dentry,
				      struct vfsmount *mnt);
#endif
static int __ccs_open_permission(struct dentry *dentry, struct vfsmount *mnt,
				 const int flag);
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 18) || (LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 33) && defined(CONFIG_SYSCTL_SYSCALL))
static int __ccs_parse_table(int __user *name, int nlen, void __user *oldval,
			     void __user *newval, struct ctl_table *table);
#endif
static int __ccs_pivot_root_permission(struct path *old_path,
				       struct path *new_path);
static int __ccs_rename_permission(struct dentry *old_dentry,
				   struct dentry *new_dentry,
				   struct vfsmount *mnt);
static int __ccs_rmdir_permission(struct dentry *dentry, struct vfsmount *mnt);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 8, 0)
static int __ccs_search_binary_handler(struct linux_binprm *bprm);
#else
static int __ccs_search_binary_handler(struct linux_binprm *bprm,
				       struct pt_regs *regs);
#endif
static int __ccs_symlink_permission(struct dentry *dentry,
				    struct vfsmount *mnt, const char *from);
static int __ccs_truncate_permission(struct dentry *dentry,
				     struct vfsmount *mnt);
static int __ccs_umount_permission(struct vfsmount *mnt, int flags);
static int __ccs_unlink_permission(struct dentry *dentry,
				   struct vfsmount *mnt);
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 30)
static int __ccs_uselib_permission(struct dentry *dentry,
				   struct vfsmount *mnt);
#endif
static int ccs_execute_permission(struct ccs_request_info *r,
				  const struct ccs_path_info *filename);
static int ccs_find_next_domain(struct ccs_execve *ee);
static int ccs_get_path(const char *pathname, struct path *path);
static int ccs_kern_path(const char *pathname, int flags, struct path *path);
static int ccs_mkdev_perm(const u8 operation, struct dentry *dentry,
			  struct vfsmount *mnt, const unsigned int mode,
			  unsigned int dev);
static int ccs_mount_acl(struct ccs_request_info *r, const char *dev_name,
			 struct path *dir, const char *type,
			 unsigned long flags);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 33)
static int ccs_new_open_permission(struct file *filp);
#endif
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 24)
static int ccs_old_chroot_permission(struct nameidata *nd);
static int ccs_old_mount_permission(const char *dev_name, struct nameidata *nd,
				    const char *type, unsigned long flags,
				    void *data_page);
static int ccs_old_pivot_root_permission(struct nameidata *old_nd,
					 struct nameidata *new_nd);
#endif
static int ccs_path2_perm(const u8 operation, struct dentry *dentry1,
			  struct vfsmount *mnt1, struct dentry *dentry2,
			  struct vfsmount *mnt2);
static int ccs_path_number_perm(const u8 type, struct dentry *dentry,
				struct vfsmount *vfsmnt, unsigned long number);
static int ccs_path_perm(const u8 operation, struct dentry *dentry,
			 struct vfsmount *mnt, const char *target);
static int ccs_path_permission(struct ccs_request_info *r, u8 operation,
			       const struct ccs_path_info *filename);
static int ccs_start_execve(struct linux_binprm *bprm,
			    struct ccs_execve **eep);
static int ccs_symlink_path(const char *pathname, struct ccs_path_info *name);
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 32)
static void __ccs_clear_open_mode(void);
static void __ccs_save_open_mode(int mode);
#endif
static void ccs_add_slash(struct ccs_path_info *buf);
static void ccs_finish_execve(int retval, struct ccs_execve *ee);

#ifdef CONFIG_CCSECURITY_MISC
static bool ccs_check_env_acl(struct ccs_request_info *r,
			      const struct ccs_acl_info *ptr);
static int ccs_env_perm(struct ccs_request_info *r, const char *env);
static int ccs_environ(struct ccs_execve *ee);
#endif

#ifdef CONFIG_CCSECURITY_CAPABILITY
static bool __ccs_capable(const u8 operation);
static bool ccs_check_capability_acl(struct ccs_request_info *r,
				     const struct ccs_acl_info *ptr);
static bool ccs_kernel_service(void);
static int __ccs_ptrace_permission(long request, long pid);
static int __ccs_socket_create_permission(int family, int type, int protocol);
#endif

#ifdef CONFIG_CCSECURITY_NETWORK
static bool ccs_address_matches_group(const bool is_ipv6, const u32 *address,
				      const struct ccs_group *group);
static bool ccs_check_inet_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr);
static bool ccs_check_unix_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr);
static bool ccs_kernel_service(void);
static int __ccs_socket_bind_permission(struct socket *sock,
					struct sockaddr *addr, int addr_len);
static int __ccs_socket_connect_permission(struct socket *sock,
					   struct sockaddr *addr,
					   int addr_len);
static int __ccs_socket_listen_permission(struct socket *sock);
static int __ccs_socket_post_accept_permission(struct socket *sock,
					       struct socket *newsock);
static int __ccs_socket_sendmsg_permission(struct socket *sock,
					   struct msghdr *msg, int size);
static int ccs_check_inet_address(const struct sockaddr *addr,
				  const unsigned int addr_len, const u16 port,
				  struct ccs_addr_info *address);
static int ccs_check_unix_address(struct sockaddr *addr,
				  const unsigned int addr_len,
				  struct ccs_addr_info *address);
static int ccs_inet_entry(const struct ccs_addr_info *address);
static int ccs_unix_entry(const struct ccs_addr_info *address);
static u8 ccs_sock_family(struct sock *sk);
#endif

#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG
static int __ccs_socket_post_recvmsg_permission(struct sock *sk,
						struct sk_buff *skb,
						int flags);
#endif

#ifdef CONFIG_CCSECURITY_IPC
static bool ccs_check_signal_acl(struct ccs_request_info *r,
				 const struct ccs_acl_info *ptr);
static int ccs_signal_acl(const int pid, const int sig);
static int ccs_signal_acl0(pid_t tgid, pid_t pid, int sig);
static int ccs_signal_acl2(const int sig, const int pid);
#endif

#ifdef CONFIG_CCSECURITY_FILE_GETATTR
static int __ccs_getattr_permission(struct vfsmount *mnt,
				    struct dentry *dentry);
#endif

#ifdef CONFIG_CCSECURITY_TASK_EXECUTE_HANDLER
static bool ccs_find_execute_handler(struct ccs_execve *ee, const u8 type);
static int ccs_try_alt_exec(struct ccs_execve *ee);
static void ccs_unescape(unsigned char *dest);
#endif

#ifdef CONFIG_CCSECURITY_TASK_DOMAIN_TRANSITION
static bool ccs_check_task_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr);
#endif

/*                                                */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 36)

/* 
                                                     
  
                         
                                           
  
                                                 
 */
static inline int ccs_copy_argv(const char *arg, struct linux_binprm *bprm)
{
	const int ret = copy_strings_kernel(1, &arg, bprm);
	if (ret >= 0)
		bprm->argc++;
	return ret;
}

#else

/* 
                                                     
  
                         
                                           
  
                                                 
 */
static inline int ccs_copy_argv(char *arg, struct linux_binprm *bprm)
{
	const int ret = copy_strings_kernel(1, &arg, bprm);
	if (ret >= 0)
		bprm->argc++;
	return ret;
}

#endif

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 35)

/* 
                                                 
  
                                        
                                   
  
                   
  
                                                
 */
static inline void get_fs_root(struct fs_struct *fs, struct path *root)
{
	read_lock(&fs->lock);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 25)
	*root = fs->root;
	path_get(root);
#else
	root->dentry = dget(fs->root);
	root->mnt = mntget(fs->rootmnt);
#endif
	read_unlock(&fs->lock);
}

#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 5, 0)

/* 
                                          
  
                                                   
  
                   
  
                                                
 */
static inline void module_put(struct module *module)
{
	if (module)
		__MOD_DEC_USE_COUNT(module);
}

#endif

/* 
                                                     
  
                                                 
  
                   
  
                                                                         
 */
static inline void ccs_put_filesystem(struct file_system_type *fstype)
{
	module_put(fstype->owner);
}

#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 22)
#if !defined(RHEL_MAJOR) || RHEL_MAJOR != 5
#if !defined(AX_MAJOR) || AX_MAJOR != 3

/* 
                               
  
                                     
  
                                     
  
                                                
 */
static inline struct iphdr *ip_hdr(const struct sk_buff *skb)
{
	return skb->nh.iph;
}

/* 
                                 
  
                                     
  
                                      
  
                                                
 */
static inline struct udphdr *udp_hdr(const struct sk_buff *skb)
{
	return skb->h.uh;
}

/* 
                                   
  
                                     
  
                                       
  
                                                
 */
static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb)
{
	return skb->nh.ipv6h;
}

#endif
#endif
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 5, 0)

/* 
                                                
  
                                    
                                       
                                               
  
                   
 */
static inline void skb_kill_datagram(struct sock *sk, struct sk_buff *skb,
				     int flags)
{
	/*              */
	if (flags & MSG_PEEK) {
		int clear = 0;
		spin_lock_irq(&sk->receive_queue.lock);
		if (skb == skb_peek(&sk->receive_queue)) {
			__skb_unlink(skb, &sk->receive_queue);
			clear = 1;
		}
		spin_unlock_irq(&sk->receive_queue.lock);
		if (clear)
			kfree_skb(skb);
	}
	skb_free_datagram(sk, skb);
}

#elif LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 16)

/* 
                                                
  
                                    
                                       
                                               
  
                   
 */
static inline void skb_kill_datagram(struct sock *sk, struct sk_buff *skb,
				     int flags)
{
	/*              */
	if (flags & MSG_PEEK) {
		int clear = 0;
		spin_lock_bh(&sk->sk_receive_queue.lock);
		if (skb == skb_peek(&sk->sk_receive_queue)) {
			__skb_unlink(skb, &sk->sk_receive_queue);
			clear = 1;
		}
		spin_unlock_bh(&sk->sk_receive_queue.lock);
		if (clear)
			kfree_skb(skb);
	}
	skb_free_datagram(sk, skb);
}

#endif

#endif

/*                                                */

/*                     */
struct ccs_domain_info ccs_kernel_domain;

/*                                        */
LIST_HEAD(ccs_domain_list);

/*                                               */

/* 
                                                                                                         
  
                                   
                                                 
  
                                                                              
                  
  
                                
 */
static const struct ccs_path_info *ccs_path_matches_group
(const struct ccs_path_info *pathname, const struct ccs_group *group)
{
	struct ccs_path_group *member;
	list_for_each_entry_srcu(member, &group->member_list, head.list,
				 &ccs_ss) {
		if (member->head.is_deleted)
			continue;
		if (!ccs_path_matches_pattern(pathname, member->member_name))
			continue;
		return member->member_name;
	}
	return NULL;
}

/* 
                                                                                                       
  
                      
                      
                                                
  
                                                                            
  
                                
 */
static bool ccs_number_matches_group(const unsigned long min,
				     const unsigned long max,
				     const struct ccs_group *group)
{
	struct ccs_number_group *member;
	bool matched = false;
	list_for_each_entry_srcu(member, &group->member_list, head.list,
				 &ccs_ss) {
		if (member->head.is_deleted)
			continue;
		if (min > member->number.values[1] ||
		    max < member->number.values[0])
			continue;
		matched = true;
		break;
	}
	return matched;
}

/* 
                                         
  
                                              
                                          
  
                                          
  
                                
 */
static bool ccs_check_entry(struct ccs_request_info *r,
			    struct ccs_acl_info *ptr)
{
	if (ptr->is_deleted || ptr->type != r->param_type)
		return false;
	switch (r->param_type) {
	case CCS_TYPE_PATH_ACL:
		return ccs_check_path_acl(r, ptr);
	case CCS_TYPE_PATH2_ACL:
		return ccs_check_path2_acl(r, ptr);
	case CCS_TYPE_PATH_NUMBER_ACL:
		return ccs_check_path_number_acl(r, ptr);
	case CCS_TYPE_MKDEV_ACL:
		return ccs_check_mkdev_acl(r, ptr);
	case CCS_TYPE_MOUNT_ACL:
		return ccs_check_mount_acl(r, ptr);
#ifdef CONFIG_CCSECURITY_MISC
	case CCS_TYPE_ENV_ACL:
		return ccs_check_env_acl(r, ptr);
#endif
#ifdef CONFIG_CCSECURITY_CAPABILITY
	case CCS_TYPE_CAPABILITY_ACL:
		return ccs_check_capability_acl(r, ptr);
#endif
#ifdef CONFIG_CCSECURITY_NETWORK
	case CCS_TYPE_INET_ACL:
		return ccs_check_inet_acl(r, ptr);
	case CCS_TYPE_UNIX_ACL:
		return ccs_check_unix_acl(r, ptr);
#endif
#ifdef CONFIG_CCSECURITY_IPC
	case CCS_TYPE_SIGNAL_ACL:
		return ccs_check_signal_acl(r, ptr);
#endif
#ifdef CONFIG_CCSECURITY_TASK_DOMAIN_TRANSITION
	case CCS_TYPE_MANUAL_TASK_ACL:
		return ccs_check_task_acl(r, ptr);
#endif
	}
	return true;
}

/* 
                                       
  
                                            
  
                                                  
  
                                
 */
int ccs_check_acl(struct ccs_request_info *r)
{
	const struct ccs_domain_info *domain = ccs_current_domain();
	int error;
	bool retried = false;
	do {
		struct ccs_acl_info *ptr;
		const struct list_head *list = &domain->acl_info_list;
retry:
		list_for_each_entry_srcu(ptr, list, list, &ccs_ss) {
			if (!ccs_check_entry(r, ptr))
				continue;
			if (!ccs_condition(r, ptr->cond))
				continue;
			r->matched_acl = ptr;
			r->granted = true;
			ccs_audit_log(r);
			return 0;
		}
		if (!retried) {
			retried = true;
			list = &domain->ns->acl_group[domain->group];
			goto retry;
		}
		r->granted = false;
		if (r->mode != CCS_CONFIG_DISABLED ||
		    r->type != CCS_MAC_FILE_EXECUTE)
			error = ccs_audit_log(r);
		else
			error = 0;
	} while (error == CCS_RETRY_REQUEST &&
		 r->type != CCS_MAC_FILE_EXECUTE);
	return error;
}

/* 
                                                      
  
                              
  
                                  
 */
static const char *ccs_last_word(const char *name)
{
	const char *cp = strrchr(name, ' ');
	if (cp)
		return cp + 1;
	return name;
}

/* 
                                                                     
  
                                              
                                           
                                              
                                                  
                                                            
  
                                              
  
                                
 */
static bool ccs_scan_transition(const struct list_head *list,
				const struct ccs_path_info *domainname,
				const struct ccs_path_info *program,
				const char *last_name,
				const enum ccs_transition_type type)
{
	const struct ccs_transition_control *ptr;
	list_for_each_entry_srcu(ptr, list, head.list, &ccs_ss) {
		if (ptr->head.is_deleted || ptr->type != type)
			continue;
		if (ptr->domainname) {
			if (!ptr->is_last_name) {
				if (ptr->domainname != domainname)
					continue;
			} else {
				/*
                                        
                     
     */
				if (strcmp(ptr->domainname->name, last_name))
					continue;
			}
		}
		if (ptr->program && ccs_pathcmp(ptr->program, program))
			continue;
		return true;
	}
	return false;
}

/* 
                                                    
  
                                                         
                                           
                                              
  
                                                                             
                                                                               
                                                                  
                                                                           
                    
  
                                
 */
static enum ccs_transition_type ccs_transition_type
(const struct ccs_policy_namespace *ns, const struct ccs_path_info *domainname,
 const struct ccs_path_info *program)
{
	const char *last_name = ccs_last_word(domainname->name);
	enum ccs_transition_type type = CCS_TRANSITION_CONTROL_NO_RESET;
	while (type < CCS_MAX_TRANSITION_TYPE) {
		const struct list_head * const list =
			&ns->policy_list[CCS_ID_TRANSITION_CONTROL];
		if (!ccs_scan_transition(list, domainname, program, last_name,
					 type)) {
			type++;
			continue;
		}
		if (type != CCS_TRANSITION_CONTROL_NO_RESET &&
		    type != CCS_TRANSITION_CONTROL_NO_INITIALIZE)
			break;
		/*
                                                              
                                                               
             
   */
		type++;
		type++;
	}
	return type;
}

/* 
                                        
  
                                       
  
                                                  
  
                                
 */
static int ccs_find_next_domain(struct ccs_execve *ee)
{
	struct ccs_request_info *r = &ee->r;
#ifdef CONFIG_CCSECURITY_TASK_EXECUTE_HANDLER
	const struct ccs_path_info *handler = ee->handler;
#endif
	struct ccs_domain_info *domain = NULL;
	struct ccs_domain_info * const old_domain = ccs_current_domain();
	struct linux_binprm *bprm = ee->bprm;
	struct ccs_security *task = ccs_current_security();
	const struct ccs_path_info *candidate;
	struct ccs_path_info exename;
	int retval;
	bool reject_on_transition_failure = false;

	/*                                    */
	retval = ccs_symlink_path(bprm->filename, &exename);
	if (retval < 0)
		return retval;

#ifdef CONFIG_CCSECURITY_TASK_EXECUTE_HANDLER
	if (handler) {
		/*                                          */
		candidate = &exename;
		if (ccs_pathcmp(candidate, handler)) {
			/*                                   */
			static u8 counter = 20;
			if (counter) {
				counter--;
				printk(KERN_WARNING "Failed to verify: %s\n",
				       handler->name);
			}
			goto out;
		}
	} else
#endif
	{
		struct ccs_aggregator *ptr;
		struct list_head *list;
retry:
		/*                               */
		candidate = &exename;
		list = &old_domain->ns->policy_list[CCS_ID_AGGREGATOR];
		list_for_each_entry_srcu(ptr, list, head.list, &ccs_ss) {
			if (ptr->head.is_deleted ||
			    !ccs_path_matches_pattern(candidate,
						      ptr->original_name))
				continue;
			candidate = ptr->aggregated_name;
			break;
		}

		/*                           */
		retval = ccs_execute_permission(r, candidate);
		if (retval == CCS_RETRY_REQUEST)
			goto retry;
		if (retval < 0)
			goto out;
		/*
                                                              
                                                        
                                                          
                                     
   */
		if (r->param.path.matched_path)
			candidate = r->param.path.matched_path;
	}
	/*
                                                                     
                                                                      
                                                                    
                               
  */
	if (r->ee->transition) {
		const char *domainname = r->ee->transition->name;
		reject_on_transition_failure = true;
		if (!strcmp(domainname, "keep"))
			goto force_keep_domain;
		if (!strcmp(domainname, "child"))
			goto force_child_domain;
		if (!strcmp(domainname, "reset"))
			goto force_reset_domain;
		if (!strcmp(domainname, "initialize"))
			goto force_initialize_domain;
		if (!strcmp(domainname, "parent")) {
			char *cp;
			strncpy(ee->tmp, old_domain->domainname->name,
				CCS_EXEC_TMPSIZE - 1);
			cp = strrchr(ee->tmp, ' ');
			if (cp)
				*cp = '\0';
		} else if (*domainname == '<')
			strncpy(ee->tmp, domainname, CCS_EXEC_TMPSIZE - 1);
		else
			snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "%s %s",
				 old_domain->domainname->name, domainname);
		goto force_jump_domain;
	}
	/*
                                              
                                   
  */
	switch (ccs_transition_type(old_domain->ns, old_domain->domainname,
				    candidate)) {
	case CCS_TRANSITION_CONTROL_RESET:
force_reset_domain:
		/*                                             */
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "<%s>",
			 candidate->name);
		/*
                                                                 
                
   */
		reject_on_transition_failure = true;
		break;
	case CCS_TRANSITION_CONTROL_INITIALIZE:
force_initialize_domain:
		/*                                                   */
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "%s %s",
			 old_domain->ns->name, candidate->name);
		break;
	case CCS_TRANSITION_CONTROL_KEEP:
force_keep_domain:
		/*                      */
		domain = old_domain;
		break;
	default:
		if (old_domain == &ccs_kernel_domain && !ccs_policy_loaded) {
			/*
                                                  
                                                         
                                                        
                        
    */
			domain = old_domain;
			break;
		}
force_child_domain:
		/*                           */
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "%s %s",
			 old_domain->domainname->name, candidate->name);
		break;
	}
force_jump_domain:
	/*
                                    
                                                    
  */
	task->ccs_flags |= CCS_TASK_IS_IN_EXECVE;
	/*
                                                      
                          
  */
	smp_wmb();
	/*
                                                                  
                                                                  
                                                                      
                   
  */
	if (!domain)
		domain = ccs_assign_domain(ee->tmp, true);
	if (domain)
		retval = 0;
	else if (reject_on_transition_failure) {
		printk(KERN_WARNING
		       "ERROR: Domain '%s' not ready.\n", ee->tmp);
		retval = -ENOMEM;
	} else if (r->mode == CCS_CONFIG_ENFORCING)
		retval = -ENOMEM;
	else {
		retval = 0;
		if (!old_domain->flags[CCS_DIF_TRANSITION_FAILED]) {
			old_domain->flags[CCS_DIF_TRANSITION_FAILED] = true;
			r->granted = false;
			ccs_write_log(r, "%s",
				      ccs_dif[CCS_DIF_TRANSITION_FAILED]);
			printk(KERN_WARNING
			       "ERROR: Domain '%s' not defined.\n", ee->tmp);
		}
	}
out:
	kfree(exename.name);
	return retval;
}

#ifdef CONFIG_CCSECURITY_TASK_EXECUTE_HANDLER

/* 
                                          
  
                             
  
                   
 */
static void ccs_unescape(unsigned char *dest)
{
	unsigned char *src = dest;
	unsigned char c;
	unsigned char d;
	unsigned char e;
	while (1) {
		c = *src++;
		if (!c)
			break;
		if (c != '\\') {
			*dest++ = c;
			continue;
		}
		c = *src++;
		if (c == '\\') {
			*dest++ = c;
			continue;
		}
		if (c < '0' || c > '3')
			break;
		d = *src++;
		if (d < '0' || d > '7')
			break;
		e = *src++;
		if (e < '0' || e > '7')
			break;
		*dest++ = ((c - '0') << 6) + ((d - '0') << 3) + (e - '0');
	}
	*dest = '\0';
}

/* 
                                                   
  
                                       
  
                                                  
 */
static int ccs_try_alt_exec(struct ccs_execve *ee)
{
	/*
                              
                                                          
                                                           
                                                         
   
                       
                                                      
                       
          
   
                          
                                                          
                          
                                               
                          
                                   
                          
                                                          
                          
                                
                          
                                                 
                          
                                                 
                          
                               
        
                                       
                                             
                                       
                                
        
                                                    
                                             
  */
	struct linux_binprm *bprm = ee->bprm;
	struct file *filp;
	int retval;
	const int original_argc = bprm->argc;
	const int original_envc = bprm->envc;

	/*                                       */
	ee->obj.path1.dentry = NULL;
	ee->obj.path1.mnt = NULL;
	ee->obj.validate_done = false;
	allow_write_access(bprm->file);
	fput(bprm->file);
	bprm->file = NULL;

	/*                             */
	ee->dump.page = NULL;

	/*                       */
	bprm->argc += bprm->envc;
	bprm->envc = 0;

	/*             */
	{
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "%d", original_envc);
		retval = ccs_copy_argv(ee->tmp, bprm);
		if (retval < 0)
			goto out;
	}

	/*             */
	{
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "%d", original_argc);
		retval = ccs_copy_argv(ee->tmp, bprm);
		if (retval < 0)
			goto out;
	}

	/*             */
	{
		retval = ccs_copy_argv(bprm->filename, bprm);
		if (retval < 0)
			goto out;
	}

	/*             */
	{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 5, 0)
		/*
                                                             
                                                             
                                                               
                                               
   */
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1,
			 "pid=%d uid=%d gid=%d euid=%d egid=%d suid=%d "
			 "sgid=%d fsuid=%d fsgid=%d", ccs_sys_getpid(),
			 __kuid_val(current_uid()), __kgid_val(current_gid()),
			 __kuid_val(current_euid()),
			 __kgid_val(current_egid()),
			 __kuid_val(current_suid()),
			 __kgid_val(current_sgid()),
			 __kuid_val(current_fsuid()),
			 __kgid_val(current_fsgid()));
#else
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1,
			 "pid=%d uid=%d gid=%d euid=%d egid=%d suid=%d "
			 "sgid=%d fsuid=%d fsgid=%d", ccs_sys_getpid(),
			 current_uid(), current_gid(), current_euid(),
			 current_egid(), current_suid(), current_sgid(),
			 current_fsuid(), current_fsgid());
#endif
		retval = ccs_copy_argv(ee->tmp, bprm);
		if (retval < 0)
			goto out;
	}

	/*             */
	{
		char *exe = (char *) ccs_get_exe();
		if (exe) {
			retval = ccs_copy_argv(exe, bprm);
			kfree(exe);
		} else {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 36)
			retval = ccs_copy_argv("<unknown>", bprm);
#else
			snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "<unknown>");
			retval = ccs_copy_argv(ee->tmp, bprm);
#endif
		}
		if (retval < 0)
			goto out;
	}

	/*             */
	{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 36)
		retval = ccs_copy_argv(ccs_current_domain()->domainname->name,
				       bprm);
#else
		snprintf(ee->tmp, CCS_EXEC_TMPSIZE - 1, "%s",
			 ccs_current_domain()->domainname->name);
		retval = ccs_copy_argv(ee->tmp, bprm);
#endif
		if (retval < 0)
			goto out;
	}

	/*             */
	{
		struct path root;
		char *cp;
		int root_len;
		int handler_len;
		get_fs_root(current->fs, &root);
		cp = ccs_realpath(&root);
		path_put(&root);
		if (!cp) {
			retval = -ENOMEM;
			goto out;
		}
		root_len = strlen(cp);
		retval = strncmp(ee->handler->name, cp, root_len);
		root_len--;
		kfree(cp);
		if (retval) {
			retval = -ENOENT;
			goto out;
		}
		handler_len = ee->handler->total_len + 1;
		cp = kmalloc(handler_len, CCS_GFP_FLAGS);
		if (!cp) {
			retval = -ENOMEM;
			goto out;
		}
		/*                                                      */
		ee->handler_path = cp;
		/*                                        */
		memmove(cp, ee->handler->name + root_len,
			handler_len - root_len);
		ccs_unescape(cp);
		retval = -ENOENT;
		if (*cp != '/')
			goto out;
		retval = ccs_copy_argv(cp, bprm);
		if (retval < 0)
			goto out;
	}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 23)
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 24)
	bprm->argv_len = bprm->exec - bprm->p;
#endif
#endif

	/*
                                                                      
  */
	filp = open_exec(ee->handler_path);
	if (IS_ERR(filp)) {
		retval = PTR_ERR(filp);
		goto out;
	}
	ee->obj.path1.dentry = filp->f_dentry;
	ee->obj.path1.mnt = filp->f_vfsmnt;
	bprm->file = filp;
	bprm->filename = ee->handler_path;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 5, 0)
	bprm->interp = bprm->filename;
#endif
	retval = prepare_binprm(bprm);
	if (retval < 0)
		goto out;
	ee->r.dont_sleep_on_enforce_error = true;
	retval = ccs_find_next_domain(ee);
	ee->r.dont_sleep_on_enforce_error = false;
out:
	return retval;
}

/* 
                                                      
  
                                         
                                  
  
                                          
  
                                
 */
static bool ccs_find_execute_handler(struct ccs_execve *ee, const u8 type)
{
	struct ccs_request_info *r = &ee->r;
	/*
                                                                     
                                                        
  */
	if (ccs_current_flags() & CCS_TASK_IS_EXECUTE_HANDLER)
		return false;
	r->param_type = type;
	ccs_check_acl(r);
	if (!r->granted)
		return false;
	ee->handler = container_of(r->matched_acl, struct ccs_handler_acl,
				   head)->handler;
	ee->transition = r->matched_acl && r->matched_acl->cond &&
		r->matched_acl->cond->exec_transit ?
		r->matched_acl->cond->transit : NULL;
	return true;
}

#endif

#ifdef CONFIG_MMU
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 23)
#define CCS_BPRM_MMU
#elif defined(RHEL_MAJOR) && RHEL_MAJOR == 5 && defined(RHEL_MINOR) && RHEL_MINOR >= 3
#define CCS_BPRM_MMU
#elif defined(AX_MAJOR) && AX_MAJOR == 3 && defined(AX_MINOR) && AX_MINOR >= 2
#define CCS_BPRM_MMU
#endif
#endif

/* 
                                         
  
                                           
                           
                                           
  
                                            
 */
bool ccs_dump_page(struct linux_binprm *bprm, unsigned long pos,
		   struct ccs_page_dump *dump)
{
	struct page *page;
	/*                                               */
	if (!dump->data) {
		dump->data = kzalloc(PAGE_SIZE, CCS_GFP_FLAGS);
		if (!dump->data)
			return false;
	}
	/*                                                   */
#ifdef CCS_BPRM_MMU
	if (get_user_pages(current, bprm->mm, pos, 1, 0, 1, &page, NULL) <= 0)
		return false;
#else
	page = bprm->page[pos / PAGE_SIZE];
#endif
	if (page != dump->page) {
		const unsigned int offset = pos % PAGE_SIZE;
		/*
                                               
                                                              
             
   */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)
		char *kaddr = kmap_atomic(page);
#else
		char *kaddr = kmap_atomic(page, KM_USER0);
#endif
		dump->page = page;
		memcpy(dump->data + offset, kaddr + offset,
		       PAGE_SIZE - offset);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)
		kunmap_atomic(kaddr);
#else
		kunmap_atomic(kaddr, KM_USER0);
#endif
	}
	/*                                           */
#ifdef CCS_BPRM_MMU
	put_page(page);
#endif
	return true;
}

/* 
                                                     
  
                                           
                                           
  
                                                  
 */
static int ccs_start_execve(struct linux_binprm *bprm,
			    struct ccs_execve **eep)
{
	int retval;
	struct ccs_security *task = ccs_current_security();
	struct ccs_execve *ee;
	int idx;
	*eep = NULL;
	ee = kzalloc(sizeof(*ee), CCS_GFP_FLAGS);
	if (!ee)
		return -ENOMEM;
	ee->tmp = kzalloc(CCS_EXEC_TMPSIZE, CCS_GFP_FLAGS);
	if (!ee->tmp) {
		kfree(ee);
		return -ENOMEM;
	}
	idx = ccs_read_lock();
	/*                                                 */
	ee->previous_domain = task->ccs_domain_info;
	/*                     */
	task->ccs_flags &= ~CCS_TASK_IS_MANAGER;
	*eep = ee;
	ccs_init_request_info(&ee->r, CCS_MAC_FILE_EXECUTE);
	ee->r.ee = ee;
	ee->bprm = bprm;
	ee->r.obj = &ee->obj;
	ee->obj.path1.dentry = bprm->file->f_dentry;
	ee->obj.path1.mnt = bprm->file->f_vfsmnt;
#ifdef CONFIG_CCSECURITY_TASK_EXECUTE_HANDLER
	/*
                                                                       
                    
  */
	if (ccs_find_execute_handler(ee, CCS_TYPE_AUTO_EXECUTE_HANDLER)) {
		retval = ccs_try_alt_exec(ee);
		goto done;
	}
#endif
	retval = ccs_find_next_domain(ee);
#ifdef CONFIG_CCSECURITY_TASK_EXECUTE_HANDLER
	if (retval == -EPERM &&
	    ccs_find_execute_handler(ee, CCS_TYPE_DENIED_EXECUTE_HANDLER)) {
		retval = ccs_try_alt_exec(ee);
		goto done;
	}
#endif
#ifdef CONFIG_CCSECURITY_MISC
	if (!retval)
		retval = ccs_environ(ee);
#endif
#ifdef CONFIG_CCSECURITY_TASK_EXECUTE_HANDLER
done:
#endif
	ccs_read_unlock(idx);
	kfree(ee->tmp);
	ee->tmp = NULL;
	kfree(ee->dump.data);
	ee->dump.data = NULL;
	return retval;
}

/* 
                                                   
  
                                                 
                                           
  
                   
 */
static void ccs_finish_execve(int retval, struct ccs_execve *ee)
{
	struct ccs_security *task = ccs_current_security();
	if (!ee)
		return;
	if (retval < 0) {
		task->ccs_domain_info = ee->previous_domain;
		/*
                                                             
                     
   */
		smp_wmb();
	} else {
		/*                                              */
		if (ee->handler)
			task->ccs_flags |= CCS_TASK_IS_EXECUTE_HANDLER;
		/*                                             */
		else
			task->ccs_flags &= ~CCS_TASK_IS_EXECUTE_HANDLER;
	}
	/*                                   */
	task->ccs_flags &= ~CCS_TASK_IS_IN_EXECVE;
	kfree(ee->handler_path);
	kfree(ee);
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 8, 0)

/* 
                                                              
  
                                           
  
                                                  
  
                                                                    
                                                                  
                                                                             
                         
                                                                  
                                                                               
                                   
 */
static int __ccs_search_binary_handler(struct linux_binprm *bprm)
{
	struct ccs_execve *ee;
	int retval;
#ifndef CONFIG_CCSECURITY_OMIT_USERSPACE_LOADER
	if (!ccs_policy_loaded)
		ccsecurity_exports.load_policy(bprm->filename);
#endif
	retval = ccs_start_execve(bprm, &ee);
	if (!retval)
		retval = search_binary_handler(bprm);
	ccs_finish_execve(retval, ee);
	return retval;
}

#else

/* 
                                                              
  
                                           
                                      
  
                                                  
  
                                                                    
                                                                  
                                                                             
                         
                                                                  
                                                                               
                                   
 */
static int __ccs_search_binary_handler(struct linux_binprm *bprm,
				       struct pt_regs *regs)
{
	struct ccs_execve *ee;
	int retval;
#ifndef CONFIG_CCSECURITY_OMIT_USERSPACE_LOADER
	if (!ccs_policy_loaded)
		ccsecurity_exports.load_policy(bprm->filename);
#endif
	retval = ccs_start_execve(bprm, &ee);
	if (!retval)
		retval = search_binary_handler(bprm, regs);
	ccs_finish_execve(retval, ee);
	return retval;
}

#endif

/* 
                                                         
  
                   
 */
void __init ccs_permission_init(void)
{
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 32)
	ccsecurity_ops.save_open_mode = __ccs_save_open_mode;
	ccsecurity_ops.clear_open_mode = __ccs_clear_open_mode;
	ccsecurity_ops.open_permission = __ccs_open_permission;
#else
	ccsecurity_ops.open_permission = ccs_new_open_permission;
#endif
	ccsecurity_ops.fcntl_permission = __ccs_fcntl_permission;
	ccsecurity_ops.ioctl_permission = __ccs_ioctl_permission;
	ccsecurity_ops.chmod_permission = __ccs_chmod_permission;
	ccsecurity_ops.chown_permission = __ccs_chown_permission;
#ifdef CONFIG_CCSECURITY_FILE_GETATTR
	ccsecurity_ops.getattr_permission = __ccs_getattr_permission;
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 25)
	ccsecurity_ops.pivot_root_permission = __ccs_pivot_root_permission;
	ccsecurity_ops.chroot_permission = __ccs_chroot_permission;
#else
	ccsecurity_ops.pivot_root_permission = ccs_old_pivot_root_permission;
	ccsecurity_ops.chroot_permission = ccs_old_chroot_permission;
#endif
	ccsecurity_ops.umount_permission = __ccs_umount_permission;
	ccsecurity_ops.mknod_permission = __ccs_mknod_permission;
	ccsecurity_ops.mkdir_permission = __ccs_mkdir_permission;
	ccsecurity_ops.rmdir_permission = __ccs_rmdir_permission;
	ccsecurity_ops.unlink_permission = __ccs_unlink_permission;
	ccsecurity_ops.symlink_permission = __ccs_symlink_permission;
	ccsecurity_ops.truncate_permission = __ccs_truncate_permission;
	ccsecurity_ops.rename_permission = __ccs_rename_permission;
	ccsecurity_ops.link_permission = __ccs_link_permission;
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 30)
	ccsecurity_ops.open_exec_permission = __ccs_open_exec_permission;
	ccsecurity_ops.uselib_permission = __ccs_uselib_permission;
#endif
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 18) || (LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 33) && defined(CONFIG_SYSCTL_SYSCALL))
	ccsecurity_ops.parse_table = __ccs_parse_table;
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 25)
	ccsecurity_ops.mount_permission = __ccs_mount_permission;
#else
	ccsecurity_ops.mount_permission = ccs_old_mount_permission;
#endif
#ifdef CONFIG_CCSECURITY_CAPABILITY
	ccsecurity_ops.socket_create_permission =
		__ccs_socket_create_permission;
#endif
#ifdef CONFIG_CCSECURITY_NETWORK
	ccsecurity_ops.socket_listen_permission =
		__ccs_socket_listen_permission;
	ccsecurity_ops.socket_connect_permission =
		__ccs_socket_connect_permission;
	ccsecurity_ops.socket_bind_permission = __ccs_socket_bind_permission;
	ccsecurity_ops.socket_post_accept_permission =
		__ccs_socket_post_accept_permission;
	ccsecurity_ops.socket_sendmsg_permission =
		__ccs_socket_sendmsg_permission;
#endif
#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG
	ccsecurity_ops.socket_post_recvmsg_permission =
		__ccs_socket_post_recvmsg_permission;
#endif
#ifdef CONFIG_CCSECURITY_IPC
	ccsecurity_ops.kill_permission = ccs_signal_acl;
	ccsecurity_ops.tgkill_permission = ccs_signal_acl0;
	ccsecurity_ops.tkill_permission = ccs_signal_acl;
	ccsecurity_ops.sigqueue_permission = ccs_signal_acl;
	ccsecurity_ops.tgsigqueue_permission = ccs_signal_acl0;
#endif
#ifdef CONFIG_CCSECURITY_CAPABILITY
	ccsecurity_ops.capable = __ccs_capable;
	ccsecurity_ops.ptrace_permission = __ccs_ptrace_permission;
#endif
	ccsecurity_ops.search_binary_handler = __ccs_search_binary_handler;
}

/* 
                                           
  
                                              
                           
                                       
  
                                                  
 */
static int ccs_kern_path(const char *pathname, int flags, struct path *path)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 28)
	if (!pathname || kern_path(pathname, flags, path))
		return -ENOENT;
#else
	struct nameidata nd;
	if (!pathname || path_lookup(pathname, flags, &nd))
		return -ENOENT;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 25)
	*path = nd.path;
#else
	path->dentry = nd.dentry;
	path->mnt = nd.mnt;
#endif
#endif
	return 0;
}

/* 
                                                     
  
                                                
                                       
  
                                                  
 */
static int ccs_get_path(const char *pathname, struct path *path)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 5, 0)
	return ccs_kern_path(pathname, LOOKUP_FOLLOW, path);
#else
	return ccs_kern_path(pathname, LOOKUP_FOLLOW | LOOKUP_POSITIVE, path);
#endif
}

/* 
                                             
  
                                                
                                                
  
                                                  
  
                                                                        
                      
 */
static int ccs_symlink_path(const char *pathname, struct ccs_path_info *name)
{
	char *buf;
	struct path path;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 5, 0)
	if (ccs_kern_path(pathname, 0, &path))
		return -ENOENT;
#else
	if (ccs_kern_path(pathname, LOOKUP_POSITIVE, &path))
		return -ENOENT;
#endif
	buf = ccs_realpath(&path);
	path_put(&path);
	if (buf) {
		name->name = buf;
		ccs_fill_path_info(name);
		return 0;
	}
	return -ENOMEM;
}

/* 
                                                                              
  
                                              
                                          
  
                                            
 */
static bool ccs_check_mount_acl(struct ccs_request_info *r,
				const struct ccs_acl_info *ptr)
{
	const struct ccs_mount_acl *acl =
		container_of(ptr, typeof(*acl), head);
	return ccs_compare_number_union(r->param.mount.flags, &acl->flags) &&
		ccs_compare_name_union(r->param.mount.type, &acl->fs_type) &&
		ccs_compare_name_union(r->param.mount.dir, &acl->dir_name) &&
		(!r->param.mount.need_dev ||
		 ccs_compare_name_union(r->param.mount.dev, &acl->dev_name));
}

/* 
                                                          
  
                                                   
                                              
                                       
                                      
                            
  
                                                  
  
                                
 */
static int ccs_mount_acl(struct ccs_request_info *r, const char *dev_name,
			 struct path *dir, const char *type,
			 unsigned long flags)
{
	struct ccs_obj_info obj = { };
	struct file_system_type *fstype = NULL;
	const char *requested_type = NULL;
	const char *requested_dir_name = NULL;
	const char *requested_dev_name = NULL;
	struct ccs_path_info rtype;
	struct ccs_path_info rdev;
	struct ccs_path_info rdir;
	int need_dev = 0;
	int error = -ENOMEM;
	r->obj = &obj;

	/*             */
	requested_type = ccs_encode(type);
	if (!requested_type)
		goto out;
	rtype.name = requested_type;
	ccs_fill_path_info(&rtype);

	/*                  */
	obj.path2 = *dir;
	requested_dir_name = ccs_realpath(dir);
	if (!requested_dir_name) {
		error = -ENOMEM;
		goto out;
	}
	rdir.name = requested_dir_name;
	ccs_fill_path_info(&rdir);

	/*                  */
	if (type == ccs_mounts[CCS_MOUNT_REMOUNT]) {
		/*                      */
	} else if (type == ccs_mounts[CCS_MOUNT_MAKE_UNBINDABLE] ||
		   type == ccs_mounts[CCS_MOUNT_MAKE_PRIVATE] ||
		   type == ccs_mounts[CCS_MOUNT_MAKE_SLAVE] ||
		   type == ccs_mounts[CCS_MOUNT_MAKE_SHARED]) {
		/*                      */
	} else if (type == ccs_mounts[CCS_MOUNT_BIND] ||
		   type == ccs_mounts[CCS_MOUNT_MOVE]) {
		need_dev = -1; /*                         */
	} else {
		fstype = get_fs_type(type);
		if (!fstype) {
			error = -ENODEV;
			goto out;
		}
		if (fstype->fs_flags & FS_REQUIRES_DEV)
			/*                                  */
			need_dev = 1;
	}
	if (need_dev) {
		/*                                 */
		if (ccs_get_path(dev_name, &obj.path1)) {
			error = -ENOENT;
			goto out;
		}
		requested_dev_name = ccs_realpath(&obj.path1);
		if (!requested_dev_name) {
			error = -ENOENT;
			goto out;
		}
	} else {
		/*                                                */
		if (!dev_name)
			dev_name = "<NULL>";
		requested_dev_name = ccs_encode(dev_name);
		if (!requested_dev_name) {
			error = -ENOMEM;
			goto out;
		}
	}
	rdev.name = requested_dev_name;
	ccs_fill_path_info(&rdev);
	r->param_type = CCS_TYPE_MOUNT_ACL;
	r->param.mount.need_dev = need_dev;
	r->param.mount.dev = &rdev;
	r->param.mount.dir = &rdir;
	r->param.mount.type = &rtype;
	r->param.mount.flags = flags;
	error = ccs_check_acl(r);
out:
	kfree(requested_dev_name);
	kfree(requested_dir_name);
	if (fstype)
		ccs_put_filesystem(fstype);
	kfree(requested_type);
	/*                                           */
	if (obj.path1.dentry)
		path_put(&obj.path1);
	return error;
}

/* 
                                                                   
  
                                               
                                        
                                                   
                             
                                         
  
                                                  
 */
static int __ccs_mount_permission(const char *dev_name, struct path *path,
				  const char *type, unsigned long flags,
				  void *data_page)
{
	struct ccs_request_info r;
	int error = 0;
	int idx;
	if ((flags & MS_MGC_MSK) == MS_MGC_VAL)
		flags &= ~MS_MGC_MSK;
	if (flags & MS_REMOUNT) {
		type = ccs_mounts[CCS_MOUNT_REMOUNT];
		flags &= ~MS_REMOUNT;
	} else if (flags & MS_BIND) {
		type = ccs_mounts[CCS_MOUNT_BIND];
		flags &= ~MS_BIND;
	} else if (flags & MS_SHARED) {
		if (flags & (MS_PRIVATE | MS_SLAVE | MS_UNBINDABLE))
			return -EINVAL;
		type = ccs_mounts[CCS_MOUNT_MAKE_SHARED];
		flags &= ~MS_SHARED;
	} else if (flags & MS_PRIVATE) {
		if (flags & (MS_SHARED | MS_SLAVE | MS_UNBINDABLE))
			return -EINVAL;
		type = ccs_mounts[CCS_MOUNT_MAKE_PRIVATE];
		flags &= ~MS_PRIVATE;
	} else if (flags & MS_SLAVE) {
		if (flags & (MS_SHARED | MS_PRIVATE | MS_UNBINDABLE))
			return -EINVAL;
		type = ccs_mounts[CCS_MOUNT_MAKE_SLAVE];
		flags &= ~MS_SLAVE;
	} else if (flags & MS_UNBINDABLE) {
		if (flags & (MS_SHARED | MS_PRIVATE | MS_SLAVE))
			return -EINVAL;
		type = ccs_mounts[CCS_MOUNT_MAKE_UNBINDABLE];
		flags &= ~MS_UNBINDABLE;
	} else if (flags & MS_MOVE) {
		type = ccs_mounts[CCS_MOUNT_MOVE];
		flags &= ~MS_MOVE;
	}
	if (!type)
		type = "<NULL>";
	idx = ccs_read_lock();
	if (ccs_init_request_info(&r, CCS_MAC_FILE_MOUNT)
	    != CCS_CONFIG_DISABLED)
		error = ccs_mount_acl(&r, dev_name, path, type, flags);
	ccs_read_unlock(idx);
	return error;
}

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 24)

/* 
                                                                     
  
                                   
                                             
                                                   
                             
                                         
  
                                                  
 */
static int ccs_old_mount_permission(const char *dev_name, struct nameidata *nd,
				    const char *type, unsigned long flags,
				    void *data_page)
{
	struct path path = { nd->mnt, nd->dentry };
	return __ccs_mount_permission(dev_name, &path, type, flags, data_page);
}

#endif

/* 
                                                                                             
  
                           
                                                
  
                                                        
 */
static bool ccs_compare_number_union(const unsigned long value,
				     const struct ccs_number_union *ptr)
{
	if (ptr->group)
		return ccs_number_matches_group(value, value, ptr->group);
	return value >= ptr->values[0] && value <= ptr->values[1];
}

/* 
                                                                                        
  
                                            
                                             
  
                                                                        
 */
static const struct ccs_path_info *ccs_compare_name_union
(const struct ccs_path_info *name, const struct ccs_name_union *ptr)
{
	if (ptr->group)
		return ccs_path_matches_group(name, ptr->group);
	if (ccs_path_matches_pattern(name, ptr->filename))
		return ptr->filename;
	return NULL;
}

/* 
                                              
  
                                           
  
                   
  
                                                                        
                                  
 */
static void ccs_add_slash(struct ccs_path_info *buf)
{
	if (buf->is_dir)
		return;
	/*                                                                   */
	strcat((char *) buf->name, "/");
	ccs_fill_path_info(buf);
}

/* 
                                   
  
                                            
                                                           
  
                                            
 */
static bool ccs_get_realpath(struct ccs_path_info *buf, struct path *path)
{
	buf->name = ccs_realpath(path);
	if (buf->name) {
		ccs_fill_path_info(buf);
		return true;
	}
	return false;
}

/* 
                                                            
  
                                              
                                          
  
                                            
  
                                                                       
                                                                     
                                    
 */
static bool ccs_check_path_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr)
{
	const struct ccs_path_acl *acl = container_of(ptr, typeof(*acl), head);
	if (ptr->perm & (1 << r->param.path.operation)) {
		r->param.path.matched_path =
			ccs_compare_name_union(r->param.path.filename,
					       &acl->name);
		return r->param.path.matched_path != NULL;
	}
	return false;
}

/* 
                                                                          
  
                                              
                                          
  
                                            
 */
static bool ccs_check_path_number_acl(struct ccs_request_info *r,
				      const struct ccs_acl_info *ptr)
{
	const struct ccs_path_number_acl *acl =
		container_of(ptr, typeof(*acl), head);
	return (ptr->perm & (1 << r->param.path_number.operation)) &&
		ccs_compare_number_union(r->param.path_number.number,
					 &acl->number) &&
		ccs_compare_name_union(r->param.path_number.filename,
				       &acl->name);
}

/* 
                                                                  
  
                                              
                                          
  
                                            
 */
static bool ccs_check_path2_acl(struct ccs_request_info *r,
				const struct ccs_acl_info *ptr)
{
	const struct ccs_path2_acl *acl =
		container_of(ptr, typeof(*acl), head);
	return (ptr->perm & (1 << r->param.path2.operation)) &&
		ccs_compare_name_union(r->param.path2.filename1, &acl->name1)
		&& ccs_compare_name_union(r->param.path2.filename2,
					  &acl->name2);
}

/* 
                                                                                  
  
                                              
                                          
  
                                            
 */
static bool ccs_check_mkdev_acl(struct ccs_request_info *r,
				const struct ccs_acl_info *ptr)
{
	const struct ccs_mkdev_acl *acl =
		container_of(ptr, typeof(*acl), head);
	return (ptr->perm & (1 << r->param.mkdev.operation)) &&
		ccs_compare_number_union(r->param.mkdev.mode, &acl->mode) &&
		ccs_compare_number_union(r->param.mkdev.major, &acl->major) &&
		ccs_compare_number_union(r->param.mkdev.minor, &acl->minor) &&
		ccs_compare_name_union(r->param.mkdev.filename, &acl->name);
}

/* 
                                                             
  
                                                    
                                 
                                 
  
                                                  
  
                                
 */
static int ccs_path_permission(struct ccs_request_info *r, u8 operation,
			       const struct ccs_path_info *filename)
{
	r->type = ccs_p2mac[operation];
	r->mode = ccs_get_mode(r->profile, r->type);
	if (r->mode == CCS_CONFIG_DISABLED)
		return 0;
	r->param_type = CCS_TYPE_PATH_ACL;
	r->param.path.filename = filename;
	r->param.path.operation = operation;
	return ccs_check_acl(r);
}

/* 
                                                                   
  
                                                    
                                 
  
                                                                              
  
                                
 */
static int ccs_execute_permission(struct ccs_request_info *r,
				  const struct ccs_path_info *filename)
{
	int error;
	/*
                                                                    
                                                                 
               
  */
	r->type = CCS_MAC_FILE_EXECUTE;
	r->mode = ccs_get_mode(r->profile, r->type);
	r->param_type = CCS_TYPE_PATH_ACL;
	r->param.path.filename = filename;
	r->param.path.operation = CCS_TYPE_EXECUTE;
	error = ccs_check_acl(r);
	r->ee->transition = r->matched_acl && r->matched_acl->cond &&
		r->matched_acl->cond->exec_transit ?
		r->matched_acl->cond->transit : NULL;
	return error;
}

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 32)

/* 
                                                                       
  
                                     
  
                   
  
                                                                           
                                                                     
                                        
  
                                                                          
                                                                             
                                          
 */
static void __ccs_save_open_mode(int mode)
{
	if ((mode & 3) == 3)
		ccs_current_security()->ccs_flags |= CCS_OPEN_FOR_IOCTL_ONLY;
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 14)
	/*                                                    */
	else if (!(mode & 3) && (mode & O_TRUNC))
		ccs_current_security()->ccs_flags |=
			CCS_OPEN_FOR_READ_TRUNCATE;
#endif
}

/* 
                                                                      
  
                   
 */
static void __ccs_clear_open_mode(void)
{
	ccs_current_security()->ccs_flags &= ~(CCS_OPEN_FOR_IOCTL_ONLY |
					       CCS_OPEN_FOR_READ_TRUNCATE);
}

#endif

/* 
                                                                   
  
                                       
                                                     
                             
  
                                                  
 */
static int __ccs_open_permission(struct dentry *dentry, struct vfsmount *mnt,
				 const int flag)
{
	struct ccs_request_info r;
	struct ccs_obj_info obj = {
		.path1.dentry = dentry,
		.path1.mnt = mnt,
	};
	const u32 ccs_flags = ccs_current_flags();
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 33)
	const u8 acc_mode = (flag & 3) == 3 ? 0 : ACC_MODE(flag);
#else
	const u8 acc_mode = (ccs_flags & CCS_OPEN_FOR_IOCTL_ONLY) ? 0 :
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 14)
		(ccs_flags & CCS_OPEN_FOR_READ_TRUNCATE) ? 4 :
#endif
		ACC_MODE(flag);
#endif
	int error = 0;
	struct ccs_path_info buf;
	int idx;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 30)
	if (current->in_execve && !(ccs_flags & CCS_TASK_IS_IN_EXECVE))
		return 0;
#endif
#ifndef CONFIG_CCSECURITY_FILE_GETATTR
	if (dentry->d_inode && S_ISDIR(dentry->d_inode->i_mode))
		return 0;
#endif
	buf.name = NULL;
	r.mode = CCS_CONFIG_DISABLED;
	idx = ccs_read_lock();
	if (acc_mode && ccs_init_request_info(&r, CCS_MAC_FILE_OPEN)
	    != CCS_CONFIG_DISABLED) {
		if (!ccs_get_realpath(&buf, &obj.path1)) {
			error = -ENOMEM;
			goto out;
		}
		r.obj = &obj;
		if (acc_mode & MAY_READ)
			error = ccs_path_permission(&r, CCS_TYPE_READ, &buf);
		if (!error && (acc_mode & MAY_WRITE))
			error = ccs_path_permission(&r, (flag & O_APPEND) ?
						    CCS_TYPE_APPEND :
						    CCS_TYPE_WRITE, &buf);
	}
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 32)
	if (!error && (flag & O_TRUNC) &&
	    ccs_init_request_info(&r, CCS_MAC_FILE_TRUNCATE)
	    != CCS_CONFIG_DISABLED) {
		if (!buf.name && !ccs_get_realpath(&buf, &obj.path1)) {
			error = -ENOMEM;
			goto out;
		}
		r.obj = &obj;
		error = ccs_path_permission(&r, CCS_TYPE_TRUNCATE, &buf);
	}
#endif
out:
	kfree(buf.name);
	ccs_read_unlock(idx);
	if (r.mode != CCS_CONFIG_ENFORCING)
		error = 0;
	return error;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 33)

/* 
                                                                     
  
                                   
  
                                                  
 */
static int ccs_new_open_permission(struct file *filp)
{
	return __ccs_open_permission(filp->f_path.dentry, filp->f_path.mnt,
				     filp->f_flags);
}

#endif

/* 
                                                                                                                              
  
                                 
                                          
                                                        
                                                                  
                              
  
                                                  
 */
static int ccs_path_perm(const u8 operation, struct dentry *dentry,
			 struct vfsmount *mnt, const char *target)
{
	struct ccs_request_info r;
	struct ccs_obj_info obj = {
		.path1.dentry = dentry,
		.path1.mnt = mnt,
	};
	int error = 0;
	struct ccs_path_info buf;
	bool is_enforce = false;
	struct ccs_path_info symlink_target;
	int idx;
	buf.name = NULL;
	symlink_target.name = NULL;
	idx = ccs_read_lock();
	if (ccs_init_request_info(&r, ccs_p2mac[operation])
	    == CCS_CONFIG_DISABLED)
		goto out;
	is_enforce = (r.mode == CCS_CONFIG_ENFORCING);
	error = -ENOMEM;
	if (!ccs_get_realpath(&buf, &obj.path1))
		goto out;
	r.obj = &obj;
	switch (operation) {
	case CCS_TYPE_RMDIR:
	case CCS_TYPE_CHROOT:
		ccs_add_slash(&buf);
		break;
	case CCS_TYPE_SYMLINK:
		symlink_target.name = ccs_encode(target);
		if (!symlink_target.name)
			goto out;
		ccs_fill_path_info(&symlink_target);
		obj.symlink_target = &symlink_target;
		break;
	}
	error = ccs_path_permission(&r, operation, &buf);
	if (operation == CCS_TYPE_SYMLINK)
		kfree(symlink_target.name);
out:
	kfree(buf.name);
	ccs_read_unlock(idx);
	if (!is_enforce)
		error = 0;
	return error;
}

/* 
                                                                
  
                                                                       
                                          
                                                        
                           
                             
  
                                                  
 */
static int ccs_mkdev_perm(const u8 operation, struct dentry *dentry,
			  struct vfsmount *mnt, const unsigned int mode,
			  unsigned int dev)
{
	struct ccs_request_info r;
	struct ccs_obj_info obj = {
		.path1.dentry = dentry,
		.path1.mnt = mnt,
	};
	int error = 0;
	struct ccs_path_info buf;
	bool is_enforce = false;
	int idx;
	idx = ccs_read_lock();
	if (ccs_init_request_info(&r, ccs_pnnn2mac[operation])
	    == CCS_CONFIG_DISABLED)
		goto out;
	is_enforce = (r.mode == CCS_CONFIG_ENFORCING);
	error = -EPERM;
	if (!capable(CAP_MKNOD))
		goto out;
	error = -ENOMEM;
	if (!ccs_get_realpath(&buf, &obj.path1))
		goto out;
	r.obj = &obj;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 5, 0)
	dev = new_decode_dev(dev);
#endif
	r.param_type = CCS_TYPE_MKDEV_ACL;
	r.param.mkdev.filename = &buf;
	r.param.mkdev.operation = operation;
	r.param.mkdev.mode = mode;
	r.param.mkdev.major = MAJOR(dev);
	r.param.mkdev.minor = MINOR(dev);
	error = ccs_check_acl(&r);
	kfree(buf.name);
out:
	ccs_read_unlock(idx);
	if (!is_enforce)
		error = 0;
	return error;
}

/* 
                                                                           
  
                                 
                                          
                                                        
                                          
                                                        
  
                                                  
 */
static int ccs_path2_perm(const u8 operation, struct dentry *dentry1,
			  struct vfsmount *mnt1, struct dentry *dentry2,
			  struct vfsmount *mnt2)
{
	struct ccs_request_info r;
	int error = 0;
	struct ccs_path_info buf1;
	struct ccs_path_info buf2;
	bool is_enforce = false;
	struct ccs_obj_info obj = {
		.path1.dentry = dentry1,
		.path1.mnt = mnt1,
		.path2.dentry = dentry2,
		.path2.mnt = mnt2,
	};
	int idx;
	buf1.name = NULL;
	buf2.name = NULL;
	idx = ccs_read_lock();
	if (ccs_init_request_info(&r, ccs_pp2mac[operation])
	    == CCS_CONFIG_DISABLED)
		goto out;
	is_enforce = (r.mode == CCS_CONFIG_ENFORCING);
	error = -ENOMEM;
	if (!ccs_get_realpath(&buf1, &obj.path1) ||
	    !ccs_get_realpath(&buf2, &obj.path2))
		goto out;
	switch (operation) {
	case CCS_TYPE_RENAME:
	case CCS_TYPE_LINK:
		if (!dentry1->d_inode || !S_ISDIR(dentry1->d_inode->i_mode))
			break;
		/*              */
	case CCS_TYPE_PIVOT_ROOT:
		ccs_add_slash(&buf1);
		ccs_add_slash(&buf2);
		break;
	}
	r.obj = &obj;
	r.param_type = CCS_TYPE_PATH2_ACL;
	r.param.path2.operation = operation;
	r.param.path2.filename1 = &buf1;
	r.param.path2.filename2 = &buf2;
	error = ccs_check_acl(&r);
out:
	kfree(buf1.name);
	kfree(buf2.name);
	ccs_read_unlock(idx);
	if (!is_enforce)
		error = 0;
	return error;
}

/* 
                                                                                                                         
  
                              
                                       
                                                     
                   
  
                                                  
 */
static int ccs_path_number_perm(const u8 type, struct dentry *dentry,
				struct vfsmount *vfsmnt, unsigned long number)
{
	struct ccs_request_info r;
	struct ccs_obj_info obj = {
		.path1.dentry = dentry,
		.path1.mnt = vfsmnt,
	};
	int error = 0;
	struct ccs_path_info buf;
	int idx;
	if (!dentry)
		return 0;
	idx = ccs_read_lock();
	if (ccs_init_request_info(&r, ccs_pn2mac[type]) == CCS_CONFIG_DISABLED)
		goto out;
	error = -ENOMEM;
	if (!ccs_get_realpath(&buf, &obj.path1))
		goto out;
	r.obj = &obj;
	if (type == CCS_TYPE_MKDIR)
		ccs_add_slash(&buf);
	r.param_type = CCS_TYPE_PATH_NUMBER_ACL;
	r.param.path_number.operation = type;
	r.param.path_number.filename = &buf;
	r.param.path_number.number = number;
	error = ccs_check_acl(&r);
	kfree(buf.name);
out:
	ccs_read_unlock(idx);
	if (r.mode != CCS_CONFIG_ENFORCING)
		error = 0;
	return error;
}

/* 
                                                         
  
                                   
                               
                         
  
                                                  
 */
static int __ccs_ioctl_permission(struct file *filp, unsigned int cmd,
				  unsigned long arg)
{
	return ccs_path_number_perm(CCS_TYPE_IOCTL, filp->f_dentry,
				    filp->f_vfsmnt, cmd);
}

/* 
                                                         
  
                                       
                                                     
                 
  
                                                  
 */
static int __ccs_chmod_permission(struct dentry *dentry,
				  struct vfsmount *vfsmnt, mode_t mode)
{
	if (mode == (mode_t) -1)
		return 0;
	return ccs_path_number_perm(CCS_TYPE_CHMOD, dentry, vfsmnt,
				    mode & S_IALLUGO);
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 5, 0)

/* 
                                                               
  
                                       
                                                     
                    
                     
  
                                                  
 */
static int __ccs_chown_permission(struct dentry *dentry,
				  struct vfsmount *vfsmnt, kuid_t user,
				  kgid_t group)
{
	int error = 0;
	if (uid_valid(user))
		error = ccs_path_number_perm(CCS_TYPE_CHOWN, dentry, vfsmnt,
					     from_kuid(&init_user_ns, user));
	if (!error && gid_valid(group))
		error = ccs_path_number_perm(CCS_TYPE_CHGRP, dentry, vfsmnt,
					     from_kgid(&init_user_ns, group));
	return error;
}

#else

/* 
                                                               
  
                                       
                                                     
                    
                     
  
                                                  
 */
static int __ccs_chown_permission(struct dentry *dentry,
				  struct vfsmount *vfsmnt, uid_t user,
				  gid_t group)
{
	int error = 0;
	if (user == (uid_t) -1 && group == (gid_t) -1)
		return 0;
	if (user != (uid_t) -1)
		error = ccs_path_number_perm(CCS_TYPE_CHOWN, dentry, vfsmnt,
					     user);
	if (!error && group != (gid_t) -1)
		error = ccs_path_number_perm(CCS_TYPE_CHGRP, dentry, vfsmnt,
					     group);
	return error;
}

#endif

/* 
                                                                        
  
                                   
                         
                         
  
                                                  
 */
static int __ccs_fcntl_permission(struct file *file, unsigned int cmd,
				  unsigned long arg)
{
	if (!(cmd == F_SETFL && ((arg ^ file->f_flags) & O_APPEND)))
		return 0;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 33)
	return __ccs_open_permission(file->f_dentry, file->f_vfsmnt,
				     O_WRONLY | (arg & O_APPEND));
#elif defined(RHEL_MAJOR) && RHEL_MAJOR == 6
	return __ccs_open_permission(file->f_dentry, file->f_vfsmnt,
				     O_WRONLY | (arg & O_APPEND));
#else
	return __ccs_open_permission(file->f_dentry, file->f_vfsmnt,
				     (O_WRONLY + 1) | (arg & O_APPEND));
#endif
}

/* 
                                                                   
  
                                       
                                       
  
                                                  
 */
static int __ccs_pivot_root_permission(struct path *old_path,
				       struct path *new_path)
{
	return ccs_path2_perm(CCS_TYPE_PIVOT_ROOT, new_path->dentry,
			      new_path->mnt, old_path->dentry, old_path->mnt);
}

/* 
                                                           
  
                                   
  
                                                  
 */
static int __ccs_chroot_permission(struct path *path)
{
	return ccs_path_perm(CCS_TYPE_CHROOT, path->dentry, path->mnt, NULL);
}

/* 
                                                          
  
                                        
                  
  
                                                  
 */
static int __ccs_umount_permission(struct vfsmount *mnt, int flags)
{
	return ccs_path_perm(CCS_TYPE_UMOUNT, mnt->mnt_root, mnt, NULL);
}

/* 
                                                             
  
                                       
                                                     
                                       
                                                        
  
                                                  
 */
static int __ccs_mknod_permission(struct dentry *dentry, struct vfsmount *mnt,
				  const unsigned int mode, unsigned int dev)
{
	int error = 0;
	const unsigned int perm = mode & S_IALLUGO;
	switch (mode & S_IFMT) {
	case S_IFCHR:
		error = ccs_mkdev_perm(CCS_TYPE_MKCHAR, dentry, mnt, perm,
				       dev);
		break;
	case S_IFBLK:
		error = ccs_mkdev_perm(CCS_TYPE_MKBLOCK, dentry, mnt, perm,
				       dev);
		break;
	case S_IFIFO:
		error = ccs_path_number_perm(CCS_TYPE_MKFIFO, dentry, mnt,
					     perm);
		break;
	case S_IFSOCK:
		error = ccs_path_number_perm(CCS_TYPE_MKSOCK, dentry, mnt,
					     perm);
		break;
	case 0:
	case S_IFREG:
		error = ccs_path_number_perm(CCS_TYPE_CREATE, dentry, mnt,
					     perm);
		break;
	}
	return error;
}

/* 
                                                             
  
                                       
                                                     
                        
  
                                                  
 */
static int __ccs_mkdir_permission(struct dentry *dentry, struct vfsmount *mnt,
				  unsigned int mode)
{
	return ccs_path_number_perm(CCS_TYPE_MKDIR, dentry, mnt, mode);
}

/* 
                                                             
  
                                       
                                                     
  
                                                  
 */
static int __ccs_rmdir_permission(struct dentry *dentry, struct vfsmount *mnt)
{
	return ccs_path_perm(CCS_TYPE_RMDIR, dentry, mnt, NULL);
}

/* 
                                                               
  
                                       
                                                     
  
                                                  
 */
static int __ccs_unlink_permission(struct dentry *dentry, struct vfsmount *mnt)
{
	return ccs_path_perm(CCS_TYPE_UNLINK, dentry, mnt, NULL);
}

#ifdef CONFIG_CCSECURITY_FILE_GETATTR

/* 
                                                                 
  
                                                     
                                       
  
                                                  
 */
static int __ccs_getattr_permission(struct vfsmount *mnt,
				    struct dentry *dentry)
{
	return ccs_path_perm(CCS_TYPE_GETATTR, dentry, mnt, NULL);
}

#endif

/* 
                                                                 
  
                                       
                                                     
                               
  
                                                  
 */
static int __ccs_symlink_permission(struct dentry *dentry,
				    struct vfsmount *mnt, const char *from)
{
	return ccs_path_perm(CCS_TYPE_SYMLINK, dentry, mnt, from);
}

/* 
                                                                    
  
                                       
                                                     
  
                                                  
 */
static int __ccs_truncate_permission(struct dentry *dentry,
				     struct vfsmount *mnt)
{
	return ccs_path_perm(CCS_TYPE_TRUNCATE, dentry, mnt, NULL);
}

/* 
                                                               
  
                                           
                                           
                                                         
  
                                                  
 */
static int __ccs_rename_permission(struct dentry *old_dentry,
				   struct dentry *new_dentry,
				   struct vfsmount *mnt)
{
	return ccs_path2_perm(CCS_TYPE_RENAME, old_dentry, mnt, new_dentry,
			      mnt);
}

/* 
                                                           
  
                                           
                                           
                                                         
  
                                                  
 */
static int __ccs_link_permission(struct dentry *old_dentry,
				 struct dentry *new_dentry,
				 struct vfsmount *mnt)
{
	return ccs_path2_perm(CCS_TYPE_LINK, old_dentry, mnt, new_dentry, mnt);
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 30)

/* 
                                                                 
  
                                       
                                         
  
                                                  
 */
static int __ccs_open_exec_permission(struct dentry *dentry,
				      struct vfsmount *mnt)
{
	return (ccs_current_flags() & CCS_TASK_IS_IN_EXECVE) ?
		__ccs_open_permission(dentry, mnt, O_RDONLY + 1) : 0;
}

/* 
                                                               
  
                                       
                                         
  
                                                  
 */
static int __ccs_uselib_permission(struct dentry *dentry, struct vfsmount *mnt)
{
	return __ccs_open_permission(dentry, mnt, O_RDONLY + 1);
}

#endif

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 18) || (LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 33) && defined(CONFIG_SYSCTL_SYSCALL))

/* 
                                                          
  
                                    
                                        
                                     
                                     
                                          
  
                                                  
  
                                                                         
                                                                  
 */
static int __ccs_parse_table(int __user *name, int nlen, void __user *oldval,
			     void __user *newval, struct ctl_table *table)
{
	int n;
	int error = -ENOMEM;
	int op = 0;
	struct ccs_path_info buf;
	char *buffer = NULL;
	struct ccs_request_info r;
	int idx;
	if (oldval)
		op |= 004;
	if (newval)
		op |= 002;
	if (!op) /*                        */
		return 0;
	idx = ccs_read_lock();
	if (ccs_init_request_info(&r, CCS_MAC_FILE_OPEN)
	    == CCS_CONFIG_DISABLED) {
		error = 0;
		goto out;
	}
	buffer = kmalloc(PAGE_SIZE, CCS_GFP_FLAGS);
	if (!buffer)
		goto out;
	snprintf(buffer, PAGE_SIZE - 1, "proc:/sys");
repeat:
	if (!nlen) {
		error = -ENOTDIR;
		goto out;
	}
	if (get_user(n, name)) {
		error = -EFAULT;
		goto out;
	}
	for ( ; table->ctl_name
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 21)
		      || table->procname
#endif
		      ; table++) {
		int pos;
		const char *cp;
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 21)
		if (n != table->ctl_name && table->ctl_name != CTL_ANY)
			continue;
#else
		if (!n || n != table->ctl_name)
			continue;
#endif
		pos = strlen(buffer);
		cp = table->procname;
		error = -ENOMEM;
		if (cp) {
			int len = strlen(cp);
			if (len + 2 > PAGE_SIZE - 1)
				goto out;
			buffer[pos++] = '/';
			memmove(buffer + pos, cp, len + 1);
		} else {
			/*                                            */
			snprintf(buffer + pos, PAGE_SIZE - pos - 1,
				 "/=%d=", table->ctl_name);
			if (!memchr(buffer, '\0', PAGE_SIZE - 2))
				goto out;
		}
		if (!table->child)
			goto no_child;
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 21)
		if (!table->strategy)
			goto no_strategy;
		/*                                  */
		buf.name = ccs_encode(buffer);
		if (!buf.name)
			goto out;
		ccs_fill_path_info(&buf);
		if (op & MAY_READ)
			error = ccs_path_permission(&r, CCS_TYPE_READ, &buf);
		else
			error = 0;
		if (!error && (op & MAY_WRITE))
			error = ccs_path_permission(&r, CCS_TYPE_WRITE, &buf);
		kfree(buf.name);
		if (error)
			goto out;
no_strategy:
#endif
		name++;
		nlen--;
		table = table->child;
		goto repeat;
no_child:
		/*                                  */
		buf.name = ccs_encode(buffer);
		if (!buf.name)
			goto out;
		ccs_fill_path_info(&buf);
		if (op & MAY_READ)
			error = ccs_path_permission(&r, CCS_TYPE_READ, &buf);
		else
			error = 0;
		if (!error && (op & MAY_WRITE))
			error = ccs_path_permission(&r, CCS_TYPE_WRITE, &buf);
		kfree(buf.name);
		goto out;
	}
	error = -ENOTDIR;
out:
	ccs_read_unlock(idx);
	kfree(buffer);
	return error;
}

#endif

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 24)

/* 
                                                                     
  
                                          
                                          
  
                                                  
 */
static int ccs_old_pivot_root_permission(struct nameidata *old_nd,
					 struct nameidata *new_nd)
{
	struct path old_path = { old_nd->mnt, old_nd->dentry };
	struct path new_path = { new_nd->mnt, new_nd->dentry };
	return __ccs_pivot_root_permission(&old_path, &new_path);
}

/* 
                                                             
  
                                      
  
                                                  
 */
static int ccs_old_chroot_permission(struct nameidata *nd)
{
	struct path path = { nd->mnt, nd->dentry };
	return __ccs_chroot_permission(&path);
}

#endif

#ifdef CONFIG_CCSECURITY_NETWORK

/* 
                                                                                                          
  
                                                 
                                     
                                                   
  
                                                                               
  
                                
 */
static bool ccs_address_matches_group(const bool is_ipv6, const u32 *address,
				      const struct ccs_group *group)
{
	struct ccs_address_group *member;
	bool matched = false;
	const u8 size = is_ipv6 ? 16 : 4;
	list_for_each_entry_srcu(member, &group->member_list, head.list,
				 &ccs_ss) {
		if (member->head.is_deleted)
			continue;
		if (member->address.is_ipv6 != is_ipv6)
			continue;
		if (memcmp(&member->address.ip[0], address, size) > 0 ||
		    memcmp(address, &member->address.ip[1], size) > 0)
			continue;
		matched = true;
		break;
	}
	return matched;
}

/* 
                                                                          
  
                                              
                                          
  
                                            
 */
static bool ccs_check_inet_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr)
{
	const struct ccs_inet_acl *acl = container_of(ptr, typeof(*acl), head);
	const u8 size = r->param.inet_network.is_ipv6 ? 16 : 4;
	if (!(ptr->perm & (1 << r->param.inet_network.operation)) ||
	    !ccs_compare_number_union(r->param.inet_network.port, &acl->port))
		return false;
	if (acl->address.group)
		return ccs_address_matches_group(r->param.inet_network.is_ipv6,
						 r->param.inet_network.address,
						 acl->address.group);
	return acl->address.is_ipv6 == r->param.inet_network.is_ipv6 &&
		memcmp(&acl->address.ip[0],
		       r->param.inet_network.address, size) <= 0 &&
		memcmp(r->param.inet_network.address,
		       &acl->address.ip[1], size) <= 0;
}

/* 
                                                                          
  
                                              
                                          
  
                                            
 */
static bool ccs_check_unix_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr)
{
	const struct ccs_unix_acl *acl = container_of(ptr, typeof(*acl), head);
	return (ptr->perm & (1 << r->param.unix_network.operation)) &&
		ccs_compare_name_union(r->param.unix_network.address,
				       &acl->name);
}

/* 
                                                                
  
                                               
  
                                                  
 */
static int ccs_inet_entry(const struct ccs_addr_info *address)
{
	const int idx = ccs_read_lock();
	struct ccs_request_info r;
	int error = 0;
	const u8 type = ccs_inet2mac[address->protocol][address->operation];
	if (type && ccs_init_request_info(&r, type) != CCS_CONFIG_DISABLED) {
		r.param_type = CCS_TYPE_INET_ACL;
		r.param.inet_network.protocol = address->protocol;
		r.param.inet_network.operation = address->operation;
		r.param.inet_network.is_ipv6 = address->inet.is_ipv6;
		r.param.inet_network.address = address->inet.address;
		r.param.inet_network.port = ntohs(address->inet.port);
		r.dont_sleep_on_enforce_error =
			address->operation == CCS_NETWORK_ACCEPT
#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG
			|| address->operation == CCS_NETWORK_RECV
#endif
			;
		error = ccs_check_acl(&r);
	}
	ccs_read_unlock(idx);
	return error;
}

/* 
                                                                                
  
                                           
                            
                          
                                                
  
                                                  
 */
static int ccs_check_inet_address(const struct sockaddr *addr,
				  const unsigned int addr_len, const u16 port,
				  struct ccs_addr_info *address)
{
	struct ccs_inet_addr_info *i = &address->inet;
	switch (addr->sa_family) {
	case AF_INET6:
		if (addr_len < SIN6_LEN_RFC2133)
			goto skip;
		i->is_ipv6 = true;
		i->address = (u32 *)
			((struct sockaddr_in6 *) addr)->sin6_addr.s6_addr;
		i->port = ((struct sockaddr_in6 *) addr)->sin6_port;
		break;
	case AF_INET:
		if (addr_len < sizeof(struct sockaddr_in))
			goto skip;
		i->is_ipv6 = false;
		i->address = (u32 *) &((struct sockaddr_in *) addr)->sin_addr;
		i->port = ((struct sockaddr_in *) addr)->sin_port;
		break;
	default:
		goto skip;
	}
	if (address->protocol == SOCK_RAW)
		i->port = htons(port);
	return ccs_inet_entry(address);
skip:
	return 0;
}

/* 
                                                                
  
                                               
  
                                                  
 */
static int ccs_unix_entry(const struct ccs_addr_info *address)
{
	const int idx = ccs_read_lock();
	struct ccs_request_info r;
	int error = 0;
	const u8 type = ccs_unix2mac[address->protocol][address->operation];
	if (type && ccs_init_request_info(&r, type) != CCS_CONFIG_DISABLED) {
		char *buf = address->unix0.addr;
		int len = address->unix0.addr_len - sizeof(sa_family_t);
		if (len <= 0) {
			buf = "anonymous";
			len = 9;
		} else if (buf[0]) {
			len = strnlen(buf, len);
		}
		buf = ccs_encode2(buf, len);
		if (buf) {
			struct ccs_path_info addr;
			addr.name = buf;
			ccs_fill_path_info(&addr);
			r.param_type = CCS_TYPE_UNIX_ACL;
			r.param.unix_network.protocol = address->protocol;
			r.param.unix_network.operation = address->operation;
			r.param.unix_network.address = &addr;
			r.dont_sleep_on_enforce_error =
				address->operation == CCS_NETWORK_ACCEPT
#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG
				|| address->operation == CCS_NETWORK_RECV
#endif
				;
			error = ccs_check_acl(&r);
			kfree(buf);
		} else
			error = -ENOMEM;
	}
	ccs_read_unlock(idx);
	return error;
}

/* 
                                                                                
  
                                           
                            
                                                
  
                                                  
 */
static int ccs_check_unix_address(struct sockaddr *addr,
				  const unsigned int addr_len,
				  struct ccs_addr_info *address)
{
	struct ccs_unix_addr_info *u = &address->unix0;
	if (addr->sa_family != AF_UNIX)
		return 0;
	u->addr = ((struct sockaddr_un *) addr)->sun_path;
	u->addr_len = addr_len;
	return ccs_unix_entry(address);
}

/* 
                                         
  
                                 
  
                                                  
 */
static u8 ccs_sock_family(struct sock *sk)
{
	u8 family;
	if (ccs_kernel_service())
		return 0;
	family = sk->sk_family;
	switch (family) {
	case PF_INET:
	case PF_INET6:
	case PF_UNIX:
		return family;
	default:
		return 0;
	}
}

/* 
                                                                            
  
                                     
  
                                                  
 */
static int __ccs_socket_listen_permission(struct socket *sock)
{
	struct ccs_addr_info address;
	const u8 family = ccs_sock_family(sock->sk);
	const unsigned int type = sock->type;
	struct sockaddr_storage addr;
	int addr_len;
	if (!family || (type != SOCK_STREAM && type != SOCK_SEQPACKET))
		return 0;
	{
		const int error = sock->ops->getname(sock, (struct sockaddr *)
						     &addr, &addr_len, 0);
		if (error)
			return error;
	}
	address.protocol = type;
	address.operation = CCS_NETWORK_LISTEN;
	if (family == PF_UNIX)
		return ccs_check_unix_address((struct sockaddr *) &addr,
					      addr_len, &address);
	return ccs_check_inet_address((struct sockaddr *) &addr, addr_len, 0,
				      &address);
}

/* 
                                                                                                 
  
                                         
                                           
                            
  
                                                  
 */
static int __ccs_socket_connect_permission(struct socket *sock,
					   struct sockaddr *addr, int addr_len)
{
	struct ccs_addr_info address;
	const u8 family = ccs_sock_family(sock->sk);
	const unsigned int type = sock->type;
	if (!family)
		return 0;
	address.protocol = type;
	switch (type) {
	case SOCK_DGRAM:
	case SOCK_RAW:
		address.operation = CCS_NETWORK_SEND;
		break;
	case SOCK_STREAM:
	case SOCK_SEQPACKET:
		address.operation = CCS_NETWORK_CONNECT;
		break;
	default:
		return 0;
	}
	if (family == PF_UNIX)
		return ccs_check_unix_address(addr, addr_len, &address);
	return ccs_check_inet_address(addr, addr_len, sock->sk->sk_protocol,
				      &address);
}

/* 
                                                                                             
  
                                         
                                           
                            
  
                                                  
 */
static int __ccs_socket_bind_permission(struct socket *sock,
					struct sockaddr *addr, int addr_len)
{
	struct ccs_addr_info address;
	const u8 family = ccs_sock_family(sock->sk);
	const unsigned int type = sock->type;
	if (!family)
		return 0;
	switch (type) {
	case SOCK_STREAM:
	case SOCK_DGRAM:
	case SOCK_RAW:
	case SOCK_SEQPACKET:
		address.protocol = type;
		address.operation = CCS_NETWORK_BIND;
		break;
	default:
		return 0;
	}
	if (family == PF_UNIX)
		return ccs_check_unix_address(addr, addr_len, &address);
	return ccs_check_inet_address(addr, addr_len, sock->sk->sk_protocol,
				      &address);
}

/* 
                                                                             
  
                                     
                                     
                 
  
                                                  
 */
static int __ccs_socket_sendmsg_permission(struct socket *sock,
					   struct msghdr *msg, int size)
{
	struct ccs_addr_info address;
	const u8 family = ccs_sock_family(sock->sk);
	const unsigned int type = sock->type;
	if (!msg->msg_name || !family ||
	    (type != SOCK_DGRAM && type != SOCK_RAW))
		return 0;
	address.protocol = type;
	address.operation = CCS_NETWORK_SEND;
	if (family == PF_UNIX)
		return ccs_check_unix_address((struct sockaddr *)
					      msg->msg_name, msg->msg_namelen,
					      &address);
	return ccs_check_inet_address((struct sockaddr *) msg->msg_name,
				      msg->msg_namelen, sock->sk->sk_protocol,
				      &address);
}

/* 
                                                                                 
  
                                        
                                        
  
                                                  
 */
static int __ccs_socket_post_accept_permission(struct socket *sock,
					       struct socket *newsock)
{
	struct ccs_addr_info address;
	const u8 family = ccs_sock_family(sock->sk);
	const unsigned int type = sock->type;
	struct sockaddr_storage addr;
	int addr_len;
	if (!family || (type != SOCK_STREAM && type != SOCK_SEQPACKET))
		return 0;
	{
		const int error = newsock->ops->getname(newsock,
							(struct sockaddr *)
							&addr, &addr_len, 2);
		if (error)
			return error;
	}
	address.protocol = type;
	address.operation = CCS_NETWORK_ACCEPT;
	if (family == PF_UNIX)
		return ccs_check_unix_address((struct sockaddr *) &addr,
					      addr_len, &address);
	return ccs_check_inet_address((struct sockaddr *) &addr, addr_len, 0,
				      &address);
}

#ifdef CONFIG_CCSECURITY_NETWORK_RECVMSG

/* 
                                                                                    
  
                                    
                                       
                                               
  
                                                  
 */
static int __ccs_socket_post_recvmsg_permission(struct sock *sk,
						struct sk_buff *skb, int flags)
{
	struct ccs_addr_info address;
	const u8 family = ccs_sock_family(sk);
	const unsigned int type = sk->sk_type;
	struct sockaddr_storage addr;
	if (!family)
		return 0;
	switch (type) {
	case SOCK_DGRAM:
	case SOCK_RAW:
		address.protocol = type;
		break;
	default:
		return 0;
	}
	address.operation = CCS_NETWORK_RECV;
	switch (family) {
	case PF_INET6:
		{
			struct in6_addr *sin6 = (struct in6_addr *) &addr;
			address.inet.is_ipv6 = true;
			if (type == SOCK_DGRAM &&
			    skb->protocol == htons(ETH_P_IP))
				ipv6_addr_set(sin6, 0, 0, htonl(0xffff),
					      ip_hdr(skb)->saddr);
			else
				*sin6 = ipv6_hdr(skb)->saddr;
			break;
		}
	case PF_INET:
		{
			struct in_addr *sin4 = (struct in_addr *) &addr;
			address.inet.is_ipv6 = false;
			sin4->s_addr = ip_hdr(skb)->saddr;
			break;
		}
	default: /*            */
		{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 5, 0)
			struct unix_address *u = unix_sk(skb->sk)->addr;
#else
			struct unix_address *u =
				skb->sk->protinfo.af_unix.addr;
#endif
			unsigned int addr_len;
			if (u && u->len <= sizeof(addr)) {
				addr_len = u->len;
				memcpy(&addr, u->name, addr_len);
			} else {
				addr_len = 0;
				addr.ss_family = AF_UNIX;
			}
			if (ccs_check_unix_address((struct sockaddr *) &addr,
						   addr_len, &address))
				goto out;
			return 0;
		}
	}
	address.inet.address = (u32 *) &addr;
	if (type == SOCK_DGRAM)
		address.inet.port = udp_hdr(skb)->source;
	else
		address.inet.port = htons(sk->sk_protocol);
	if (ccs_inet_entry(&address))
		goto out;
	return 0;
out:
	/*
                                                 
                                                                   
                                                                      
                                                          
  */
	{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 35)
		bool slow = false;
		if (type == SOCK_DGRAM && family != PF_UNIX)
			slow = lock_sock_fast(sk);
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 25)
		if (type == SOCK_DGRAM && family != PF_UNIX)
			lock_sock(sk);
#elif defined(RHEL_MAJOR) && RHEL_MAJOR == 5 && defined(RHEL_MINOR) && RHEL_MINOR >= 2
		if (type == SOCK_DGRAM && family != PF_UNIX)
			lock_sock(sk);
#endif
		skb_kill_datagram(sk, skb, flags);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 35)
		if (type == SOCK_DGRAM && family != PF_UNIX)
			unlock_sock_fast(sk, slow);
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 25)
		if (type == SOCK_DGRAM && family != PF_UNIX)
			release_sock(sk);
#elif defined(RHEL_MAJOR) && RHEL_MAJOR == 5 && defined(RHEL_MINOR) && RHEL_MINOR >= 2
		if (type == SOCK_DGRAM && family != PF_UNIX)
			release_sock(sk);
#endif
	}
	return -EPERM;
}

#endif

#endif

#if defined(CONFIG_CCSECURITY_CAPABILITY) || defined(CONFIG_CCSECURITY_NETWORK)

/* 
                                                                
  
                                                       
 */
static bool ccs_kernel_service(void)
{
	/*                                         */
	return segment_eq(get_fs(), KERNEL_DS);
}

#endif

#ifdef CONFIG_CCSECURITY_CAPABILITY

/* 
                                                                        
  
                                              
                                          
  
                                            
 */
static bool ccs_check_capability_acl(struct ccs_request_info *r,
				     const struct ccs_acl_info *ptr)
{
	const struct ccs_capability_acl *acl =
		container_of(ptr, typeof(*acl), head);
	return acl->operation == r->param.capability.operation;
}

/* 
                                                 
  
                                 
  
                                            
 */
static bool __ccs_capable(const u8 operation)
{
	struct ccs_request_info r;
	int error = 0;
	const int idx = ccs_read_lock();
	if (ccs_init_request_info(&r, ccs_c2mac[operation])
	    != CCS_CONFIG_DISABLED) {
		r.param_type = CCS_TYPE_CAPABILITY_ACL;
		r.param.capability.operation = operation;
		error = ccs_check_acl(&r);
	}
	ccs_read_unlock(idx);
	return !error;
}

/* 
                                                                           
  
                              
                     
                     
  
                                                  
 */
static int __ccs_socket_create_permission(int family, int type, int protocol)
{
	if (ccs_kernel_service())
		return 0;
	if (family == PF_PACKET && !ccs_capable(CCS_USE_PACKET_SOCKET))
		return -EPERM;
	if (family == PF_ROUTE && !ccs_capable(CCS_USE_ROUTE_SOCKET))
		return -EPERM;
	return 0;
}

/* 
                                                           
  
                    
                    
  
                                                  
  
                                                                              
                                                                              
                                   
 */
static int __ccs_ptrace_permission(long request, long pid)
{
	return __ccs_capable(CCS_SYS_PTRACE) ? 0 : -EPERM;
}

#endif

#ifdef CONFIG_CCSECURITY_IPC

/* 
                                                                
  
                                              
                                          
  
                                            
 */
static bool ccs_check_signal_acl(struct ccs_request_info *r,
				 const struct ccs_acl_info *ptr)
{
	const struct ccs_signal_acl *acl =
		container_of(ptr, typeof(*acl), head);
	if (ccs_compare_number_union(r->param.signal.sig, &acl->sig)) {
		const int len = acl->domainname->total_len;
		if (!strncmp(acl->domainname->name,
			     r->param.signal.dest_pattern, len)) {
			switch (r->param.signal.dest_pattern[len]) {
			case ' ':
			case '\0':
				return true;
			}
		}
	}
	return false;
}

/* 
                                                 
  
                       
                      
  
                                                  
  
                                
 */
static int ccs_signal_acl2(const int sig, const int pid)
{
	struct ccs_request_info r;
	struct ccs_domain_info *dest = NULL;
	const struct ccs_domain_info * const domain = ccs_current_domain();
	if (ccs_init_request_info(&r, CCS_MAC_SIGNAL) == CCS_CONFIG_DISABLED)
		return 0;
	if (!sig)
		return 0;                /*                           */
	r.param_type = CCS_TYPE_SIGNAL_ACL;
	r.param.signal.sig = sig;
	r.param.signal.dest_pattern = domain->domainname->name;
	r.granted = true;
	if (ccs_sys_getpid() == pid) {
		ccs_audit_log(&r);
		return 0;                /*                            */
	}
	{ /*                      */
		struct task_struct *p = NULL;
		ccs_tasklist_lock();
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 24)
		if (pid > 0)
			p = ccsecurity_exports.find_task_by_vpid((pid_t) pid);
		else if (pid == 0)
			p = current;
		else if (pid == -1)
			dest = &ccs_kernel_domain;
		else
			p = ccsecurity_exports.find_task_by_vpid((pid_t) -pid);
#else
		if (pid > 0)
			p = find_task_by_pid((pid_t) pid);
		else if (pid == 0)
			p = current;
		else if (pid == -1)
			dest = &ccs_kernel_domain;
		else
			p = find_task_by_pid((pid_t) -pid);
#endif
		if (p)
			dest = ccs_task_domain(p);
		ccs_tasklist_unlock();
	}
	if (!dest)
		return 0; /*                            */
	if (domain == dest) {
		ccs_audit_log(&r);
		return 0;                /*                           */
	}
	r.param.signal.dest_pattern = dest->domainname->name;
	return ccs_check_acl(&r);
}

/* 
                                                
  
                      
                       
  
                                                  
 */
static int ccs_signal_acl(const int pid, const int sig)
{
	int error;
	if (!sig)
		error = 0;
	else {
		const int idx = ccs_read_lock();
		error = ccs_signal_acl2(sig, pid);
		ccs_read_unlock(idx);
	}
	return error;
}

/* 
                                                   
  
                 
                       
                        
  
                                                  
 */
static int ccs_signal_acl0(pid_t tgid, pid_t pid, int sig)
{
	return ccs_signal_acl(pid, sig);
}

#endif

#ifdef CONFIG_CCSECURITY_MISC

/* 
                                                                        
  
                                              
                                          
  
                                            
 */
static bool ccs_check_env_acl(struct ccs_request_info *r,
			      const struct ccs_acl_info *ptr)
{
	const struct ccs_env_acl *acl = container_of(ptr, typeof(*acl), head);
	return ccs_path_matches_pattern(r->param.environ.name, acl->env);
}

/* 
                                                                   
  
                                              
                                          
  
                                                  
  
                                
 */
static int ccs_env_perm(struct ccs_request_info *r, const char *env)
{
	struct ccs_path_info environ;
	if (!env || !*env)
		return 0;
	environ.name = env;
	ccs_fill_path_info(&environ);
	r->param_type = CCS_TYPE_ENV_ACL;
	r->param.environ.name = &environ;
	return ccs_check_acl(r);
}

/* 
                                                                 
  
                                       
  
                                                  
 */
static int ccs_environ(struct ccs_execve *ee)
{
	struct ccs_request_info *r = &ee->r;
	struct linux_binprm *bprm = ee->bprm;
	/*                                                */
	struct ccs_page_dump env_page = { };
	char *arg_ptr; /*                                */
	int arg_len = 0;
	unsigned long pos = bprm->p;
	int offset = pos % PAGE_SIZE;
	int argv_count = bprm->argc;
	int envp_count = bprm->envc;
	/*                                                             */
	int error = -ENOMEM;
	ee->r.type = CCS_MAC_ENVIRON;
	ee->r.profile = ccs_current_domain()->profile;
	ee->r.mode = ccs_get_mode(ee->r.profile, CCS_MAC_ENVIRON);
	if (!r->mode || !envp_count)
		return 0;
	arg_ptr = kzalloc(CCS_EXEC_TMPSIZE, CCS_GFP_FLAGS);
	if (!arg_ptr)
		goto out;
	while (error == -ENOMEM) {
		if (!ccs_dump_page(bprm, pos, &env_page))
			goto out;
		pos += PAGE_SIZE - offset;
		/*       */
		while (argv_count && offset < PAGE_SIZE) {
			if (!env_page.data[offset++])
				argv_count--;
		}
		if (argv_count) {
			offset = 0;
			continue;
		}
		while (offset < PAGE_SIZE) {
			const unsigned char c = env_page.data[offset++];
			if (c && arg_len < CCS_EXEC_TMPSIZE - 10) {
				if (c == '=') {
					arg_ptr[arg_len++] = '\0';
				} else if (c == '\\') {
					arg_ptr[arg_len++] = '\\';
					arg_ptr[arg_len++] = '\\';
				} else if (c > ' ' && c < 127) {
					arg_ptr[arg_len++] = c;
				} else {
					arg_ptr[arg_len++] = '\\';
					arg_ptr[arg_len++] = (c >> 6) + '0';
					arg_ptr[arg_len++]
						= ((c >> 3) & 7) + '0';
					arg_ptr[arg_len++] = (c & 7) + '0';
				}
			} else {
				arg_ptr[arg_len] = '\0';
			}
			if (c)
				continue;
			if (ccs_env_perm(r, arg_ptr)) {
				error = -EPERM;
				break;
			}
			if (!--envp_count) {
				error = 0;
				break;
			}
			arg_len = 0;
		}
		offset = 0;
	}
out:
	if (r->mode != CCS_CONFIG_ENFORCING)
		error = 0;
	kfree(env_page.data);
	kfree(arg_ptr);
	return error;
}

#endif

/* 
                                                    
  
                                      
                                      
                             
                                          
                                                    
  
                                            
 */
static bool ccs_argv(const unsigned int index, const char *arg_ptr,
		     const int argc, const struct ccs_argv *argv,
		     u8 *checked)
{
	int i;
	struct ccs_path_info arg;
	arg.name = arg_ptr;
	for (i = 0; i < argc; argv++, checked++, i++) {
		bool result;
		if (index != argv->index)
			continue;
		*checked = 1;
		ccs_fill_path_info(&arg);
		result = ccs_path_matches_pattern(&arg, argv->value);
		if (argv->is_not)
			result = !result;
		if (!result)
			return false;
	}
	return true;
}

/* 
                                                    
  
                                                
                                                 
                               
                                            
                                                         
  
                                            
 */
static bool ccs_envp(const char *env_name, const char *env_value,
		     const int envc, const struct ccs_envp *envp,
		     u8 *checked)
{
	int i;
	struct ccs_path_info name;
	struct ccs_path_info value;
	name.name = env_name;
	ccs_fill_path_info(&name);
	value.name = env_value;
	ccs_fill_path_info(&value);
	for (i = 0; i < envc; envp++, checked++, i++) {
		bool result;
		if (!ccs_path_matches_pattern(&name, envp->name))
			continue;
		*checked = 1;
		if (envp->value) {
			result = ccs_path_matches_pattern(&value, envp->value);
			if (envp->is_not)
				result = !result;
		} else {
			result = true;
			if (!envp->is_not)
				result = !result;
		}
		if (!result)
			return false;
	}
	return true;
}

/* 
                                              
  
                                         
                          
                                       
                          
                                      
  
                                            
 */
static bool ccs_scan_bprm(struct ccs_execve *ee,
			  const u16 argc, const struct ccs_argv *argv,
			  const u16 envc, const struct ccs_envp *envp)
{
	struct linux_binprm *bprm = ee->bprm;
	struct ccs_page_dump *dump = &ee->dump;
	char *arg_ptr = ee->tmp;
	int arg_len = 0;
	unsigned long pos = bprm->p;
	int offset = pos % PAGE_SIZE;
	int argv_count = bprm->argc;
	int envp_count = bprm->envc;
	bool result = true;
	u8 local_checked[32];
	u8 *checked;
	if (argc + envc <= sizeof(local_checked)) {
		checked = local_checked;
		memset(local_checked, 0, sizeof(local_checked));
	} else {
		checked = kzalloc(argc + envc, CCS_GFP_FLAGS);
		if (!checked)
			return false;
	}
	while (argv_count || envp_count) {
		if (!ccs_dump_page(bprm, pos, dump)) {
			result = false;
			goto out;
		}
		pos += PAGE_SIZE - offset;
		while (offset < PAGE_SIZE) {
			/*       */
			const char *kaddr = dump->data;
			const unsigned char c = kaddr[offset++];
			if (c && arg_len < CCS_EXEC_TMPSIZE - 10) {
				if (c == '\\') {
					arg_ptr[arg_len++] = '\\';
					arg_ptr[arg_len++] = '\\';
				} else if (c > ' ' && c < 127) {
					arg_ptr[arg_len++] = c;
				} else {
					arg_ptr[arg_len++] = '\\';
					arg_ptr[arg_len++] = (c >> 6) + '0';
					arg_ptr[arg_len++] =
						((c >> 3) & 7) + '0';
					arg_ptr[arg_len++] = (c & 7) + '0';
				}
			} else {
				arg_ptr[arg_len] = '\0';
			}
			if (c)
				continue;
			/*        */
			if (argv_count) {
				if (!ccs_argv(bprm->argc - argv_count,
					      arg_ptr, argc, argv,
					      checked)) {
					result = false;
					break;
				}
				argv_count--;
			} else if (envp_count) {
				char *cp = strchr(arg_ptr, '=');
				if (cp) {
					*cp = '\0';
					if (!ccs_envp(arg_ptr, cp + 1,
						      envc, envp,
						      checked + argc)) {
						result = false;
						break;
					}
				}
				envp_count--;
			} else {
				break;
			}
			arg_len = 0;
		}
		offset = 0;
		if (!result)
			break;
	}
out:
	if (result) {
		int i;
		/*                                */
		for (i = 0; i < argc; i++) {
			if (checked[i])
				continue;
			/*
                                                  
                                   
    */
			if (argv[i].is_not)
				continue;
			result = false;
			break;
		}
		for (i = 0; i < envc; envp++, i++) {
			if (checked[argc + i])
				continue;
			/*
                                                         
                                                          
    */
			if ((!envp->value && !envp->is_not) ||
			    (envp->value && envp->is_not))
				continue;
			result = false;
			break;
		}
	}
	if (checked != local_checked)
		kfree(checked);
	return result;
}

/* 
                                                                                      
  
                                    
                                              
                                                                
  
                                            
 */
static bool ccs_scan_exec_realpath(struct file *file,
				   const struct ccs_name_union *ptr,
				   const bool match)
{
	bool result;
	struct ccs_path_info exe;
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 20)
	struct path path;
#endif
	if (!file)
		return false;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 20)
	exe.name = ccs_realpath(&file->f_path);
#else
	path.mnt = file->f_vfsmnt;
	path.dentry = file->f_dentry;
	exe.name = ccs_realpath(&path);
#endif
	if (!exe.name)
		return false;
	ccs_fill_path_info(&exe);
	result = ccs_compare_name_union(&exe, ptr);
	kfree(exe.name);
	return result == match;
}

/* 
                                                  
  
                                          
  
                   
 */
void ccs_get_attributes(struct ccs_obj_info *obj)
{
	u8 i;
	struct dentry *dentry = NULL;

	for (i = 0; i < CCS_MAX_PATH_STAT; i++) {
		struct inode *inode;
		switch (i) {
		case CCS_PATH1:
			dentry = obj->path1.dentry;
			if (!dentry)
				continue;
			break;
		case CCS_PATH2:
			dentry = obj->path2.dentry;
			if (!dentry)
				continue;
			break;
		default:
			if (!dentry)
				continue;
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 5, 0)
			spin_lock(&dcache_lock);
			dentry = dget(dentry->d_parent);
			spin_unlock(&dcache_lock);
#else
			dentry = dget_parent(dentry);
#endif
			break;
		}
		inode = dentry->d_inode;
		if (inode) {
			struct ccs_mini_stat *stat = &obj->stat[i];
			stat->uid  = inode->i_uid;
			stat->gid  = inode->i_gid;
			stat->ino  = inode->i_ino;
			stat->mode = inode->i_mode;
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 5, 0)
			stat->dev  = inode->i_dev;
#else
			stat->dev  = inode->i_sb->s_dev;
#endif
			stat->rdev = inode->i_rdev;
			obj->stat_valid[i] = true;
		}
		if (i & 1) /*                                                */
			dput(dentry);
	}
}

/* 
                                        
  
                                               
                                                        
  
                                            
  
                                
 */
bool ccs_condition(struct ccs_request_info *r,
		   const struct ccs_condition *cond)
{
	const u32 ccs_flags = ccs_current_flags();
	u32 i;
	unsigned long min_v[2] = { 0, 0 };
	unsigned long max_v[2] = { 0, 0 };
	const struct ccs_condition_element *condp;
	const struct ccs_number_union *numbers_p;
	const struct ccs_name_union *names_p;
	const struct ccs_argv *argv;
	const struct ccs_envp *envp;
	struct ccs_obj_info *obj;
	u16 condc;
	u16 argc;
	u16 envc;
	struct linux_binprm *bprm = NULL;
	if (!cond)
		return true;
	condc = cond->condc;
	argc = cond->argc;
	envc = cond->envc;
	obj = r->obj;
	if (r->ee)
		bprm = r->ee->bprm;
	if (!bprm && (argc || envc))
		return false;
	condp = (struct ccs_condition_element *) (cond + 1);
	numbers_p = (const struct ccs_number_union *) (condp + condc);
	names_p = (const struct ccs_name_union *)
		(numbers_p + cond->numbers_count);
	argv = (const struct ccs_argv *) (names_p + cond->names_count);
	envp = (const struct ccs_envp *) (argv + argc);
	for (i = 0; i < condc; i++) {
		const bool match = condp->equals;
		const u8 left = condp->left;
		const u8 right = condp->right;
		bool is_bitop[2] = { false, false };
		u8 j;
		condp++;
		/*                                */
		if (left == CCS_ARGV_ENTRY || left == CCS_ENVP_ENTRY)
			continue;
		/*                           */
		if (right == CCS_NAME_UNION) {
			const struct ccs_name_union *ptr = names_p++;
			switch (left) {
				struct ccs_path_info *symlink;
				struct ccs_execve *ee;
				struct file *file;
			case CCS_SYMLINK_TARGET:
				symlink = obj ? obj->symlink_target : NULL;
				if (!symlink ||
				    !ccs_compare_name_union(symlink, ptr)
				    == match)
					goto out;
				break;
			case CCS_EXEC_REALPATH:
				ee = r->ee;
				file = ee ? ee->bprm->file : NULL;
				if (!ccs_scan_exec_realpath(file, ptr, match))
					goto out;
				break;
			}
			continue;
		}
		/*                                      */
		for (j = 0; j < 2; j++) {
			const u8 index = j ? right : left;
			unsigned long value = 0;
			switch (index) {
			case CCS_TASK_UID:
				value = from_kuid(&init_user_ns,
						  current_uid());
				break;
			case CCS_TASK_EUID:
				value = from_kuid(&init_user_ns,
						  current_euid());
				break;
			case CCS_TASK_SUID:
				value = from_kuid(&init_user_ns,
						  current_suid());
				break;
			case CCS_TASK_FSUID:
				value = from_kuid(&init_user_ns,
						  current_fsuid());
				break;
			case CCS_TASK_GID:
				value = from_kgid(&init_user_ns,
						  current_gid());
				break;
			case CCS_TASK_EGID:
				value = from_kgid(&init_user_ns,
						  current_egid());
				break;
			case CCS_TASK_SGID:
				value = from_kgid(&init_user_ns,
						  current_sgid());
				break;
			case CCS_TASK_FSGID:
				value = from_kgid(&init_user_ns,
						  current_fsgid());
				break;
			case CCS_TASK_PID:
				value = ccs_sys_getpid();
				break;
			case CCS_TASK_PPID:
				value = ccs_sys_getppid();
				break;
			case CCS_TYPE_IS_SOCKET:
				value = S_IFSOCK;
				break;
			case CCS_TYPE_IS_SYMLINK:
				value = S_IFLNK;
				break;
			case CCS_TYPE_IS_FILE:
				value = S_IFREG;
				break;
			case CCS_TYPE_IS_BLOCK_DEV:
				value = S_IFBLK;
				break;
			case CCS_TYPE_IS_DIRECTORY:
				value = S_IFDIR;
				break;
			case CCS_TYPE_IS_CHAR_DEV:
				value = S_IFCHR;
				break;
			case CCS_TYPE_IS_FIFO:
				value = S_IFIFO;
				break;
			case CCS_MODE_SETUID:
				value = S_ISUID;
				break;
			case CCS_MODE_SETGID:
				value = S_ISGID;
				break;
			case CCS_MODE_STICKY:
				value = S_ISVTX;
				break;
			case CCS_MODE_OWNER_READ:
				value = S_IRUSR;
				break;
			case CCS_MODE_OWNER_WRITE:
				value = S_IWUSR;
				break;
			case CCS_MODE_OWNER_EXECUTE:
				value = S_IXUSR;
				break;
			case CCS_MODE_GROUP_READ:
				value = S_IRGRP;
				break;
			case CCS_MODE_GROUP_WRITE:
				value = S_IWGRP;
				break;
			case CCS_MODE_GROUP_EXECUTE:
				value = S_IXGRP;
				break;
			case CCS_MODE_OTHERS_READ:
				value = S_IROTH;
				break;
			case CCS_MODE_OTHERS_WRITE:
				value = S_IWOTH;
				break;
			case CCS_MODE_OTHERS_EXECUTE:
				value = S_IXOTH;
				break;
			case CCS_EXEC_ARGC:
				if (!bprm)
					goto out;
				value = bprm->argc;
				break;
			case CCS_EXEC_ENVC:
				if (!bprm)
					goto out;
				value = bprm->envc;
				break;
			case CCS_TASK_TYPE:
				value = ((u8) ccs_flags)
					& CCS_TASK_IS_EXECUTE_HANDLER;
				break;
			case CCS_TASK_EXECUTE_HANDLER:
				value = CCS_TASK_IS_EXECUTE_HANDLER;
				break;
			case CCS_NUMBER_UNION:
				/*                     */
				break;
			default:
				if (!obj)
					goto out;
				if (!obj->validate_done) {
					ccs_get_attributes(obj);
					obj->validate_done = true;
				}
				{
					u8 stat_index;
					struct ccs_mini_stat *stat;
					switch (index) {
					case CCS_PATH1_UID:
					case CCS_PATH1_GID:
					case CCS_PATH1_INO:
					case CCS_PATH1_MAJOR:
					case CCS_PATH1_MINOR:
					case CCS_PATH1_TYPE:
					case CCS_PATH1_DEV_MAJOR:
					case CCS_PATH1_DEV_MINOR:
					case CCS_PATH1_PERM:
						stat_index = CCS_PATH1;
						break;
					case CCS_PATH2_UID:
					case CCS_PATH2_GID:
					case CCS_PATH2_INO:
					case CCS_PATH2_MAJOR:
					case CCS_PATH2_MINOR:
					case CCS_PATH2_TYPE:
					case CCS_PATH2_DEV_MAJOR:
					case CCS_PATH2_DEV_MINOR:
					case CCS_PATH2_PERM:
						stat_index = CCS_PATH2;
						break;
					case CCS_PATH1_PARENT_UID:
					case CCS_PATH1_PARENT_GID:
					case CCS_PATH1_PARENT_INO:
					case CCS_PATH1_PARENT_PERM:
						stat_index = CCS_PATH1_PARENT;
						break;
					case CCS_PATH2_PARENT_UID:
					case CCS_PATH2_PARENT_GID:
					case CCS_PATH2_PARENT_INO:
					case CCS_PATH2_PARENT_PERM:
						stat_index = CCS_PATH2_PARENT;
						break;
					default:
						goto out;
					}
					if (!obj->stat_valid[stat_index])
						goto out;
					stat = &obj->stat[stat_index];
					switch (index) {
					case CCS_PATH1_UID:
					case CCS_PATH2_UID:
					case CCS_PATH1_PARENT_UID:
					case CCS_PATH2_PARENT_UID:
						value = from_kuid
							(&init_user_ns,
							 stat->uid);
						break;
					case CCS_PATH1_GID:
					case CCS_PATH2_GID:
					case CCS_PATH1_PARENT_GID:
					case CCS_PATH2_PARENT_GID:
						value = from_kgid
							(&init_user_ns,
							 stat->gid);
						break;
					case CCS_PATH1_INO:
					case CCS_PATH2_INO:
					case CCS_PATH1_PARENT_INO:
					case CCS_PATH2_PARENT_INO:
						value = stat->ino;
						break;
					case CCS_PATH1_MAJOR:
					case CCS_PATH2_MAJOR:
						value = MAJOR(stat->dev);
						break;
					case CCS_PATH1_MINOR:
					case CCS_PATH2_MINOR:
						value = MINOR(stat->dev);
						break;
					case CCS_PATH1_TYPE:
					case CCS_PATH2_TYPE:
						value = stat->mode & S_IFMT;
						break;
					case CCS_PATH1_DEV_MAJOR:
					case CCS_PATH2_DEV_MAJOR:
						value = MAJOR(stat->rdev);
						break;
					case CCS_PATH1_DEV_MINOR:
					case CCS_PATH2_DEV_MINOR:
						value = MINOR(stat->rdev);
						break;
					case CCS_PATH1_PERM:
					case CCS_PATH2_PERM:
					case CCS_PATH1_PARENT_PERM:
					case CCS_PATH2_PARENT_PERM:
						value = stat->mode & S_IALLUGO;
						break;
					}
				}
				break;
			}
			max_v[j] = value;
			min_v[j] = value;
			switch (index) {
			case CCS_MODE_SETUID:
			case CCS_MODE_SETGID:
			case CCS_MODE_STICKY:
			case CCS_MODE_OWNER_READ:
			case CCS_MODE_OWNER_WRITE:
			case CCS_MODE_OWNER_EXECUTE:
			case CCS_MODE_GROUP_READ:
			case CCS_MODE_GROUP_WRITE:
			case CCS_MODE_GROUP_EXECUTE:
			case CCS_MODE_OTHERS_READ:
			case CCS_MODE_OTHERS_WRITE:
			case CCS_MODE_OTHERS_EXECUTE:
				is_bitop[j] = true;
			}
		}
		if (left == CCS_NUMBER_UNION) {
			/*                   */
			const struct ccs_number_union *ptr = numbers_p++;
			min_v[0] = ptr->values[0];
			max_v[0] = ptr->values[1];
		}
		if (right == CCS_NUMBER_UNION) {
			/*                   */
			const struct ccs_number_union *ptr = numbers_p++;
			if (ptr->group) {
				if (ccs_number_matches_group(min_v[0],
							     max_v[0],
							     ptr->group)
				    == match)
					continue;
			} else {
				if ((min_v[0] <= ptr->values[1] &&
				     max_v[0] >= ptr->values[0]) == match)
					continue;
			}
			goto out;
		}
		/*
                                                       
                           
   */
		if (is_bitop[0] && is_bitop[1]) {
			goto out;
		} else if (is_bitop[0]) {
			switch (right) {
			case CCS_PATH1_PERM:
			case CCS_PATH1_PARENT_PERM:
			case CCS_PATH2_PERM:
			case CCS_PATH2_PARENT_PERM:
				if (!(max_v[0] & max_v[1]) == !match)
					continue;
			}
			goto out;
		} else if (is_bitop[1]) {
			switch (left) {
			case CCS_PATH1_PERM:
			case CCS_PATH1_PARENT_PERM:
			case CCS_PATH2_PERM:
			case CCS_PATH2_PARENT_PERM:
				if (!(max_v[0] & max_v[1]) == !match)
					continue;
			}
			goto out;
		}
		/*                                */
		if ((min_v[0] <= max_v[1] && max_v[0] >= min_v[1]) == match)
			continue;
out:
		return false;
	}
	/*                              */
	if (r->ee && (argc || envc))
		return ccs_scan_bprm(r->ee, argc, argv, envc, envp);
	return true;
}

#ifdef CONFIG_CCSECURITY_TASK_DOMAIN_TRANSITION

/* 
                                                            
  
                                              
                                          
  
                                            
 */
static bool ccs_check_task_acl(struct ccs_request_info *r,
			       const struct ccs_acl_info *ptr)
{
	const struct ccs_task_acl *acl = container_of(ptr, typeof(*acl), head);
	return !ccs_pathcmp(r->param.task.domainname, acl->domainname);
}

#endif

/* 
                                                                        
  
                                                              
                                         
  
                
  
                                                                               
                                                                     
                                                                         
                                                                       
 */
int ccs_init_request_info(struct ccs_request_info *r, const u8 index)
{
#ifdef CONFIG_CCSECURITY_TASK_DOMAIN_TRANSITION
	u8 i;
	const char *buf;
	for (i = 0; i < 255; i++) {
		const u8 profile = ccs_current_domain()->profile;
		memset(r, 0, sizeof(*r));
		r->profile = profile;
		r->type = index;
		r->mode = ccs_get_mode(profile, index);
		r->param_type = CCS_TYPE_AUTO_TASK_ACL;
		ccs_check_acl(r);
		if (!r->granted)
			return r->mode;
		buf = container_of(r->matched_acl, typeof(struct ccs_task_acl),
				   head)->domainname->name;
		if (!ccs_assign_domain(buf, true))
			break;
	}
	ccs_transition_failed(buf);
	return CCS_CONFIG_DISABLED;
#else
	const u8 profile = ccs_current_domain()->profile;
	memset(r, 0, sizeof(*r));
	r->profile = profile;
	r->type = index;
	r->mode = ccs_get_mode(profile, index);
	return r->mode;
#endif
}

/* 
                                                                         
  
                               
  
                                                                     
 */
static bool ccs_byte_range(const char *str)
{
	return *str >= '0' && *str++ <= '3' &&
		*str >= '0' && *str++ <= '7' &&
		*str >= '0' && *str <= '7';
}

/* 
                                                                    
  
                              
  
                                                              
 */
static bool ccs_decimal(const char c)
{
	return c >= '0' && c <= '9';
}

/* 
                                                                            
  
                              
  
                                                                  
 */
static bool ccs_hexadecimal(const char c)
{
	return (c >= '0' && c <= '9') ||
		(c >= 'A' && c <= 'F') ||
		(c >= 'a' && c <= 'f');
}

/* 
                                                                  
  
                              
  
                                                                
 */
static bool ccs_alphabet_char(const char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

/* 
                                                                                       
  
                                               
                                             
                                                  
                                                
  
                                                               
 */
static bool ccs_file_matches_pattern2(const char *filename,
				      const char *filename_end,
				      const char *pattern,
				      const char *pattern_end)
{
	while (filename < filename_end && pattern < pattern_end) {
		char c;
		if (*pattern != '\\') {
			if (*filename++ != *pattern++)
				return false;
			continue;
		}
		c = *filename;
		pattern++;
		switch (*pattern) {
			int i;
			int j;
		case '?':
			if (c == '/') {
				return false;
			} else if (c == '\\') {
				if (filename[1] == '\\')
					filename++;
				else if (ccs_byte_range(filename + 1))
					filename += 3;
				else
					return false;
			}
			break;
		case '\\':
			if (c != '\\')
				return false;
			if (*++filename != '\\')
				return false;
			break;
		case '+':
			if (!ccs_decimal(c))
				return false;
			break;
		case 'x':
			if (!ccs_hexadecimal(c))
				return false;
			break;
		case 'a':
			if (!ccs_alphabet_char(c))
				return false;
			break;
		case '0':
		case '1':
		case '2':
		case '3':
			if (c == '\\' && ccs_byte_range(filename + 1)
			    && !strncmp(filename + 1, pattern, 3)) {
				filename += 3;
				pattern += 2;
				break;
			}
			return false; /*              */
		case '*':
		case '@':
			for (i = 0; i <= filename_end - filename; i++) {
				if (ccs_file_matches_pattern2(filename + i,
							      filename_end,
							      pattern + 1,
							      pattern_end))
					return true;
				c = filename[i];
				if (c == '.' && *pattern == '@')
					break;
				if (c != '\\')
					continue;
				if (filename[i + 1] == '\\')
					i++;
				else if (ccs_byte_range(filename + i + 1))
					i += 3;
				else
					break; /*              */
			}
			return false; /*              */
		default:
			j = 0;
			c = *pattern;
			if (c == '$') {
				while (ccs_decimal(filename[j]))
					j++;
			} else if (c == 'X') {
				while (ccs_hexadecimal(filename[j]))
					j++;
			} else if (c == 'A') {
				while (ccs_alphabet_char(filename[j]))
					j++;
			}
			for (i = 1; i <= j; i++) {
				if (ccs_file_matches_pattern2(filename + i,
							      filename_end,
							      pattern + 1,
							      pattern_end))
					return true;
			}
			return false; /*                             */
		}
		filename++;
		pattern++;
	}
	while (*pattern == '\\' &&
	       (*(pattern + 1) == '*' || *(pattern + 1) == '@'))
		pattern += 2;
	return filename == filename_end && pattern == pattern_end;
}

/* 
                                                                     
  
                                               
                                             
                                                  
                                                
  
                                                               
 */
static bool ccs_file_matches_pattern(const char *filename,
				     const char *filename_end,
				     const char *pattern,
				     const char *pattern_end)
{
	const char *pattern_start = pattern;
	bool first = true;
	bool result;
	while (pattern < pattern_end - 1) {
		/*                        */
		if (*pattern++ != '\\' || *pattern++ != '-')
			continue;
		result = ccs_file_matches_pattern2(filename, filename_end,
						   pattern_start, pattern - 2);
		if (first)
			result = !result;
		if (result)
			return false;
		first = false;
		pattern_start = pattern;
	}
	result = ccs_file_matches_pattern2(filename, filename_end,
					   pattern_start, pattern_end);
	return first ? result : !result;
}

/* 
                                                            
  
                                    
                                       
  
                                                  
 */
static bool ccs_path_matches_pattern2(const char *f, const char *p)
{
	const char *f_delimiter;
	const char *p_delimiter;
	while (*f && *p) {
		f_delimiter = strchr(f, '/');
		if (!f_delimiter)
			f_delimiter = f + strlen(f);
		p_delimiter = strchr(p, '/');
		if (!p_delimiter)
			p_delimiter = p + strlen(p);
		if (*p == '\\' && *(p + 1) == '{')
			goto recursive;
		if (!ccs_file_matches_pattern(f, f_delimiter, p, p_delimiter))
			return false;
		f = f_delimiter;
		if (*f)
			f++;
		p = p_delimiter;
		if (*p)
			p++;
	}
	/*                                            */
	while (*p == '\\' &&
	       (*(p + 1) == '*' || *(p + 1) == '@'))
		p += 2;
	return !*f && !*p;
recursive:
	/*
                                                           
                                                  
                                                                 
                                                              
  */
	if (*(p - 1) != '/' || p_delimiter <= p + 3 || *p_delimiter != '/' ||
	    *(p_delimiter - 1) != '}' || *(p_delimiter - 2) != '\\')
		return false; /*              */
	do {
		/*                                         */
		if (!ccs_file_matches_pattern(f, f_delimiter, p + 2,
					      p_delimiter - 2))
			break;
		/*                            */
		f = f_delimiter;
		if (!*f)
			break;
		f++;
		/*                      */
		if (ccs_path_matches_pattern2(f, p_delimiter + 1))
			return true;
		f_delimiter = strchr(f, '/');
	} while (f_delimiter);
	return false; /*              */
}

/* 
                                                                                         
  
                                    
                                     
  
                                            
  
                                        
                     
                                           
                                                                  
                                                                         
                                            
                                                      
                            
                                                          
                                
                                                           
                                 
  
                                 
  
                                                                              
                                 
 */
static bool ccs_path_matches_pattern(const struct ccs_path_info *filename,
				     const struct ccs_path_info *pattern)
{
	const char *f = filename->name;
	const char *p = pattern->name;
	const int len = pattern->const_len;
	/*                                                          */
	if (!pattern->is_patterned)
		return !ccs_pathcmp(filename, pattern);
	/*                                            */
	if (filename->is_dir != pattern->is_dir)
		return false;
	/*                                              */
	if (strncmp(f, p, len))
		return false;
	f += len;
	p += len;
	return ccs_path_matches_pattern2(f, p);
}
