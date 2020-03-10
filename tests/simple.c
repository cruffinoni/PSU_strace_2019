/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int a = 0;

    printf("my pid: %u\n", getpid());
    while (a++ < 3) {
        write(1, "hello world\n", 12);
        sleep(10);
    }
    //_exit(32);
    return (0);
}
