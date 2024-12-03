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
#include <time.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

static void draw_window(sfRenderWindow *window, sfSprite *sprite,
    sfSprite *sprite_kenny, sfSprite *create_life1)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite_kenny, NULL);
    sfRenderWindow_drawSprite(window, create_life1, NULL);
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

    window = SFRWC(window_mode->mode, "SH", sfResize | sfClose, NULL);
    return (window);
}

int continue_window(sfSprite *sprite,
    sfRenderWindow *window, texture_data_t texture_data)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture_data.texture);
    sfRenderWindow_destroy(window);
}

void do_create_window(void)
{
    sfSprite *sprite_kenny;
    window_mode_t window_mode = {{1900, 1080, 32}};
    texture_data_t texture_data;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *sprite;

    window = create_window(&window_mode);
    texture_data.texture = SFTCF("src/params/BUS_STOP.jpg", NULL);
    sprite = create_sprite(&texture_data);
    sprite_kenny = create_kenny(window, 50, 10);
    srand(time(NULL));
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, &event);
        if (kill_kenny(&sprite_kenny, window, event))
            sprite_kenny = create_kenny(window, rand() % 1900, rand() % 1080);
        move_kenny(sprite_kenny, window);
        DW(window, sprite, sprite_kenny, create_life(window, 50, 900));
    }
    continue_window(sprite, window, texture_data);
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            help_hunter();
            return 0;
        }
        if (my_strcmp(argv[i], "-easter") == 0) {
            do_easter();
            return 0;
        }
        if (my_strcmp(argv[i], "-valgrind") == 0) {
            do_valgrind();
            return 0;
        } else {
            mini_printf("Bozo\n");
            return 0;
        }
    }
        play_music();
        do_menu_window();
}
