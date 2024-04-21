/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** init_csfml.h
*/

#ifndef INIT_csfml_H
    #define INIT_csfml_H

    #include <SFML/Graphics.h>
    #include "CSFML.h"

csfml* create_csfml(void);
sfRenderWindow* create_window(void);
sfSprite* load_map_sprite(char *map_filepath, sfRenderWindow* window);
void set_map_scale(sfSprite* map, sfRenderWindow* window);
void set_window_framerate(sfRenderWindow* window);
csfml* init_csfml(char *map_filepath);

#endif
