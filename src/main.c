/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <sys/types.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <sys/user.h>

#include "strace.h"
#include "sysname.h"

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
            printf("Old rax: %llx\n", regs.rax);
            ptrace(PTRACE_GETREGS, child, NULL, &regs); // PTRACE_SYSCALL
            //if (regs.rax == (ullong_t) -38)
            //    continue; // SYSCALL_NAMES[regs.orig_rax]
            printf("[%llu] -> ? (%llx, 0x%llx, 0x%llx) = 0x%llx (= %lli)\n",
            regs.orig_rax, regs.rdi, regs.rsi, regs.rdx, regs.rax, regs.rax);
            if (regs.orig_rax == 1) {
                char *str = (char *) regs.rsi;
                printf("write(%llu, ", regs.rdi);
                //for (ullong_t i = 0; i < regs.rax; i++) {
                //    if (str[i] < 97 || str[i] > 122)
                //        printf("%u", str[i]);
                //    else
                //        printf("%c", str[i]);
                //}
                printf("%llu) = %llu\n", regs.rdx, regs.rax);
            }
            ptrace(PTRACE_SINGLESTEP, child, NULL, NULL);
        }
        printf("+++ exit with status %u +++\n", WEXITSTATUS(status));
    }
}
