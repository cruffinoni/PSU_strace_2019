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

char *display_pointer(const ullong_t reg)
{
    char *string;

    if (reg == 0x0)
        return (strdup("NULL"));
    string = malloc(50);
    sprintf(string, "0x%llx", reg);
    return (string);
}
