/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

static const char *ERR_NAMES[] = {
    "None",
    "Malloc failed", "No pid provided with -p flag",
    "Invalid pid number provided", "Invalid pid provided", "Illegal pid",
    "Unable to fork and execute child program",
    "You have to enter a process name to execute or you should use the -p flag",
    "Invalid",
};

error_t display_err(const error_t error)
{
    if (error > ERR_MAX_ERR || error == ERR_PTRACE)
        return (ERR_EXIT);
    fprintf(stderr, "strace: %s\n", ERR_NAMES[error]);
    return (ERR_EXIT);
}

error_t create_argv(const char *process_name, char ***argv)
{
    *argv = malloc(sizeof(char *) * 2);
    if (*argv == NULL)
        return (ERR_MALLOC);
    (*argv)[0] = strdup(process_name);
    if ((*argv)[0] == NULL)
        return (ERR_MALLOC);
    (*argv)[1] = NULL;
    return (ERR_NONE);
}
