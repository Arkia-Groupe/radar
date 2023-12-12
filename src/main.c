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
    sfTexture* txt_background;
    sfSprite* sprt_background;
    sfTexture* txt_tower;
    sfSprite* sprt_tower;
    sfEvent event;

    sfCircleShape* circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, 50);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setOutlineColor(circle, sfBlue);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setPosition(circle, (sfVector2f){960, 540});
    sfCircleShape_setScale(circle, (sfVector2f){2, 2});

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usages();
        return (0);
    }
    window = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    txt_background = sfTexture_createFromFile("resources/background.png", NULL);
    if (!txt_background)
        return EXIT_FAILURE;
    txt_tower = sfTexture_createFromFile("resources/tower.png", NULL);
    if (!txt_tower)
        return EXIT_FAILURE;
    sprt_background = sfSprite_create();
    sprt_tower = sfSprite_create();
    sfSprite_setPosition(sprt_tower, (sfVector2f){960, 540});
    sfSprite_setScale(sprt_tower, (sfVector2f){0.2, 0.2});
    sfSprite_setTexture(sprt_background, txt_background, sfTrue);
    sfSprite_setTexture(sprt_tower, txt_tower, sfTrue);
    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprt_background, NULL);
        sfRenderWindow_drawSprite(window, sprt_tower, NULL);
        sfRenderWindow_drawCircleShape(window, circle, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprt_background);
    sfTexture_destroy(txt_background);
    sfRenderWindow_destroy(window);
    sfCircleShape_destroy(circle);
    return EXIT_SUCCESS;
}