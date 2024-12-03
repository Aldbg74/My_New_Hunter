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
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #define SFTCF sfTexture_createFromFile
    #define SFRWC sfRenderWindow_create
    #define DW draw_window
    #define SFFR sfFloatRect

typedef struct window {
    sfVideoMode mode;
    sfWindow *window;
} window_mode_t;

typedef struct texture {
    sfTexture* texture;
    sfSprite* sprite;
} texture_data_t;

typedef struct {
    sfText *start;
    sfText *exit;
    sfFont *font;
} menu_t;

void do_create_window(void);
int make_window(void);
int make_kenny_true(void);
int make_menu(void);
sfTexture* load_character_texture(const char *file_path);
sfSprite *create_kenny(sfRenderWindow *window, float x, float y);
void draw_menu(sfRenderWindow *window, menu_t *menu);
int help_hunter(void);
sfSprite *create_life(sfRenderWindow *window, float x, float y);
int kill_kenny(sfSprite **sprite, sfRenderWindow *window, sfEvent event);
sfSprite *why_kenny_fly(sfRenderWindow *window, float x, float y);
int do_easter(void);
int do_valgrind(void);
sfSprite *create_play(sfRenderWindow *window, float x, float y);
sfSprite *create_quit(sfRenderWindow *window, float x, float y);
void do_menu_window(void);
void do_window(void);
sfSprite *move_kenny(sfSprite *sprite, sfRenderWindow *window);
sfMusic *play_music(void);
sfMusic *play_gun_music(void);

#endif
