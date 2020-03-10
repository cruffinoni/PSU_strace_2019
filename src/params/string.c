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

static char *retrieve_string(const ullong_t src, const pid_t child)
{
    char *str = NULL;
    char c = 0;
    uint i = 0;
    uint k = 0;

    for (k = 0; str == NULL || c != '\0'; i++, k++) {
        str = realloc(str, k + 1);
        if (str == NULL)
            return (NULL);
        c = (char) ptrace(PTRACE_PEEKTEXT, child, src + i, NULL);
        if (IS_PRINTABLE(c))
            str[k] = c;
        else if (c != 0) {
            str = realloc(str, k + 1);
            if (str == NULL)
                return (NULL);
            str[k++] = '\\';
            str[k] = 'n';
        }
    }
    //fprintf(stderr, "[[k: %i]]", k);
    str[k - 1] = '\0';
    //printf("total size: %i = '%s'\n", i, str);
    return (str);
}

char *display_string(const strace_t *this, const ullong_t reg)
{
    char *string;
    char *tmp;

    if (reg == 0)
        return (strdup("NULL"));
    tmp = retrieve_string(reg, this->child);
    string = malloc(sizeof(char) * (strlen(tmp) + 2));
    if (string == NULL) {
        free(tmp);
        return (NULL);
    }
    sprintf(string, "\"%s\"", tmp);
    //free(tmp);
    return (string);
}
