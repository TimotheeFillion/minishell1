/*
** EPITECH PROJECT, 2019
** minishell 2
** File description:
** contains functions for unsetenv command
*/

#include "my.h"

void my_unsetenv2(char *elem, char **env)
{
    int n = 0;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcomp_2(elem, env[i]) == 0) {
            env[i][0] = 0;
            env[i][1] = '\0';
            n++;
        }
    }
}

void my_unsetenv(char **env, char **command)
{
    if (my_strlen_double(command) == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; command[i] != NULL; i++) {
        my_unsetenv2(command[i], env);
    }
}