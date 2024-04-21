/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** events.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/events.h"
#include "../include/my.h"

void handle_window_events_simulation(csfml *csfml, int *should_close)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(csfml->window, &event))
        handle_event(event, &csfml, should_close);
}

float babylonian_sqrt(float num)
{
    const float epsilon = 0.00001;
    float guess = num / 2.0;

    while (abs(guess * guess - num) >= epsilon) {
        guess = (guess + num / guess) / 2.0;
    }
    return guess;
}
