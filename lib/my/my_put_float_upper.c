/*
** EPITECH PROJECT, 2023
** my_put_float_upper
** File description:
** ./my_put_float_upper.c
*/

#include "lib.h"

int my_put_float_upper(float nb)
{
    int x = 0;
    int entier = nb;
    int precision = 6;
    int decimal[precision];
    int b = 10;
    int tt;

    for (int i = 0; i < precision; i++) {
        tt = (int)(nb * b);
        decimal[i] = tt % 10;
        b = b * 10;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        entier = nb;
    }
    my_put_float2_upper(decimal, x, precision, entier);
    return (0);
}

void my_put_float2_upper(
    int *decimal,
    int x,
    int precision,
    int entier
)
{
    x += my_put_nbr(entier);
    my_putchar('.');
    x++;
    for (int i = 0; i < precision; i++) {
        if (decimal[i] != 0)
            x += my_put_nbr(decimal[i]);
    }
}
