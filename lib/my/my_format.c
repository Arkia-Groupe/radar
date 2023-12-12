/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** ./my_format.c
*/

#include <stdarg.h>
#include "lib.h"

int my_format(const char *format, int i, va_list list)
{
    int count = 1;

    switch (format[i + 1]) {
        case '%':
            my_putchar('%');
            break;
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        case 'i' :
        case 'd' :
        case 'n' :
            count = my_put_nbr(va_arg(list, int));
            break;
        default:
            return (my_format2(format, i, list));
    }
    return (count);
}

int my_format2(const char *format, int i, va_list list)
{
    int count = 1;

    switch (format[i + 1]) {
        case 'u':
            count = my_put_unsigned_nbr(va_arg(list, unsigned int));
            break;
        case 'o':
            count = my_put_octal(va_arg(list, unsigned int));
            break;
        case 'f':
            count = my_put_float(va_arg(list, double));
            break;
        case 's':
            count = my_putstr(va_arg(list, char *));
            break;
        default:
            return -42;
    }
    return (count);
}

int my_format3(const char *format, int i, va_list list)
{
    int count = 1;

    switch (format[i + 1]) {
        case 'F':
            count = my_put_float_upper(va_arg(list, double));
            break;
        default:
            return -42;
    }
    return (count);
}
