/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** map.c
*/

#include <string.h>
#include <SFML/Graphics.h>
#include "../include/map.h"
#include "../include/my.h"

sfSprite* load_map(char *filepath)
{
    sfSprite* sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(filepath, NULL);

    if (!texture)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void draw_map(sfRenderWindow* window, sfSprite* map)
{
    if (map != NULL)
        sfRenderWindow_drawSprite(window, map, NULL);
}

void unload_map(sfSprite* map)
{
    const sfTexture* texture = sfSprite_getTexture(map);

    sfSprite_destroy(map);
    sfTexture_destroy((sfTexture*)texture);
}
