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

static void dislay_rtn_value(const strace_t *this, const regs_t regs)
{
    illong_t rtn = ptrace(PTRACE_PEEKTEXT, this->child, regs.rax, NULL);

    if ((illong_t) regs.rax < 0 && this->verbose)
        fprintf(stderr, ") = %lli\n", rtn);
    else if (regs.rax > 0xFFFF || !this->verbose)
        fprintf(stderr, ") = 0x%llx\n", (ullong_t) regs.rax);
    else
        fprintf(stderr, ") = %lli\n", regs.rax);
}

static void display_arg(const strace_t *this, const ullong_t reg, const char c)
{
    char *arg;

    switch (c) {
        case 's':
            arg = display_string(this, reg);
            break;
        case 'p':
            arg = display_pointer(reg);
            break;
        case 'i':
            arg = display_integer(reg);
            break;
        default: return;
    }
    fprintf(stderr, "%s", arg);
    free(arg);
}

void display_trace(const strace_t *this, const regs_t regs)
{
    ullong_t registers[] = {regs.rdi, regs.rsi, regs.rdx, regs.r10,
                            regs.r9, regs.r8};
    const size_t params_len = strlen(SYSCALL_PARAMS[regs.orig_rax].params);


    fprintf(stderr, "%s(", SYSCALL_NAMES[regs.orig_rax]);
    for (uint i = 0; i < params_len; ++i) {
        if (!this->verbose && SYSCALL_PARAMS[regs.orig_rax].params[i] != 'v')
            fprintf(stderr, "0x%llx", registers[i]);
        else if (this->verbose) {
            display_arg(this, registers[i],
                SYSCALL_PARAMS[regs.orig_rax].params[i]);
        }
        if ((i + 1) != params_len)
            fprintf(stderr, ", ");
    }
    dislay_rtn_value(this, regs);
}
