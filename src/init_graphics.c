/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-savinien.petitjean
** File description:
** init_csfml.c
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "../include/map.h"
#include "init_CSFML.h"
#include "../include/my.h"

csfml* create_csfml(void)
{
    csfml* csfml = malloc(sizeof(csfml));

    if (!csfml) {
        my_printf("Failed to allocate memory for csfml\n");
    }
    return csfml;
}

sfRenderWindow* create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode,
        "Air Traffic Simulation", sfResize | sfClose, NULL);

    return window;
}

sfSprite* load_map_sprite(char *map_filepath, sfRenderWindow* window)
{
    sfSprite* map = load_map(map_filepath);

    if (!map) {
        sfRenderWindow_destroy(window);
    }
    return map;
}

void set_map_scale(sfSprite* map, sfRenderWindow* window)
{
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    sfFloatRect mapBounds = sfSprite_getLocalBounds(map);
    sfSprite_setScale(map, (sfVector2f){windowSize.x /
    mapBounds.width, windowSize.y / mapBounds.height});
}

void set_window_framerate(sfRenderWindow* window)
{
    sfRenderWindow_setFramerateLimit(window, 60);
}

csfml* init_csfml(char *map_filepath)
{
    csfml* csfml = create_csfml();

    if (!csfml) {
        return NULL;
    }
    csfml->window = create_window();
    if (!csfml->window) {
        (csfml);
        return NULL;
    }
    csfml->map = load_map_sprite(map_filepath, csfml->window);
    if (!csfml->map) {
        sfRenderWindow_destroy(csfml->window);
        (csfml);
        return NULL;
    }
    set_map_scale(csfml->map, csfml->window);
    set_window_framerate(csfml->window);
    return csfml;
}
