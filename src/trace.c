/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <wait.h>
#include <sys/user.h>
#include "strace.h"

static error_t trace_child(strace_t *this)
{
    int status = 0;
    struct user_regs_struct regs;

    while (waitpid(this->child, &status, 0) && !WIFEXITED(status)) {
        ptrace(PTRACE_GETREGS, this->child, NULL, &regs);
        if (IS_SYSCALL(regs.orig_rax))
            display_trace(this, regs);
        ptrace(PTRACE_SINGLESTEP, this->child, NULL, NULL);
    }
    this->child_exit = WEXITSTATUS(status);
    fprintf(stderr, "exit_group(%u) = ?\n", this->child_exit);
    fprintf(stderr, "+++ exited with %u +++\n", this->child_exit);
    ptrace(PTRACE_DETACH, this->child, NULL, NULL);
    return (ERR_NONE);
}

static error_t create_child(strace_t *this)
{
    char **av;
    error_t err;

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

error_t execute_child(strace_t *this)
{
    if (this->child != 0) {
        if (ptrace(PTRACE_ATTACH, this->child, NULL, NULL) == -1) {
            perror("ptrace");
            return (ERR_PTRACE);
        }
        return (trace_child(this));
    }
    return (create_child(this));
}
