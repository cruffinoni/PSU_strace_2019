/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include "strace.h"

static char *retrieve_string(const ullong_t src, const pid_t child)
{
    char *str = NULL;
    char c = 0;

    for (int i = 0; str == NULL || c != '\0'; i++) {
        str = realloc(str, i + 1);
        if (str == NULL)
            return (NULL);
        c = (char) ptrace(PTRACE_PEEKTEXT, child, src + i, NULL);
        if (IS_PRINTABLE(c))
            str[i] = c;
        else {
            str = realloc(str, i + 1);
            if (str == NULL)
                return (NULL);
            str[i++] = '\\';
            str[i++] = 'n';
        }
    }
    return (str);
}

static illong_t get_rtn_value(const struct user_regs_struct regs,
    const pid_t child)
{
    illong_t rtn = ptrace(PTRACE_PEEKTEXT, child, regs.rax, NULL);

    if ((illong_t) regs.rax < 0)
        return (rtn);
    return ((ullong_t) regs.rax);
}

void display_trace(strace_t *this, const regs_t regs)
{
    //printf(
    //    "[%llu] -> '%s' (0x%llx, 0x%llx, 0x%llx) = 0x%llx (= %lli)\n",
    //    regs.orig_rax, SYSCALL_NAMES[regs.orig_rax], regs.rdi,
    //    regs.rsi, regs.rdx, regs.rax,
    //    get_rtn_value(regs, this->child));
    if (!this->flags)
        fprintf(stderr,"%s(0x%llx, 0x%llx, 0x%llx) = 0x%llx\n",
        SYSCALL_NAMES[regs.orig_rax], regs.rdi, regs.rsi, regs.rdx,
        regs.rax);
    else {
        fprintf(stderr,"%s(0x%llx, 0x%llx, 0x%llx) = 0x%llx\n",
        SYSCALL_NAMES[regs.orig_rax], regs.rdi, regs.rsi, regs.rdx,
        regs.rax);
    }
}
