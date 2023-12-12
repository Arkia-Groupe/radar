/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-bsmyls-savinien.petitjean
** File description:
** ./my_strcmp.c
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return s1[i] - s2[i];
}
