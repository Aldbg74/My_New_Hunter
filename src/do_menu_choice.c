/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myhunter-alexis.drago-beltran
** File description:
** do_menu_choice
*/

#include "../include//my.h"
#include "../include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>

sfSprite *create_play(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/Start.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}

sfSprite *create_quit(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/quit.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}
