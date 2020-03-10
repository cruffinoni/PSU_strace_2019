/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef SRC_ERROR_
#define SRC_ERROR_

typedef unsigned int error_t;

enum error_e {
    ERR_NONE = 0,
    ERR_MALLOC,
    ERR_NO_PID_PROVIDED,
    ERR_INVALID_NUMBER_PID,
    ERR_INVALID_PID,
    ERR_FORBIDDEN_PID,
    ERR_CHILD,
    ERR_MISSING_PARAM,
    ERR_PTRACE,

    ERR_MAX_ERR,
    ERR_EXIT = 84,
};

#endif
