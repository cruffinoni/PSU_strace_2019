/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strace.h"

char *display_integer(const ullong_t reg)
{
    char *string = malloc(50);

    if (string == NULL)
        return (NULL);
    sprintf(string, "%lli", reg);
    return (string);
}
