/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** simulation2.c
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/map.h"
#include "../include/my.h"

extern Aircraft* aircrafts;
extern ControlTower* towers;
extern int num_aircrafts;
extern int num_towers;
extern int num_landed_aircrafts;
extern int num_destroyed_aircrafts;
extern int show_hitboxes;
float babylonian_sqrt(float num);

void check_end_simulation(csfml *csfml)
{
    if (num_aircrafts == 0) {
        my_printf("Nombre d'avions atterris : %d\n", num_landed_aircrafts);
        my_printf("Nombre d'avions détruits : %d\n", num_destroyed_aircrafts);
        if (csfml && csfml->window && sfRenderWindow_isOpen(csfml->window)) {
            sfRenderWindow_close(csfml->window);
        }
    }
}

void end_simulation(csfml *csfml, sfSprite*)
{
    for (int i = 0; i < num_aircrafts; i++) {
        sfSprite_destroy(aircrafts[i].sprite);
        aircrafts[i].sprite = NULL;
    }
    (aircrafts);
    for (int i = 0; i < num_towers; i++) {
        sfSprite_destroy(towers[i].sprite);
        towers[i].sprite = NULL;
    }
    (towers);
    unload_map(csfml->map);
}