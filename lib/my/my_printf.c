/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** ./mini_printf.c
*/

#include <stdarg.h>
#include "lib.h"

int my_printf(const char *format, ...)
{
    va_list list;
    int count = 0;

    if (format == 0)
        return -42;
    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            count += my_format(format, i, list);
            i++;
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(list);
    return count;
}
