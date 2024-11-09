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

static void draw_window(sfRenderWindow *window, sfSprite *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

static void handle_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

static sfSprite *create_sprite(texture_data_t *texture_data)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_data->texture, sfTrue);
    return (sprite);
}

static sfRenderWindow *create_window(window_mode_t *window_mode)
{
    sfRenderWindow *window;

    window = sfRenderWindow_create(window_mode->mode, "SH",
                                    sfResize | sfClose, NULL);
    return (window);
}

int do_window(void)
{
    window_mode_t window_mode = {{1900, 1080, 32}};
    texture_data_t texture_data;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *sprite;

    window = create_window(&window_mode);
    texture_data.texture =
            sfTexture_createFromFile("src/params/BUS_STOP.jpg", NULL);
    sprite = create_sprite(&texture_data);
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, &event);
        draw_window(window, sprite);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture_data.texture);
    sfRenderWindow_destroy(window);
    return (0);
}

int main(void)
{
    if (sfTrue) {
        do_window();
    }
    return 0;
}
