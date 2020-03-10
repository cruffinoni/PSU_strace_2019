/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef SRC_PSU_STRACE_
#define SRC_PSU_STRACE_

#include <sys/param.h>
#include "error.h"
#include "sysname.h"

typedef unsigned long long ullong_t;
typedef int long long illong_t;

#define IS_SYSCALL(a)   (a <= 313)
#define IS_PRINTABLE(c) ((c >= 32 && c <= 126))

#define IS_FLAG(a, i, c) (a[i][0] == '-' && a[i][1] == c && a[i][2] == '\0')

typedef struct strace_s {
    uint flags;
    pid_t child;
    char *process_name;
    uint child_exit;
} strace_t;

error_t display_perror(const char *reason);
error_t display_err(const error_t error);
error_t execute_child(strace_t *this);

#endif
