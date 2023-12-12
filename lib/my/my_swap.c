/*
** EPITECH PROJECT, 2023
** CPoolDay07
** File description:
** ./my_swap.c
*/

#include "lib.h"

int my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
    return (0);
}
