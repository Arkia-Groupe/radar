/*
** EPITECH PROJECT, 2023
** my_put_octal
** File description:
** ./my_put_octal.c
*/

#include "lib.h"

int my_put_octal(int nb)
{
    int result = nb;

    while (nb != 0) {
        result = nb % 8;
        my_putchar(result + 48);
        nb = nb / 8;
    }
    return (0);
}
