/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef SRC_SYSCALL_NAMES_
#define SRC_SYSCALL_NAMES_

typedef struct sysattr_s {
    char *params;
    char rtn;
} sysattr_t;

static const __attribute__ ((unused)) sysattr_t SYSCALL_PARAMS[] = {
    {"isi", 'i'}, {"isi", 'i'}, {"si", 'i'},
    {"i", 'i'}, {"sp", 'i'}, {"ip", 'i'}, {"sp", 'i'},
    {"pii", 'i'},
    {"iii", 'i'}, {"piiiii", 'i'}, {"pii", 'i'},
    {"ii", 'i'}, {"p", 'i'},
    {"ippi", 'i'}, {"ippi", 'i'}, {"pppppp", 'i'},
    {"iii", 'i'}, {"isii", 'i'}, {"isii", 'i'},
    {"ipi", 'i'}, {"ipi", 'i'}, {"si", 'i'}, {"p", 'i'},
    {"ipppp", 'i'}, {"v", 'i'},
    {"iiiii", 'i'}, {"iii", 'i'}, {"iip", 'i'}, {"iii", 'i'},
    {"iii", 'i'}, {"isi", 'i'}, {"iip", 'i'}, {"i", 'i'},
    {"ii", 'i'}, {"v", 'i'}, {"pp", 'i'}, {"ip", 'i'},
    {"i", 'i'}, {"ipp", 'i'},
    {"v", 'i'}, {"iipi", 'i'}, {"iii", 'i'}, {"ipi", 'i'},
    {"ipp", 'i'}, {"ipiipi", 'i'},
    {"ipiipp", 'i'}, {"ipi", 'i'}, {"ipi", 'i'}, {"ii", 'i'},
    {"ipi", 'i'}, {"ii", 'i'}, {"ipp", 'i'},
    {"ipp", 'i'}, {"iiip", 'i'}, {"iiisi", 'i'}, {"iiisp", 'i'},
    {"iippi", 'i'}, {"v", 'i'}, {"v", 'i'},
    {"spp", 'i'}, {"i", 'i'}, {"ipip", 'i'}, {"ii", 'i'},
    {"p", 'i'}, {"iii", 'i'}, {"ipi", 'i'}, {"iiii", 'i'},
    {"s", 'i'}, {"ii", 'i'}, {"ipii", 'i'}, {"ipiii", 'i'},
    {"iip", 'i'}, {"iii", 'i'}, {"ii", 'i'}, {"i", 'i'},
    {"i", 'i'}, {"si", 'i'}, {"ii", 'i'}, {"ipi", 'i'},
    {"si", 'i'}, {"s", 'i'}, {"i", 'i'}, {"s s", 'i'}, {"si", 'i'},
    {"s", 'i'}, {"si", 'i'}, {"ss", 'i'}, {"s", 'i'}, {"ss", 'i'},
    {"ssi", 'i'}, {"si", 'i'}, {"ii", 'i'}, {"sii", 'i'},
    {"iii", 'i'}, {"sii", 'i'}, {"i", 'i'}, {"pp", 'i'}, {"ip", 'i'},
    {"ip", 'i'}, {"p", 'i'}, {"p", 'i'}, {"iiii", 'i'},
    {"v", 'i'}, {"isi", 'i'}, {"v", 'i'}, {"i", 'i'}, {"i", 'i'},
    {"v", 'i'}, {"v", 'i'}, {"ii", 'i'}, {"v", 'i'},
    {"v", 'i'}, {"v", 'i'}, {"ii", 'i'}, {"ii", 'i'}, {"ip", 'i'},
    {"ip", 'i'}, {"iii", 'i'}, {"ppp", 'i'},
    {"iii", 'i'}, {"ppp", 'i'}, {"i", 'i'},
    {"i", 'i'}, {"i", 'i'}, {"i", 'i'}, {"ii", 'i'}, {"ii", 'i'},
    {"pi", 'i'}, {"pppi", 'i'}, {"iip", 'i'}, {"pi", 'i'},
    {"pp", 'i'}, {"sp", 'i'}, {"sii", 'i'}, {"s", 'i'}, {"i", 'i'},
    {"ip", 'i'}, {"sp", 'i'}, {"ip", 'i'}, {"iii", 'i'},
    {"ii", 'i'}, {"iii", 'i'}, {"ip", 'i'}, {"ip", 'i'}, {"iip", 'i'},
    {"i", 'i'}, {"i", 'i'}, {"i", 'i'}, {"ip", 'i'},
    {"ii", 'i'}, {"ii", 'i'}, {"i", 'i'},
    {"v", 'i'}, {"v", 'i'}, {"pppppp", 'i'}, {"ss", 'i'},
    {"pppppp", 'i'}, {"iiiii", 'i'}, {"ip", 'i'}, {"p", 'i'},
    {"ip", 'i'}, {"s", 'i'}, {"v", 'i'}, {"s", 'i'}, {"pp", 'i'},
    {"sssip", 'i'}, {"pppppp", 'i'}, {"si", 'i'}, {"s", 'i'},
    {"iiip", 'i'}, {"si", 'i'}, {"si", 'i'}, {"i", 'i'},
    {"pppppp", 'i'}, {"pppppp", 'i'}, {"pis", 'i'},
    {"si", 'i'}, {"pppppp", 'i'},
    {"pppppp", 'i'}, {"isip", 'i'}, {"pppppp", 'i'},
    {"pppppp", 'i'}, {"pppppp", 'i'}, {"pppppp", 'i'},
    {"pppppp", 'i'}, {"pppppp", 'i'}, {"v", 'i'}, {"iii", 'i'},
    {"sspii", 'i'}, {"sspii", 'i'}, {"ispii", 'i'},
    {"sspi", 'i'}, {"sspi", 'i'}, {"ispi", 'i'}, {"ssi", 'i'},
    {"ssi", 'i'}, {"isi", 'i'}, {"ss", 'i'}, {"ss", 'i'}, {"is", 'i'},
    {"ii", 'i'}, {"p", 'i'}, {"piippi", 'i'}, {"iip", 'i'},
    {"iip", 'i'}, {"p", 'i'}, {"ip", 'i'}, {"i", 'i'},
    {"iiipp", 'i'}, {"iip", 'i'}, {"ipp", 'i'}, {"p", 'i'},
    {"isi", 'i'}, {"i", 'i'}, {"pppppp", 'i'},
    {"pppppp", 'i'}, {"iiiii", 'i'}, {"ipi", 'i'},
    {"p", 'i'}, {"v", 'i'},
    {"ipip", 'i'}, {"iiii", 'i'}, {"ipp", 'i'}, {"iipp", 'i'},
    {"ip", 'i'}, {"i", 'i'},
    {"i", 'i'}, {"ip", 'i'}, {"ip", 'i'}, {"ip", 'i'},
    {"iipp", 'i'}, {"i", 'i'},
    {"ipii", 'i'}, {"iiip", 'i'}, {"iii", 'i'}, {"sp", 'i'},
    {"pppppp", 'i'},
    {"iiipii", 'i'}, {"ipi", 'i'}, {"ppiii", 'i'},
    {"siip", 'i'}, {"s", 'i'},
    {"isiip", 'i'}, {"isipp", 'i'}, {"ip", 'i'}, {"ipp", 'i'},
    {"iipi", 'i'},
    {"iipip", 'i'}, {"sspii", 'i'}, {"sssi", 'i'}, {"iiiii", 'i'},
    {"pppppp", 'i'},
    {"pppppp", 'i'}, {"v", 'i'}, {"isi", 'i'}, {"ii", 'i'},
    {"iipp", 'i'},
    {"isii", 'i'}, {"isi", 'i'}, {"isii", 'i'}, {"isiii", 'i'},
    {"isp", 'i'},
    {"ispi", 'i'}, {"isi", 'i'}, {"isis", 'i'}, {"isisi", 'i'},
    {"si s", 'i'},
    {"issi", 'i'}, {"isi", 'i'}, {"isi", 'i'}, {"ippppp", 'i'},
    {"pippi", 'i'},
    {"i", 'i'}, {"pi", 'i'}, {"ipp", 'i'}, {"ipipii", 'i'},
    {"iiii", 'i'},
    {"iiii", 'i'}, {"ipii", 'i'}, {"iipppi", 'i'}, {"ispi", 'i'},
    {"ipiipi", 'i'},
    {"ipi", 'i'}, {"ii", 'i'}, {"i", 'i'}, {"iiii", 'i'},
    {"iipp", 'i'},
    {"ip", 'i'}, {"ippi", 'i'}, {"ipii", 'i'}, {"ii", 'i'},
    {"i", 'i'},
    {"iii", 'i'}, {"pi", 'i'}, {"i", 'i'}, {"ipiii", 'i'},
    {"ipiii", 'i'},
    {"iiip", 'i'}, {"piiii", 'i'}, {"ipiip", 'i'}, {"ii", 'i'},
    {"iiiis", 'i'},
    {"iipp", 'i'}, {"isppi", 'i'}, {"ipi", 'i'}, {"ip", 'i'},
    {"i", 'i'},
    {"ipii", 'i'}, {"ii", 'i'}, {"ppp", 'i'}, {"ipipii", 'i'},
    {"ipipii", 'i'},
    {"iiiii", 'i'}, {"isi", 'i'}, {"ipi", 'i'}, {"ipii", 'i'},
    {"isisi", 'i'},
    {"iis", 'i'}, {"pppppp", 'i'}, {"si", 'i'}, {"iiisi", 'i'},
    {"ipi", 'i'},
    {"isppi", 'i'}, {"i", 'i'}, {"ii", 'i'}, {"iii", 'i'},
    {"ipipii", 'i'},
    {"ipiiii", 'i'}, {"ipiiii", 'i'}, {"iiii", 'i'}, {"ii", 'i'},
    {"i", 'i'}
};

static const __attribute__ ((unused)) char *SYSCALL_NAMES[] = {
    "read", "write", "open", "close", "stat", "fstat", "lstat", "poll", "lseek",
    "mmap", "mprotect", "munmap", "brk", "rt_sigaction", "rt_sigprocmask",
    "rt_sigreturn", "ioctl", "pread64", "pwrite64", "readv", "writev",
    "access", "pipe", "select", "sched_yield", "mremap", "msync", "mincore",
    "madvise", "shmget", "shmat", "shmctl", "dup", "dup2", "pause", "nanosleep",
    "getitimer", "alarm", "setitimer", "getpid", "sendfile", "socket",
    "connect", "accept", "sendto", "recvfrom", "sendmsg", "recvmsg",
    "shutdown", "bind", "listen", "getsockname", "getpeername",
    "socketpair", "setsockopt", "getsockopt", "clone", "fork", "vfork",
    "execve", "exit", "wait4", "kill", "uname", "semget", "semop", "semctl",
    "shmdt", "msgget", "msgsnd", "msgrcv", "msgctl", "fcntl", "flock", "fsync",
    "fdatasync", "truncate", "ftruncate", "getdents", "getcwd", "chdir",
    "fchdir", "rename", "mkdir", "rmdir", "creat", "link", "unlink", "symlink",
    "readlink", "chmod", "fchmod", "chown", "fchown", "lchown", "umask",
    "gettimeofday", "getrlimit", "getrusage", "sysinfo", "times", "ptrace",
    "getuid", "syslog", "getgid", "setuid", "setgid", "geteuid", "getegid",
    "setpgid", "getppid", "getpgrp", "setsid", "setreuid", "setregid",
    "getgroups", "setgroups", "setresuid", "getresuid", "setresgid",
    "getresgid", "getpgid", "setfsuid", "setfsgid", "getsid", "capget",
    "capset", "rt_sigpending", "rt_sigtimedwait", "rt_sigqueueinfo",
    "rt_sigsuspend", "sigaltstack", "utime", "mknod", "uselib", "personality",
    "ustat", "statfs", "fstatfs", "sysfs", "getpriority", "setpriority",
    "sched_setparam", "sched_getparam", "sched_setscheduler",
    "sched_getscheduler", "sched_get_priority_max", "sched_get_priority_min",
    "sched_rr_get_interval", "mlock", "munlock", "mlockall", "munlockall",
    "vhangup", "modify_ldt", "pivot_root", "_sysctl", "prctl", "arch_prctl",
    "adjtimex", "setrlimit", "chroot", "sync", "acct", "settimeofday",
    "mount", "umount2", "swapon", "swapoff", "reboot", "sethostname",
    "setdomainname", "iopl", "ioperm", "create_module", "init_module",
    "delete_module", "get_kernel_syms", "query_module", "quotactl",
    "nfsservctl", "getpmsg", "putpmsg", "afs_syscall", "tuxcall", "security",
    "gettid", "readahead", "setxattr", "lsetxattr", "fsetxattr", "getxattr",
    "lgetxattr", "fgetxattr", "listxattr", "llistxattr", "flistxattr",
    "removexattr", "lremovexattr", "fremovexattr", "tkill", "time", "futex",
    "sched_setaffinity", "sched_getaffinity", "set_thread_area", "io_setup",
    "io_destroy", "io_getevents", "io_submit", "io_cancel", "get_thread_area",
    "lookup_dcookie", "epoll_create", "epoll_ctl_old", "epoll_wait_old",
    "remap_file_pages", "getdents64", "set_tid_address", "restart_syscall",
    "semtimedop", "fadvise64", "timer_create", "timer_settime", "timer_gettime",
    "timer_getoverrun", "timer_delete", "clock_settime", "clock_gettime",
    "clock_getres", "clock_nanosleep", "exit_group", "epoll_wait", "epoll_ctl",
    "tgkill", "utimes", "vserver", "mbind", "set_mempolicy", "get_mempolicy",
    "mq_open", "mq_unlink", "mq_timedsend", "mq_timedreceive", "mq_notify",
    "mq_getsetattr", "kexec_load", "waitid", "add_key", "request_key", "keyctl",
    "ioprio_set", "ioprio_get", "inotify_init", "inotify_add_watch",
    "inotify_rm_watch", "migrate_pages", "openat", "mkdirat", "mknodat",
    "fchownat", "futimesat", "newfstatat", "unlinkat", "renameat", "linkat",
    "symlinkat", "readlinkat", "fchmodat", "faccessat", "pselect6", "ppoll",
    "unshare", "set_robust_list", "get_robust_list", "splice", "tee",
    "sync_file_range", "vmsplice", "move_pages", "utimensat", "epoll_pwait",
    "signalfd", "timerfd_create", "eventfd", "fallocate", "timerfd_settime",
    "timerfd_gettime", "accept4", "signalfd4", "eventfd2", "epoll_create1",
    "dup3", "pipe2", "inotify_init1", "preadv", "pwritev", "rt_tgsigqueueinfo",
    "perf_event_open", "recvmmsg", "fanotify_init", "fanotify_mark",
    "prlimit64", "name_to_handle_at", "open_by_handle_at", "clock_adjtime",
    "syncfs", "sendmmsg", "setns", "getcpu", "process_vm_readv",
    "process_vm_writev", "kcmp", "finit_module", "sched_setattr",
    "sched_getattr", "renameat2", "seccomp", "getrandom", "memfd_create",
    "kexec_file_load", "bpf", "stub_execveat", "userfaultfd", "membarrier",
    "mlock2", "copy_file_range", "preadv2", "pwritev2", "pkey_mprotect",
    "pkey_alloc", "pkey_free", "statx", "io_pgetevents", "rseq",
    "pkey_mprotect",
};
#endif
