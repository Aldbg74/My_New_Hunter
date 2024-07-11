/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-alexis.drago-beltran
** File description:
** my_hunter.h
*/

#pragma once
#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

#ifndef MY_HUNTER_H
#define MY_HUNTER_H
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

typedef struct game_s {
    sfRenderWindow *window;
    sfTexture *backgroundTexture;
    sfSprite *backgroundSprite;
} game_t;

#endif

void do_the_window(void);
int make_window(void);
int make_kenny_true(void);
int make_menu(void);

#endif
