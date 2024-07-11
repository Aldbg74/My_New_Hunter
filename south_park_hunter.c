/*
** EPITECH PROJECT, 2024
** My_New_Hunter
** File description:
** south_park_hunter.c
*/

#include "include/my.h"
#include "include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "include/my_hunter.h"

int main(void)
{
    WindowMode windowMode = {{1700, 1600, 32}};
    sfRenderWindow* window;
    sfEvent event;

    window = sfRenderWindow_create(windowMode.mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return 1;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}