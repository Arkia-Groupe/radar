/*
** EPITECH PROJECT, 2023
** CPoolDay07
** File description:
** ./my_putstr.c
*/

#include "lib.h"

int my_puterr(char const *str)
{
    int count;

    count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
        count++;
    }
    return (count);
}
