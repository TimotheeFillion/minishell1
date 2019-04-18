/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_str_to_wordtab
*/

#include "my.h"

char **my_realloc_tab(char **tab, int size)
{
    int i = 0;
    int j = 0;
    char **new_tab;

    new_tab = malloc((my_strlen_double(tab) + size) * sizeof(char *));
    while (tab[i] != NULL) {
        new_tab[i] = malloc((my_strlen(tab[i]) + 1) * sizeof(char));
        while (tab[i][j] != '\0') {
            new_tab[i][j] = tab[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    new_tab[i + 1] = NULL;
    return (new_tab);
}

void malloc_tab(char **tab, char *str)
{
    for (int l = 0; l != my_strlen(str); l++) {
        tab[l] = malloc(1 * sizeof(char));
        tab[l][0] = '\0';
    }
}

char **my_str_to_wordtab(char *str)
{
    char **wordtab = malloc((my_strlen(str) + 2) * sizeof(char *));
    int i = 0;
    int j = 0;

    malloc_tab(wordtab, str);
    for (int k = 0; str[k] != '\0' ; k++) {
        if (str[k] == ' ' || str[k] == ':') {
            i++;
            j = 0;
            k++;
        }
        wordtab[i] = my_realloc(wordtab[i], 1);
        wordtab[i][j] = str[k];
        j++;
    }
    i++;
    wordtab[i] = NULL;
    return (wordtab);
}