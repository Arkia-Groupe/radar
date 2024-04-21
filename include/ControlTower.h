/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** ControlTower.h
*/

#ifndef CONTROLTOWER_H
    #define CONTROLTOWER_H

    #include <SFML/Graphics.h>

typedef struct {
    sfVector2f pos;
    sfSprite* sprite;
    int radius;
} ControlTower;
void process_tower_line(char *line);
int is_in_control_area(int i);
float babylonian_sqrt(float number);

#endif
