/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myhunter-alexis.drago-beltran
** File description:
** play_music
*/

#include <SFML/Audio.h>

sfMusic *play_music(void)
{
    sfMusic *music = sfMusic_createFromFile("src/params/music/southsong.mp3");
    sfBool loop;

    sfMusic_setLoop(music, loop);
    sfMusic_play(music);
    return music;
}

sfMusic *play_gun_music(void)
{
    sfMusic *music = sfMusic_createFromFile("src/params/music/pan.mp3");

    sfMusic_play(music);
    return music;
}
