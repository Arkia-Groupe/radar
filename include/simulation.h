/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** simulation.h
*/

#ifndef SIMULATION_H
    #define SIMULATION_H

    #include <SFML/Graphics.h>
    #include "script.h"
    #include "CSFML.h"

typedef struct {
    csfml* csfml;
    sfText* timerText;
    int* should_close;
    float deltaTime;
    float elapsed_time;
} SimulationData;
int init_simulation(char *script_filepath);
void init_run_sim(csfml *csfml, sfText* timerText, int *should_close);
void run_simulation(csfml* csfml, sfText *timerText, int *should_close);
void run_simulation_loop(SimulationData simData, csfml *csfml);
void check_end_simulation(csfml *csfml);
void end_simulation(csfml *csfml, sfSprite*);

#endif
