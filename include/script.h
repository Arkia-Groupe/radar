/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** script.h
*/

#ifndef SCRIPT_H
    #define SCRIPT_H

    #include <SFML/Graphics.h>
    #include "simulation.h"
    #include "aircraft.h"
    #include "ControlTower.h"
    #include "init_CSFML.h"

extern Aircraft* aircrafts;
extern ControlTower* towers;
extern int num_aircrafts;
extern int num_towers;
extern int num_landed_aircrafts;
extern int num_destroyed_aircrafts;

void handle_event(sfEvent event, csfml **csfml, int *should_close);
int read_script(char *filepath);

#endif
