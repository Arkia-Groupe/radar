/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** simulation.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/map.h"
#include "../include/init_CSFML.h"
#include "../include/script.h"
#include "../include/ControlTower.h"
#include "../include/aircraft.h"
#include "../include/window.h"
#include "../include/events.h"
#include "../include/my.h"

extern Aircraft* aircrafts;
extern ControlTower* towers;
extern int num_aircrafts;
extern int num_towers;
extern int num_landed_aircrafts;
extern int num_destroyed_aircrafts;
extern int show_hitboxes;
float babylonian_sqrt(float num);

int init_simulation(char *script_filepath)
{
    if (read_script(script_filepath) != 0) {
        my_printf( "Failed to read the script file: %s\n",
        script_filepath);
        return 84;
    }
    return 0;
}

void init_run_sim(csfml *csfml, sfText* timerText, int *should_close)
{
    SimulationData simData;

    simData.csfml = csfml;
    simData.timerText = timerText;
    simData.should_close = should_close;
    run_simulation_loop(simData, csfml);
}

void run_simulation(csfml* csfml, sfText *timerText, int *should_close)
{
    if (!csfml || !csfml->window) {
        my_printf( "Failed to initialize csfml\n");
        return;
    }
    init_run_sim(csfml, timerText, should_close);
    if (csfml) {
        sfText_destroy(timerText);
        if (csfml->map)
            unload_map(csfml->map);
        if (csfml->window)
            sfRenderWindow_destroy(csfml->window);
        (csfml);
    }
}

void run_simulation_loop(SimulationData simData, csfml *csfml)
{
    sfClock* clock = sfClock_create();
    float deltaTime = 0;
    float elapsed_time = 0;

    while (simData.csfml && simData.csfml->window &&
    sfRenderWindow_isOpen(simData.csfml->window)) {
        handle_window_events_simulation(simData.csfml, simData.should_close);
        if (*simData.should_close)
            break;
        deltaTime = sfTime_asSeconds(sfClock_restart(clock));
        elapsed_time += deltaTime;
        simData.deltaTime = deltaTime;
        simData.elapsed_time = elapsed_time;
        update_and_draw(simData);
    }
    sfClock_destroy(clock);
}
