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

int do_the_window2(void)
{
    sfVideoMode mode = {1900, 1080, 32};
    sfRenderWindow *window =
            sfRenderWindow_create(mode, "South Park Hunt", sfClose, NULL);
    sfTexture *backgroundTexture =
            sfTexture_createFromFile("src/params/BUS_STOP.jpg", NULL);
    sfSprite *backgroundSprite = sfSprite_create();

    sfSprite_destroy(backgroundSprite);
    sfTexture_destroy(backgroundTexture);
    sfRenderWindow_destroy(window);
    return 0;
}

int do_the_window(void)
{
    sfVideoMode mode = {1900, 1080, 32};
    sfRenderWindow *window =
            sfRenderWindow_create(mode, "South Park Hunt", sfClose, NULL);
    sfTexture *backgroundTexture =
            sfTexture_createFromFile("src/params/BUS_STOP.jpg", NULL);
    sfSprite *backgroundSprite = sfSprite_create();

    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, backgroundSprite, NULL);
        sfRenderWindow_display(window);
    }
    do_the_window2();
    return 0;
}

int make_window(void)
{
    sfVideoMode mode = {1900, 1080, 32};
    sfRenderWindow *window =
            sfRenderWindow_create(mode, "South Park Hunt", sfClose, NULL);
    sfTexture *backgroundTexture =
            sfTexture_createFromFile("src/params/BUS_STOP.jpg", NULL);
    sfSprite *backgroundSprite = sfSprite_create();

    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    if (!window) {
        return 84;
    }
    do_the_window();
    return 0;
}