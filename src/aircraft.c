/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** aircraft.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include <math.h>
#include "../include/my.h"

void configure_aircraft_sprite(Aircraft *aircraft)
{
    sfTexture* texture;
    sfVector2u spriteSize;

    aircraft->sprite = sfSprite_create();
    texture = sfTexture_createFromFile("resources/img/plane.png", NULL);
    sfSprite_setTexture(aircraft->sprite, texture, sfTrue);
    spriteSize = sfTexture_getSize(texture);
    sfSprite_setOrigin(aircraft->sprite,
    (sfVector2f){spriteSize.x / 2, spriteSize.y / 2});
    sfSprite_setScale(aircraft->sprite, (sfVector2f){0.10, 0.10});
}

void calculate_aircraft_direction(Aircraft *aircraft)
{
    sfVector2f diff;
    float length;

    diff = (sfVector2f){aircraft->dest.x - aircraft->pos.x,
    aircraft->dest.y - aircraft->pos.y};
    length = sqrt(diff.x * diff.x + diff.y * diff.y);
    aircraft->direction = (sfVector2f){diff.x / length, diff.y / length};
    aircraft->speed *= 10;
}

void process_aircraft_line(char *line)
{
    Aircraft* new_aircrafts;

    new_aircrafts = malloc((num_aircrafts + 1) * sizeof(Aircraft));
    if (aircrafts != NULL) {
        memcpy(new_aircrafts, aircrafts, num_aircrafts * sizeof(Aircraft));
        (aircrafts);
    }
    aircrafts = new_aircrafts;
    sscanf(line, "A %f %f %f %f %d %d", &aircrafts[num_aircrafts].pos.x,
    &aircrafts[num_aircrafts].pos.y,
    &aircrafts[num_aircrafts].dest.x, &aircrafts[num_aircrafts].dest.y,
    &aircrafts[num_aircrafts].speed, &aircrafts[num_aircrafts].delay);
    configure_aircraft_sprite(&aircrafts[num_aircrafts]);
    calculate_aircraft_direction(&aircrafts[num_aircrafts]);
    num_aircrafts++;
}

void draw_aircraft_hitbox(csfml *csfml, int i)
{
    sfRectangleShape* hitbox = sfRectangleShape_create();
    sfVector2f hitboxPos = {aircrafts[i].pos.x - 10, aircrafts[i].pos.y - 10};

    sfRectangleShape_setPosition(hitbox, hitboxPos);
    sfRectangleShape_setSize(hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 1.0);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRenderWindow_drawRectangleShape(csfml->window, hitbox, NULL);
    sfRectangleShape_destroy(hitbox);
}
