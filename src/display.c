/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include "strace.h"

static void dislay_rtn_value(const struct user_regs_struct regs,
    const pid_t child)
{
    illong_t rtn = ptrace(PTRACE_PEEKTEXT, child, regs.rax, NULL);

    fprintf(stderr, " / param: %zu", strlen(SYSCALL_PARAMS[regs.orig_rax].params));
    if ((illong_t) regs.rax < 0)
        fprintf(stderr, " = %lli\n", rtn);
    else if (regs.rax > 0xFFFF)
        fprintf(stderr, " = 0x%llx\n", (ullong_t) regs.rax);
    else
        fprintf(stderr, " = %lli\n", regs.rax);
}

static char *display_register(const ullong_t reg)
{
    char *str = malloc(25);

    if (str == NULL)
        return (NULL);
    if (reg < 0xFFFF)
        sprintf(str, "%llu", reg);
    else
        sprintf(str, "0x%llx", reg);
    return (str);
}

void display_trace(const strace_t *this, const regs_t regs)
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
        fprintf(stderr, "%s(", SYSCALL_NAMES[regs.orig_rax]);
        for (uint i = 0, len = strlen(SYSCALL_PARAMS[regs.orig_rax].params); i < len; ++i) {
            if (i == 0)
                fprintf(stderr, ", ")
        }
        dislay_rtn_value(regs, this->child);
    }
}
