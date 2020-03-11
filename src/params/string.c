/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include "strace.h"

// hello\n world
// hello world\n

static size_t get_src_len(const ullong_t src, const pid_t child)
{
    size_t size = 0;
    char c = (char) ptrace(PTRACE_PEEKTEXT, child, src + size, NULL);

    for (size = 1; c != 0; size++)
        c = (char) ptrace(PTRACE_PEEKTEXT, child, src + size, NULL);
    return (size);
}

static char *retrieve_string(const ullong_t src, const pid_t child)
{
    size_t len = get_src_len(src, child);
    char *str = malloc(sizeof(char) * (len + 1));
    char c;

    memset(str, '\0', len);
    if (str == NULL)
        return (NULL);
    for (uint i = 0, k = 0; i < len; i++, k++) {
        c = (char) ptrace(PTRACE_PEEKTEXT, child, src + i, NULL);
        if (IS_PRINTABLE(c))
            str[k] = c;
        else if (c != 0) {
            str = realloc(str, ++len);
            if (str == NULL)
                return (NULL);
            str[len - 1] = '\0';
            str[k++] = '\\';
            str[k] = 'n';
        }
    }
    return (str);
}

char *display_string(const strace_t *this, const ullong_t reg)
{
    char *string;
    char *tmp;

    if (reg == 0)
        return (strdup("NULL"));
    tmp = retrieve_string(reg, this->child);
    string = malloc(sizeof(char) * (strlen(tmp) + 3));
    if (string == NULL) {
        free(tmp);
        return (NULL);
    }
    sprintf(string, "\"%s\"", tmp);
    free(tmp);
    return (string);
}
