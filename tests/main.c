/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <sys/user.h>

#include "strace.h"

char *retrieve_string(const ullong_t src, const pid_t child)
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

long int get_rtn_value(const struct user_regs_struct regs, const pid_t child)
{
    return ((long int) ptrace(PTRACE_PEEKTEXT, child, regs.rax, NULL));
}

int main(int ac, char **av)
{
    pid_t child = fork();
    int status = 0;

    if (child == -1) {
        printf("Child creation failed\n");
        return (84);
    }
    printf("Current pid: %u\n", child);
    //        long ptrace(enum __ptrace_request request, pid_t pid,
    //                   void *addr, void *data);
    if (child == 0) {
        //printf("[%u] You can trace me\n", child);
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execv("./simple", av);
    } else {
        while (waitpid(child, &status, 0) && !WIFEXITED(status)) {
            struct user_regs_struct regs;
            //printf("Old rax: %llx\n", regs.rax);
            ptrace(PTRACE_GETREGS, child, NULL, &regs);
            //if (regs.rax == (ullong_t) -38)
            //    continue; // SYSCALL_NAMES[regs.orig_rax]
            //u_long a = ptrace(PTRACE_PEEKTEXT, child, regs.rip, NULL);
            //printf("RIP: 0x%lx\n", a, a & (0xFF));
            if (IS_SYSCALL(regs.orig_rax))  {
                printf("[%llu] -> '%s' (0x%llx, 0x%llx, 0x%llx) = 0x%llx (= %li)\n",
                       regs.orig_rax, SYSCALL_NAMES[regs.orig_rax], regs.rdi, regs.rsi, regs.rdx, regs.rax, get_rtn_value(regs, child));
                //if ((illong_t) regs.rax < 0) {
                //    u_long rtn = ptrace(PTRACE_PEEKTEXT, child, regs.rax, NULL);
                //    printf("rtn: %li\n", (long int) rtn);
                //}
            }
            if (regs.orig_rax == 1) {
                printf("write(?, '%s', ?);\n", retrieve_string(regs.rsi, child));
            }
            /*if (regs.orig_rax == 1) {
                char *str = (char *) regs.rsi;
                printf("write(%llu, ", regs.rdi);
                //for (ullong_t i = 0; i < regs.rax; i++) {
                //    if (str[i] < 97 || str[i] > 122)
                //        printf("%u", str[i]);
                //    else
                //        printf("%c", str[i]);
                //}
                printf("%llu) = %llu\n", regs.rdx, regs.rax);
            }*/
            ptrace(PTRACE_SINGLESTEP, child, NULL, NULL); // PTRACE_SYSCALL
        }
        printf("exit_group(%u)\n", WEXITSTATUS(status));
        printf("+++ exited with %u +++\n", WEXITSTATUS(status));
        return (WEXITSTATUS(status));
    }
}
