/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdlib.h>
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

char *display_string(const struct user_regs_struct regs,
    const pid_t child)
{

}
