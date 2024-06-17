/*
** EPITECH PROJECT, 2024
** My_New_Hunter
** File description:
** this_kenny.c
*/

#include "../include/my.h"
#include "../include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

int make_kenny_true(void)
{
    sfSprite *kennySprite;
    sfTexture *kennyTexture;
    sfVector2f kennyPosition = {0, 0};

    kennyTexture = sfTexture_createFromFile("params/KennyMcCormick.png", NULL);
    if (!kennyTexture) {
        return 84;
    }
    kennySprite = sfSprite_create();
    sfSprite_setTexture(kennySprite, kennyTexture, sfTrue);
    sfSprite_setPosition(kennySprite, kennyPosition);
    sfRenderWindow_drawSprite(window, kennySprite, NULL);

    return 0;
}