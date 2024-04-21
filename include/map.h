/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** map.h
*/

#ifndef MAP_H
    #define MAP_H

    #include <SFML/Graphics.h>

sfSprite* load_map(char *map_filepath);
void unload_map(sfSprite* map);
void draw_map(sfRenderWindow* window, sfSprite* map);

#endif
