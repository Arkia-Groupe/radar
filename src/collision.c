/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** collision.c
*/

#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include <math.h>
#include "../include/events.h"
#include "../include/my.h"

void handle_aircraft_collision(int i, int j)
{
    if (!is_in_control_area(i) && !is_in_control_area(j)) {
        /*my_printf(
        "Collision detected between aircraft %d and %d\n", i, j);*/
        if (i < j) {
            destroy_aircraft(i);
            destroy_aircraft(j - 1);
        } else {
            destroy_aircraft(j);
            destroy_aircraft(i - 1);
        }
        //my_printf("Nombre d'avions après collision : %d\n", num_aircrafts);
    }
}

void handle_aircraft_landing(int i, float deltaTime)
{
    float distance;

    distance = babylonian_sqrt(pow(aircrafts[i].pos.x
    - aircrafts[i].dest.x, 2) +
    pow(aircrafts[i].pos.y - aircrafts[i].dest.y, 2));
    if (distance <= aircrafts[i].speed * deltaTime) {
        sfSprite_destroy(aircrafts[i].sprite);
        aircrafts[i].sprite = NULL;
        for (int j = i; j < num_aircrafts - 1; j++)
            aircrafts[j] = aircrafts[j + 1];
        num_aircrafts--;
        num_landed_aircrafts++;
        //my_printf("Nombre d'avions après atterrissage : %d\n", num_aircrafts);
    } else {
        aircrafts[i].pos.x += aircrafts[i].direction.x *
        aircrafts[i].speed * deltaTime;
        aircrafts[i].pos.y += aircrafts[i].direction.y *
        aircrafts[i].speed * deltaTime;
    }
}

void draw_hitbox(csfml *csfml, int i)
{
    sfRectangleShape* hitbox = sfRectangleShape_create();
    sfVector2f hitboxPos = {
        aircrafts[i].pos.x - 10,
        aircrafts[i].pos.y - 10
    };

    sfRectangleShape_setPosition(hitbox, hitboxPos);
    sfRectangleShape_setSize(hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 1.0);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRenderWindow_drawRectangleShape(csfml->window, hitbox, NULL);
    sfRectangleShape_destroy(hitbox);
}

void destroy_aircraft(int i)
{
    sfSprite_destroy(aircrafts[i].sprite);
    aircrafts[i].sprite = NULL;
    for (int j = i; j < num_aircrafts - 1; j++) {
        aircrafts[j] = aircrafts[j + 1];
    }
    num_aircrafts--;
    num_destroyed_aircrafts++;
}
