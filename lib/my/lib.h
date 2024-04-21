/*
** EPITECH PROJECT, 2023
** Lib/My
** File description:
** ./lib/my/lib.h
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stdarg.h>
    #include <stdlib.h>
    #include <unistd.h>
int my_printf(const char *, ...);
int my_format(const char *, int, va_list);
int my_format2(const char *, int, va_list);
int my_format3(const char *, int, va_list);
int my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
int my_put_unsigned_nbr(unsigned int);
int my_put_hexa(int);
int my_put_address(int);
int my_put_hexa_upper(int);
int my_put_octal(int);
int my_swap(int *, int *);
int my_put_float(float);
int my_put_float_upper(float);
void my_put_float2(int *, int, int, int);
void my_put_float2_upper(int *, int, int, int);
int my_putstr(char const *);
int my_puterr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
int my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char my_strstr(char const *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
int my_show_word_array(char *const *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
char *my_strpop(char *, int);
#endif /* LIB_H_ */
