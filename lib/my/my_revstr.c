/*
** EPITECH PROJECT, 2023
** CPoolDay07
** File description:
** ./my_revstr.c
*/

#include "lib.h"

char *my_revstr(char *str)
{
    int i;
    char swap;

    for (i = 0; str[i] != '\0'; i++);
    for (int j = 0; j < i / 2; j++) {
        swap = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = swap;
    }
    return str;
}
