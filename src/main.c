/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-savinien.petitjean
** File description:
** main.c
*/

#include "../include/radar.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usages();
        return (0);
    }
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
