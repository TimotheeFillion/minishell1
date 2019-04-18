/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** contains functions for cd
*/

#include "my.h"

void update_pwd(char *pwd, char *new_dir)
{
    int j = my_strlen(pwd) + 1;

    my_realloc(pwd, my_strlen(new_dir + 1));
    pwd[my_strlen(pwd)] = '/';
    for (int i = 0; new_dir[i] != '\0'; i++) {
        pwd[j] = new_dir[i];
        j++;
    }
    my_putstr(pwd);
}

void basic_cd(char *pwd, char *new_dir)
{
    char *to_open = malloc(my_strlen(new_dir + 3));
    int i = 2;

    to_open[0] = '.';
    to_open[1] = '/';
    for (int j = 0; new_dir[j] != '\0'; j++) {
        to_open[i] = new_dir[j];
        i++;
    }
    if (opendir(to_open) == NULL) {
        my_putstr(new_dir);
        my_putstr(": No such file or directory.");
        return;
    }
    chdir(to_open);
    update_pwd(pwd, new_dir);
}

void cd_back(char *pwd)
{
    int i = my_strlen(pwd);

    while (pwd[i] != '/')
        i--;
    pwd[i] = '\0';
    chdir(pwd);
    return;
}

void my_cd(char *pwd, char **command)
{
    if (my_strlen_double(command) > 2) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    if (my_strcmp(command[1], "..") == 0) {
        cd_back(pwd);
        return;
    }
    basic_cd(pwd, command[1]);

}
