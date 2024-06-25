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
#include <SFML/Graphics.h>

sfVideoMode mode = {1900, 1080, 32};
sfRenderWindow *window;
sfTexture *backgroundTexture;
sfSprite *backgroundSprite;


void init_resources(void)
{
    window = sfRenderWindow_create(mode, "South Park Hunt", sfClose, NULL);
    backgroundTexture =
            sfTexture_createFromFile("src/params/BUS_STOP.jpg", NULL);
    backgroundSprite = sfSprite_create();
    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
}

void destroy_resources(void)
{
    sfSprite_destroy(backgroundSprite);
    sfTexture_destroy(backgroundTexture);
    sfRenderWindow_destroy(window);
}

void still_do_window(void)
{
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

void do_the_window(void)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        still_do_window();
    }
}

int make_window(void)
{
    init_resources();
    if (!window) {
        return 84;
    }
    do_the_window();
    destroy_resources();
    return 0;
}
