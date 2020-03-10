/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdio.h>
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
    if (error > ERR_MAX_ERR)
        return (ERR_EXIT);
    if (error == ERR_PTRACE)
        return (ERR_EXIT);
    fprintf(stderr, "strace: %s\n", ERR_NAMES[error]);
    return (ERR_EXIT);
}


