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
    sfTexture *spriteTexture = sfTexture_createFromFile("src/params/KennyMcCormick.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, spriteTexture, sfTrue);
}