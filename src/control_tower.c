/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** control_tower.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/my.h"


void process_tower_line(char *line)
{
    sfTexture* texture;
    ControlTower* new_towers;

    new_towers = malloc((num_towers + 1) * sizeof(ControlTower));
    if (towers != NULL) {
        memcpy(new_towers, towers, num_towers * sizeof(ControlTower));
        (towers);
    }
    towers = new_towers;
    sscanf(line, "T %f %f %d", &towers[num_towers].pos.x,
    &towers[num_towers].pos.y, &towers[num_towers].radius);
    towers[num_towers].sprite = sfSprite_create();
    texture = sfTexture_createFromFile("resources/img/tower.png", NULL);
    sfSprite_setTexture(towers[num_towers].sprite, texture, sfTrue);
    sfSprite_setScale(towers[num_towers].sprite, (sfVector2f){0.10, 0.10});
    sfSprite_setPosition(towers[num_towers].sprite,(sfVector2f){towers[num_towers].pos.x - 25.6, towers[num_towers].pos.y - 25.6});
    num_towers++;
}

int is_in_control_area(int i)
{
    int k;
    float dx;
    float dy;
    float distance;

    for (k = 0; k < num_towers; k++) {
        dx = towers[k].pos.x - aircrafts[i].pos.x;
        dy = towers[k].pos.y - aircrafts[i].pos.y;
        distance = babylonian_sqrt(dx * dx + dy * dy);
        if (distance <= towers[k].radius) {
            return 1;
        }
    }
    return 0;
}

void draw_tower_radius(csfml* csfml, int i)
{
    sfCircleShape* radius = sfCircleShape_create();
    sfVector2f circlePos = {
        towers[i].pos.x - towers[i].radius,
        towers[i].pos.y - towers[i].radius
    };

    sfCircleShape_setPosition(radius, circlePos);
    sfCircleShape_setRadius(radius, towers[i].radius);
    sfCircleShape_setOutlineColor(radius, sfBlue);
    sfCircleShape_setOutlineThickness(radius, 1.0);
    sfCircleShape_setFillColor(radius, sfTransparent);
    sfRenderWindow_drawCircleShape(csfml->window, radius, NULL);
    sfCircleShape_destroy(radius);
}
