/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** contains commands execution
*/

#include "my.h"

void setenv_1_2(char **env, char **command, int i, int j)
{
    my_realloc_tab(env, 1);
    env[i] = malloc(my_strlen(command[1]) + 1);
    while (command[1][j] != '\0') {
        env[i][j] = command[1][j];
        j++;
    }
    env[i][j] = '=';
    env[i][j + 1] = '\0';
    env[i + 1] = NULL;
}

char **setenv_1(char **env, char **command)
{
    int i = 0;
    int j = 0;

    while (env[i] != NULL) {
        while (env[i][j] != '=' && env[i][j] == command[1][j]) {
            j++;
        }
        if (env[i][j] == '=') {
            env[i][j + 1] = '\0';
            return (env);
        }
        i++;
        j = 0;
    }
    setenv_1_2(env, command, i, j);
}

char **setenv_2(char **env, char **command)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (env[i] != NULL) {
        while (env[i][j] != '=' && env[i][j] == command[1][j]) {
            j++;
        }
        if (env[i][j] == '=') {
            env[i] = my_realloc(env[i], my_strlen(command[2]));
            j++;
            while (command[2][k] != '\0') {
                env[i][j] = command[2][k];
                k++;
                j++;
            }
            return (env);
        }
        i++;
        j = 0;
    }
    my_realloc_tab(env, 1);
    env[i] = malloc(my_strlen(command[1]) + my_strlen(command[2]) + 1);
    while (command[1][j] != '\0') {
        env[i][j] = command[1][j];
        j++;
    }
    env[i][j] = '=';
    j++;
    while (command[2][k] != '\0') {
        env[i][j] = command[2][k];
        j++;
        k++;
    }
    env[i + 1] = NULL;
    return (env);
}