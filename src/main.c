/*
** EPITECH PROJECT, 2023
** B-CPE-110-REN-1-1-organized-nathan.barbet
** File description:
** main.c
*/

#include "../include/radar.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;
    window = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
