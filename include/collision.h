/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** collision.h
*/

#ifndef COLLISION_H
    #define COLLISION_H

    #include <SFML/Graphics.h>
    #include "simulation.h"
    #include "map.h"
    #include "init_CSFML.h"
    #include "script.h"
    #include "../lib/my/lib.h"
    #include "ControlTower.h"
    #include "aircraft.h"

void handle_aircraft_collision(int i, int j);
void handle_aircraft_landing(int i, float deltaTime);
void draw_hitbox(csfml *csfml, int i);
void destroy_aircraft(int i);
int is_in_control_area(int i);
void destroy_aircraft(int i);

#endif
