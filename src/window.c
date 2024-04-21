/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** window.c
*/

#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/map.h"
#include <math.h>
#include "../include/window.h"
#include "../include/my.h"

extern int show_hitboxes;

void draw_aircraft(csfml *csfml, int i)
{
    float angle;

    if (aircrafts[i].sprite != NULL) {
        sfSprite_setPosition(aircrafts[i].sprite, aircrafts[i].pos);
        angle = atan2(aircrafts[i].direction.y,
        aircrafts[i].direction.x) * 180 / M_PI;
        sfSprite_setRotation(aircrafts[i].sprite, angle);
        sfRenderWindow_drawSprite(csfml->window, aircrafts[i].sprite, NULL);
    }
    if (show_hitboxes) {
        draw_aircraft_hitbox(csfml, i);
    }
}

void update_and_draw_aircrafts(csfml *csfml, float deltaTime)
{
    for (int i = 0; i < num_aircrafts; i++) {
        handle_aircraft_interactions(i, deltaTime);
        draw_aircraft(csfml, i);
    }
}

void draw_towers(csfml *csfml)
{
    for (int i = 0; i < num_towers; i++) {
        if (towers[i].sprite != NULL) {
            sfRenderWindow_drawSprite(csfml->window, towers[i].sprite, NULL);
        }
        if (show_hitboxes) {
            draw_tower_radius(csfml, i);
        }
    }
}

void update_and_draw(SimulationData simData)
{
    sfRenderWindow_clear(simData.csfml->window, sfBlack);
    draw_map(simData.csfml->window, simData.csfml->map);
    update_timer(simData.csfml->window, simData.timerText,
    simData.elapsed_time);
    update_and_draw_aircrafts(simData.csfml, simData.deltaTime);
    draw_towers(simData.csfml);
    check_end_simulation(simData.csfml);
    if (!simData.csfml || !simData.csfml->window ||
    !sfRenderWindow_isOpen(simData.csfml->window) || *simData.should_close)
        return;
    sfRenderWindow_display(simData.csfml->window);
}