/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-alexis.drago-beltran
** File description:
** my_strcat.c
*/

#include "../../include/my.h"
#include "stdio.h"
#include "string.h"

char *my_strcat(char const *src, char *new)
{
    size_t dest_len = my_strlen(new);
    size_t i;
    char *caca = malloc(sizeof(char) * (strlen(src)+ dest_len + 1));
    int popo = 0;

    for (i = 0; src[i] != '\0'; i++) {
        caca[i] = src[i];
    }
    for (popo = 0; new[popo] != '\0'; popo++) {
        caca[i + popo] = new[popo];
    }
    caca[i + popo] = '\0';
    return caca;
}
