/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef SRC_PSU_STRACE_
#define SRC_PSU_STRACE_

#include "sysname.h"

typedef unsigned long long ullong_t;
typedef int long long illong_t;

#define IS_SYSCALL(a)   (a <= 313)
#define IS_PRINTABLE(c) ((c >= 32 && c <= 126))

#endif
