/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_getenv function
*/

#include "my.h"

char **rm_com_to_path(char **path, char *command)
{
    int i = 0;

    while (path[i] != NULL) {
        path[i][my_strlen(path[i]) - my_strlen(command)] = '\0';
        i++;
    }
    return (path);
}

char **add_com_to_path(char **path, char *command)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (path[i] != NULL) {
        j = my_strlen(path[i] + 1);
        path[i] = my_realloc(path[i], my_strlen(command));
        path[i][j + 1] = '/';
        j = j + 2;
        while (command[k] != '\0') {
            path[i][j] = command[k];
            j++;
            k++;
        }
        path[i][j] = '\0';
        i++;
        k = 0;
    }
    return (path);
}

char *find_line(char **env, char *elem)
{
    int i = 0;
    int j = 0;

    while (env[i] != NULL) {
        while (env[i][j] == elem[j])
            j++;
        if (elem[j] == '\0') {
            return (env[i]);
        }
        j = 0;
        i++;
    }
}

char **my_getenv(char **env, char *elem)
{
    int i = 0;
    int j = 0;
    char *line = find_line(env, elem);
    char *path = NULL;
    char **tab = NULL;

    while (line[i] != '=')
        i++;
    path = malloc((my_strlen(line) - i) * sizeof(char));
    i++;
    while (line[i] != '\0') {
        path[j] = line[i];
        i++;
        j++;
    }
    tab = my_str_to_wordtab(path);
    return (tab);
}