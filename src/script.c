/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** script.c
*/

#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/init_CSFML.h"
#include "../include/script.h"
#include "../include/ControlTower.h"
#include "../include/aircraft.h"
#include "../include/window.h"
#include "../include/collision.h"
#include "../include/my.h"

Aircraft* aircrafts;
ControlTower* towers;
int num_aircrafts = 0;
int num_towers = 0;
int num_landed_aircrafts = 0;
int num_destroyed_aircrafts = 0;
extern int show_hitboxes;

void handle_event(sfEvent event, csfml **csfml, int *should_close)
{
    if (!csfml || !*csfml || !(*csfml)->window) {
        return;
    }
    if (event.type == sfEvtClosed) {
        *should_close = 1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        show_hitboxes = !show_hitboxes;
}

void update_timer(sfRenderWindow *window,
    sfText *timerText, float elapsed_time)
{
    char timerString[50] = "";

    my_printf(timerString, "Time: %.2f", elapsed_time);
    sfText_setString(timerText, timerString);
    sfRenderWindow_drawText(window, timerText, NULL);
}

void handle_aircraft_interactions(int i, float deltaTime)
{
    sfFloatRect hitbox1;
    sfFloatRect hitbox2;
    int j;

    hitbox1 = (sfFloatRect){aircrafts[i].pos.x - 10,
    aircrafts[i].pos.y - 10, 20, 20};
    for (j = i + 1; j < num_aircrafts; j++) {
        hitbox2 = (sfFloatRect){aircrafts[j].pos.x - 10,
        aircrafts[j].pos.y - 10, 20, 20};
        if (sfFloatRect_intersects(&hitbox1, &hitbox2, NULL))
            handle_aircraft_collision(i, j);
    }
    handle_aircraft_landing(i, deltaTime);
}
