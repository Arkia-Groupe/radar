/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** aircraft.h
*/

#ifndef AIRCRAFT_H
    #define AIRCRAFT_H

    #include <SFML/Graphics.h>

typedef struct {
    sfVector2f pos;
    sfVector2f dest;
    sfVector2f direction;
    sfSprite* sprite;
    int speed;
    int delay;
} Aircraft;
void configure_aircraft_sprite(Aircraft *aircraft);
void process_aircraft_line(char *line);
void destroy_aircraft(int i);

#endif
