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
#include "include/my_hunter.h"

#include "include/my.h"
#include "include/my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

int main(void)
{
    Window_Mode windowMode = {{1900, 1080, 32}};
    TextureData textureData;
    sfRenderWindow* window;
    sfEvent event;
    sfSprite* sprite;

    window = sfRenderWindow_create(windowMode.mode, "SH", sfResize | sfClose, NULL);
    if (!window)
        return 1;

    textureData.texture = sfTexture_createFromFile("src/params/BUS_STOP.jpg", NULL);
    if (!textureData.texture)
        return 1;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, textureData.texture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }

    sfSprite_destroy(sprite);
    sfTexture_destroy(textureData.texture);
    sfRenderWindow_destroy(window);

    return 0;
}