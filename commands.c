/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** contains functions to handle commands
*/

#include "my.h"

void my_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i]);
        if (env[i][0] != 0)
            my_putchar('\n');
        i++;
    }
}

void **my_setenv(char **env, char **command)
{
    int l = my_strlen_double(command);

    switch (l) {
    case 1:
        my_env(env);
        break;
    case 2:
        env = setenv_1(env, command);
        break;
    case 3:
        env = setenv_2(env, command);
        break;
    default:
        my_putstr("setenv: Too many arguments.\n");
        break;
    }
}

void print_error(char *command)
{
    my_putstr(command);
    my_putstr(": Command not found.\n");
}

void program_exe(char **path, char **env, char **command)
{
    pid_t pid;
    int wstatus;

    add_com_to_path(path, command[0]);
    for (int i = 0; path[i] != NULL; i++) {
        if (open(path[i], O_RDONLY) != -1) {
            pid = fork();
            if (pid == 0) {
                execve(path[i], command, env);
                exit (0);
            } else
                waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
            return;
        }
    }
    print_error(command[0]);
}

void check_commands(char **command, char **path, char **env, char *pwd)
{
    if (check_points_v(command, path, env, pwd) != 0)
        return;
    if (my_strcmp(command[0], "exit") == 0)
        exit (0);
    if (my_strcmp(command[0], "env") == 0) {
        my_env(env);
        return;
    }
    if (my_strcmp(command[0], "setenv") == 0) {
        my_setenv(env, command);
        return;
    }
    if (my_strcmp(command[0], "unsetenv") == 0) {
        my_unsetenv(env, command);
        return;
    }
    if (my_strcmp(command[0], "cd") == 0) {
        my_cd(pwd, command);
        return;
    }
    program_exe(path, env, command);
    rm_com_to_path(path, command[0]);
    return;
}