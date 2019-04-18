/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main file of the project
*/

#include "my.h"

void commands_errors(char *command, char **path, char **env, char *pwd)
{
    if (command == NULL) {
        my_putstr("exit\n");
        exit (0);
    }
    if (my_strlen(command) == 0) {
        shell_loop(path, env, pwd);
        exit (0);
    }
    return;
}

void shell_loop(char **path, char **env, char *pwd)
{
    char *command = NULL;
    char **command_tab = NULL;

    while (24) {
        my_putstr("my_prompt>");
        command = get_next_line(0);
        commands_errors(command, path, env, pwd);
        command_tab = my_str_to_wordtab(command);
        check_commands(command_tab, path, env, pwd);
    }
    return;
}

int main(int ac, char **av, char **env)
{
    char **path = my_getenv(env, "PATH");
    char **pwd = my_getenv(env, "PWD");

    if (ac != 1)
        return (84);
    shell_loop(path, env, pwd[0]);
    free (pwd);
    free (path);
    return (0);
}