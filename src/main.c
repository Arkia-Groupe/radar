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

    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usages();
        return (0);
    }
    window = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    texture = sfTexture_createFromFile("resources/background.png", NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
