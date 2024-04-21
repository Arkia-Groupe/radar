/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet (V4 marche pas)
** File description:
** window.h
*/

#ifndef WINDOW_H
    #define WINDOW_H

    #include <SFML/Graphics.h>
    #include "simulation.h"
    #include "map.h"
    #include "init_CSFML.h"
    #include "script.h"
    #include "ControlTower.h"
    #include "aircraft.h"

void draw_aircraft(csfml *csfml, int i);
void update_and_draw_aircrafts(csfml *csfml, float deltaTime);
void draw_towers(csfml *csfml);
void update_and_draw(SimulationData simData);
void draw_aircraft_hitbox(csfml *csfml, int i);
void handle_aircraft_interactions(int i, float deltaTime);
void draw_tower_radius(csfml* csfml, int i);
void update_timer(sfRenderWindow *window, sfText *timerText, float elapsed_time);

#endif
