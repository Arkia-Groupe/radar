/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-nathan.barbet
** File description:
** main.c
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/map.h"
#include "../include/init_CSFML.h"
#include "../include/my.h"

int show_hitboxes = 0;

void print_usage(void)
{
    my_printf("Air traffic simulation panel\n");
    my_printf("USAGE\n");
    my_printf("  ./my_radar [OPTIONS] path_to_script\n");
    my_printf("  path_to_script The path to the script file.\n");
    my_printf("OPTIONS\n");
    my_printf("  -h print the usage and quit.\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("  ‘L’ key enable/disable hitboxes and a\n");
}

void handle_events_main(sfEvent event, csfml **csfml, int *shouldClose)
{
    if (!csfml || !*csfml || !(*csfml)->window) {
        return;
    }
    if (event.type == sfEvtClosed) {
        *shouldClose = 1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        show_hitboxes = !show_hitboxes;
}

csfml* initialize_csfml(void)
{
    csfml* csfml = init_csfml("resources/img/background.png");

    if (!csfml)
        my_printf("Failed to initialize csfml\n");
    return csfml;
}

int initialize_simulation(char *script_filepath)
{
    if (init_simulation(script_filepath) != 0) {
        my_printf("Failed to initialize simulation\n");
        return 84;
    }
    return 0;
}

sfText* create_timer_text(void)
{
    sfText* timerText = sfText_create();
    sfFont* font = sfFont_createFromFile("resources/fonts/Roboto-Black.ttf");

    sfText_setPosition(timerText, (sfVector2f){1550, 0});
    sfText_setColor(timerText, sfBlack);
    sfText_setCharacterSize(timerText, 72);
    if (!font) {
        my_printf("Failed to load font\n");
        return NULL;
    }
    sfText_setFont(timerText, font);
    return timerText;
}

void handle_window_events(sfEvent event, csfml **csfml, int *should_close, int show_hitboxes)
{
    if (!csfml || !*csfml || !(*csfml)->window)
        return;
    if (event.type == sfEvtClosed)
        *should_close = 1;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        show_hitboxes = !show_hitboxes;
}

int main(int argc, char *argv[])
{
    int show_hitboxes = 0;
    sfText* timer_text = create_timer_text();
    csfml* csfml = initialize_csfml();
    int should_close = 0;

    if (check_args(argc, argv) != 1)
        return 84;
    if (!csfml)
        return 84;
    if (initialize_simulation(argv[1]) != 0) {
        if (csfml->window)
            sfRenderWindow_destroy(csfml->window);
        (csfml);
        return 84;
    }
    if (!timer_text)
        return 84;
    if (csfml && csfml->window)
        initialize_and_run_simulation(csfml, timer_text, &should_close, show_hitboxes);
    if (timer_text)
        sfText_destroy(timer_text);
    (csfml);
    return 0;
}
