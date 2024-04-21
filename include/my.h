/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-savinien.petitjean
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include "../lib/my/lib.h"
    #include "CSFML.h"

int check_args(int, char *argv[]);
void run_csfml(csfml *, sfText *, int *);
void print_usage(void);
void initialize_and_run_simulation(csfml *, sfText *, int *, int);
void handle_window_events(sfEvent, csfml **, int *, int);
#endif //MY_H_
