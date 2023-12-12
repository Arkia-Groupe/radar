/*
** EPITECH PROJECT, 2023
** CPoolDay07
** File description:
** ./my_putchar.c
*/

#include "lib.h"

int my_putchar(char a)
{
    write(1, &a, 1);
    return (0);
}
