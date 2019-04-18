/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Compare strings
*/

#include "my.h"

void free_double(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free (tab[i]);
        i++;
    }
    free (tab[i]);
    free (tab);
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}

int my_strcomp_2(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}
