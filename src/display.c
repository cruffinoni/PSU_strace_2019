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
    const strace_t *this)
{
    illong_t rtn = ptrace(PTRACE_PEEKTEXT, this->child, regs.rax, NULL);

    if ((illong_t) regs.rax < 0 && this->flags)
        fprintf(stderr, ") = %lli\n", rtn);
    else if (regs.rax > 0xFFFF || this->flags)
        fprintf(stderr, ") = 0x%llx\n", (ullong_t) regs.rax);
    else
        fprintf(stderr, ") = %lli\n", regs.rax);
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
    ullong_t registers[] = {regs.rdi, regs.rsi, regs.rdx, regs.rdx,
                            regs.rdx, regs.rdx};
    const size_t params_len = strlen(SYSCALL_PARAMS[regs.orig_rax].params);

    fprintf(stderr, "%s(", SYSCALL_NAMES[regs.orig_rax]);
    for (uint i = 0; i < params_len; ++i) {
        if (!this->flags && SYSCALL_PARAMS[regs.orig_rax].params[i] != 'v')
            fprintf(stderr, "0x%llx", registers[i]);
        else if (this->flags)
            fprintf(stderr, "?");
        if ((i + 1) != params_len)
            fprintf(stderr, ", ");
    }
    dislay_rtn_value(regs, this);
}
