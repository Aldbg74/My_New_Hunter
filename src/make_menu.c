/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myhunter-alexis.drago-beltran
** File description:
** make_menu
*/

#include "../include//my.h"
#include "../include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

static void draw_window(sfRenderWindow *window, sfSprite *sprite,
    sfSprite *create_play, sfSprite *create_quit)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, create_play, NULL);
    sfRenderWindow_drawSprite(window, create_quit, NULL);
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
    sfSprite_setScale(sprite, (sfVector2f){0.5, 0.5});
    return (sprite);
}

static sfRenderWindow *create_window(window_mode_t *window_mode)
{
    sfRenderWindow *window;

    window = SFRWC(window_mode->mode, "SH", sfResize | sfClose, NULL);
    return (window);
}

void can_use_clic(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    SFFR bounds_play = sfSprite_getGlobalBounds(create_play(window, 50, 200));
    SFFR bounds_quit = sfSprite_getGlobalBounds(create_quit(window, 50, 700));

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&bounds_play, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_close(window);
            do_create_window();
        }
        if (sfFloatRect_contains(&bounds_quit, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_close(window);
            mini_printf("[1]    113081 segmentation");
            mini_printf(" not fault (core not dumped)  ./My_Hunter\n");
            mini_printf("\n");
            mini_printf("T'as crus j'avais segfault chacal ^^ ?\n");
        }
    }
}

void do_menu_window(void)
{
    window_mode_t window_mode = {{1900, 1080, 32}};
    texture_data_t texture_data;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *sprite;

    window = create_window(&window_mode);
    texture_data.texture = SFTCF("src/params/welkom.jpg", NULL);
    sprite = create_sprite(&texture_data);
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, &event);
        DW(window, sprite, create_play(window, 50, 200),
            create_quit(window, 50, 700));
            can_use_clic(window, event);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture_data.texture);
    sfRenderWindow_destroy(window);
}
