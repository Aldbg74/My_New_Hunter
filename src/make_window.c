/*
** EPITECH PROJECT, 2024
** My_New_Hunter
** File description:
** make_window.c
*/

#include "../include/my.h"
#include "../include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

int make_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "My_Hunter", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}