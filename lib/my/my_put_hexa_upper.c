/*
** EPITECH PROJECT, 2023
** my_put_hexa_upper
** File description:
** ./my_put_hexa_upper.c
*/

#include "lib.h"

int my_put_hexa_upper(int nb)
{
    int result = nb;

    while (nb != 0) {
        result = nb % 16;
        if (result < 10) {
            my_putchar(result + 48);
        } else {
            my_putchar(result + 5);
        }
        nb = nb / 16;
    }
    return (0);
}
