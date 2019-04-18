/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** contains new_functions for minishell2
*/

#include "my.h"

char **get_new_command(char **command, int i, int j)
{
    char **new_command = malloc(sizeof(command));

    if (command[j][0] == ';')
        j++;
    for (int k = j; k != i; k++) {
        new_command[k] = command[k];
    }
    return (new_command);
}

int check_points_v(char **command, char **path, char **env, char *pwd)
{
    int j = 0;
    int return_value = 0;
    char **new_command = NULL;

    for (int i = 0; command[i] != NULL; i++) {
        if (command[i][0] == ';') {
            new_command = get_new_command(command, i, j);
            check_commands(new_command, path, env, pwd);
            j = i;
            return_value++;
        }
    }
    return (return_value);
}