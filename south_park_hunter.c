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
#include <SFML/Audio.h>
#include <SFML/System.h>

int main(void)
{
    sfVideoMode mode = {1900, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "South Park Hunt", sfClose, NULL);
    if (!window) {
        return 84;
    }
    sfTexture *backgroundTexture = sfTexture_createFromFile("src/params/BUS_STOP.jpg", NULL);
    sfSprite *backgroundSprite = sfSprite_create();
    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    sfTexture *spriteTexture = sfTexture_createFromFile("src/params/KennyMcCormick.png", NULL);
}
