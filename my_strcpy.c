/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Copy string
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    dest[0] = src[0];
    for (int i = 1; src[i - 1] != '\0'; i++)
        dest[i] = src[i];
    return (dest);
}

char **my_strcpy_double(char **source)
{
    char **dest = malloc(sizeof(source));
    int i = 0;

    while (source[i] != NULL) {
        dest[i] = malloc(sizeof(source[i]));
        dest[i] = my_strcpy(dest[i], source[i]);
        i++;
    }
    dest[i] = NULL;
    return (dest);
}