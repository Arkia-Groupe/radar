/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-savinien.petitjean
** File description:
** print_usages.c
*/

#include "../../include/radar.h"

void print_usages(void)
{
    my_putstr("USAGE\n");
    my_putstr("        ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("path_to_script The path to the script file.\n");
    my_putstr("        OPTIONS\n");
    my_putstr("                                      -h print the usage and quit.\n");
    my_putstr("        USER INTERACTIONS\n");
    my_putstr("‘L’ key enable/disable hitboxes and areas.\n");
    my_putstr("‘S’ key enable/disable sprites.\n");
}
