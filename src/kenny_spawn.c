/*
** EPITECH PROJECT, 2024
** My_New_Hunter
** File description:
** kenny_spawn.c
*/

#include "../include//my.h"
#include "../include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

sfSprite *move_kenny(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(sprite);

    sfSprite_setPosition(sprite, (sfVector2f){pos.x + 5, pos.y});
    if (pos.x > 1920) {
        sfSprite_setPosition(sprite, (sfVector2f){-100, pos.y});
    }
    if (pos.y > 1080) {
        sfSprite_setPosition(sprite, (sfVector2f){pos.x, 0});
    }
    return sprite;
}

sfSprite *create_kenny(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture = SFTCF("src/params/Kenny.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}

int kill_kenny(sfSprite **sprite, sfRenderWindow *window, sfEvent event)
{
    static int kenny_deaths;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(*sprite);
    sfTexture *texture = (sfTexture *)sfSprite_getTexture(*sprite);

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            play_gun_music();
            kenny_deaths++;
            mini_printf("Oh my God, you've killed Kenny!\n");
            mini_printf("You're fucking bastard\n");
            mini_printf("Kenny has been killed %d times\n", kenny_deaths);
            mini_printf("\n");
            sfTexture_destroy(texture);
            sfSprite_destroy(*sprite);
            *sprite = create_kenny(window, rand() % 1900, rand() % 1080);
        }
    }
    return 0;
}
