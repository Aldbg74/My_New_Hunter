/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myhunter-alexis.drago-beltran
** File description:
** make_life
*/

#include "../include//my.h"
#include "../include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>

sfSprite *create_life(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/logo.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}
