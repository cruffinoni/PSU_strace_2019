/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strace.h"

static void free_strace(strace_t *this)
{
    if (this->process_name != NULL)
        free(this->process_name);
    free(this);
}

static error_t get_pid(strace_t *this, const char *arg)
{
    char *endptr = NULL;

    if (arg == NULL)
        return (ERR_NO_PID_PROVIDED);
    this->child = strtol(arg, &endptr, 10);
    if (strlen(endptr) != 0)
        return (ERR_INVALID_NUMBER_PID);
    if (this->child <= 0 || kill(this->child, 0) != 0)
        return (ERR_INVALID_PID);
    return (ERR_NONE);
}

static error_t create_child(strace_t *this, const char *process_name)
{
    if (this->process_name != NULL) {
        fprintf(stderr, "Process '%s' ignored "
        "since already one have been taken in count.\n", process_name);
        return (ERR_NONE);
    }
    this->process_name = strdup(process_name);
    return (this->process_name == NULL ? ERR_MALLOC : ERR_NONE);
}

static error_t get_flags(strace_t *this, const char **av)
{
    error_t err = ERR_NONE;

    this->verbose = 0;
    this->child = 0;
    this->process_name = NULL;
    for (uint i = 1; av[i] != NULL; ++i) {
        if (IS_FLAG(av, i, 's'))
            this->verbose = 1;
        else if (IS_FLAG(av, i, 'p'))
            err = get_pid(this, av[i + 1]);
        else
            create_child(this, av[i]);
        if (err != ERR_NONE)
            return (err);
    }
    if (this->process_name == NULL && this->child == 0)
        return (ERR_MISSING_PARAM);
    return (ERR_NONE);
}

int main(const int ac, const char **av)
{
    strace_t *this;
    error_t err;

    if (ac == 1)
        return (display_err(ERR_MISSING_PARAM));
    this = malloc(sizeof(strace_t));
    if (this == NULL)
        return (display_err(ERR_MALLOC));
    if ((err = get_flags(this, av)) != ERR_NONE) {
        free_strace(this);
        return (display_err(err));
    }
    if ((err = execute_child(this)) != ERR_NONE) {
        free_strace(this);
        return (display_err(err));
    }
    free_strace(this);
    return (ERR_NONE);
}
