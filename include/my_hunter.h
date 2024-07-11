/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-alexis.drago-beltran
** File description:
** my_hunter.h
*/

#pragma once
#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

#include <SFML/Graphics.h>

typedef struct {
    sfVideoMode mode;
} WindowMode;

void do_the_window(void);
int make_window(void);
int make_kenny_true(void);
int make_menu(void);

#endif
