/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <wait.h>
#include <sys/user.h>
#include "strace.h"

static error_t create_argv(const char *process_name, char ***argv)
{
    *argv = malloc(sizeof(char *) * 2);
    if (*argv == NULL)
        return (ERR_MALLOC);
    (*argv)[0] = strdup(process_name);
    if ((*argv)[0] == NULL)
        return (ERR_MALLOC);
    return (ERR_NONE);
}

static illong_t get_rtn_value(const struct user_regs_struct regs,
    const pid_t child)
{
    illong_t rtn = ptrace(PTRACE_PEEKTEXT, child, regs.rax, NULL);

    if ((illong_t) regs.rax < 0)
        return (rtn);
    return ((ullong_t) regs.rax);
}

static error_t trace_child(strace_t *this)
{
    int status = 0;
    struct user_regs_struct regs;

    while (waitpid(this->child, &status, 0) && !WIFEXITED(status)) {
        ptrace(PTRACE_GETREGS, this->child, NULL, &regs);
        if (IS_SYSCALL(regs.orig_rax)) {
            //printf(
            //    "[%llu] -> '%s' (0x%llx, 0x%llx, 0x%llx) = 0x%llx (= %lli)\n",
            //    regs.orig_rax, SYSCALL_NAMES[regs.orig_rax], regs.rdi,
            //    regs.rsi, regs.rdx, regs.rax,
            //    get_rtn_value(regs, this->child));
            fprintf(stderr,"%s(0x%llx, 0x%llx, 0x%llx) = 0x%llx\n",
                SYSCALL_NAMES[regs.orig_rax], regs.rdi, regs.rsi, regs.rdx,
                regs.rax);
        }
        ptrace(PTRACE_SINGLESTEP, this->child, NULL, NULL);
    }
    this->child_exit = WEXITSTATUS(status);
    printf("exit_group(%u)\n", this->child_exit);
    printf("+++ exited with %u +++\n", this->child_exit);
    ptrace(PTRACE_DETACH, this->child, NULL, NULL);
    return (ERR_NONE);
}

error_t execute_child(strace_t *this)
{
    char **av;
    error_t err;

    if (this->child != 0) {
        if (ptrace(PTRACE_ATTACH, this->child, NULL, NULL) == -1) {
            perror("ptrace");
            return (ERR_PTRACE);
        }
        printf("attached to: %u\n", this->child);
        return (trace_child(this));
    }
    this->child = fork();
    if (this->child == -1)
        return (ERR_CHILD);
    if (this->child == 0) {
        err = create_argv(this->process_name, &av);
        if (err != ERR_NONE)
            return (err);
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execv(this->process_name, av);
        return (ERR_NONE);
    } else
        return (trace_child(this));
}
