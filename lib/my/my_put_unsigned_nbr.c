/*
** EPITECH PROJECT, 2023
** MyPrintf
** File description:
** Outputs a given int.
*/

#include "lib.h"

void my_put_positive(int nb)
{
    if (nb > 9)
        my_put_positive(nb / 10);
    my_putchar(nb % 10 + '0');
}

int my_put_unsigned_nbr(unsigned int nb)
{
    int output = nb;

    if (output < 0) {
        output = -(output / 10);
        my_put_positive(output);
        my_put_positive(-(nb % 10));
    } else
        my_put_positive(output);
    return (0);
}
