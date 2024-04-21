/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** file_handling.c
*/

#include <stdio.h>
#include "../include/simulation.h"
#include "../include/my.h"

void process_script_line(char *line)
{
    if (line[0] == 'A') {
        process_aircraft_line(line);
    } else if (line[0] == 'T') {
        process_tower_line(line);
    }
}

int read_script(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char line[256];

    if (!file) {
        my_printf("Failed to open the script file: %s\n", filepath);
        return 84;
    }
    while (fgets(line, sizeof(line), file)) {
        process_script_line(line);
    }
    if (ferror(file)) {
        my_printf("Error reading the script file: %s\n", filepath);
        fclose(file);
        return 84;
    }
    fclose(file);
    return 0;
}
