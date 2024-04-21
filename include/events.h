/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** events.h
*/


#ifndef EVENTS_H
    #define EVENTS_H

    #include <SFML/Graphics.h>
    #include "simulation.h"
    #include "map.h"
    #include "init_CSFML.h"
    #include "script.h"
    #include "ControlTower.h"
    #include "aircraft.h"

void handle_window_events_simulation(csfml *csfml, int *should_close);
float babylonian_sqrt(float num);


#endif
