/*
** EPITECH PROJECT, 2024
** B-MUL-100-REN-1-1-myradar-savinien.petitjean
** File description:
** main2
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "../include/simulation.h"
#include "../include/map.h"
#include "../include/init_CSFML.h"
#include "../include/my.h"

int check_args(int argc, char *argv[])
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        print_usage();
        return 0;
    }
    if (argc < 2) {
        my_printf("Usage: %s <script_filepath>\n", argv[0]);
        return 84;
    }
    return 1;
}

void run_csfml(csfml *csfml, sfText *timerText, int *shouldClose)
{
    if (csfml && csfml->window) {    
        while (csfml && csfml->window) {
            sfRenderWindow_clear(csfml->window, sfBlack);
            draw_map(csfml->window, csfml->map);
            run_simulation(csfml, timerText, shouldClose);
            if (csfml->window == NULL) {
            break;
            }
            if (sfRenderWindow_isOpen(csfml->window)) {
                sfRenderWindow_display(csfml->window);
            }
        }
    } else {
        my_printf("csfml or window is null\n");
        return;
    }
}

void initialize_and_run_simulation(csfml *csfml, sfText *timer_text, int *should_close, int show_hitboxes)
{
    sfEvent event;

    if (!csfml) {
        return;
    }
    while (csfml && csfml->window && sfRenderWindow_isOpen(csfml->window) && !*should_close) {
        while (csfml && csfml->window && sfRenderWindow_pollEvent(csfml->window, &event)) {
            handle_window_events(event, &csfml, should_close, show_hitboxes);
            if (!csfml || !csfml->window || !sfRenderWindow_isOpen(csfml->window)) {
                free(csfml);
                break;
            }
        }
        if (!csfml || !csfml->window || !sfRenderWindow_isOpen(csfml->window) || *should_close) {
            free(csfml);
            break;
        }
        run_csfml(csfml, timer_text, should_close);
    }
}
