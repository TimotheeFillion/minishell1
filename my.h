/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** contains declarations and includes
*/

#ifndef _HEADER
#define _HEADER

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

char **my_str_to_wordtab(char *str);
char *my_realloc(char *str, int size);
char *get_next_line(int fd);
int my_strcmp(char const *s1, char const *s2);
char **my_getenv(char **env, char *elem);
int my_putstr(char const *str);
int my_strlen(char *str);
void shell_loop(char **path, char **env, char *pwd);
void check_commands(char **command, char **path, char **env, char *pwd);
char **add_com_to_path(char **path, char *command);
char **my_strcpy_double(char **source);
void free_double(char **tab);
char **rm_com_to_path(char **path, char *command);
char **my_realloc_tab(char **tab, int size);
int my_putchar(char c);
int my_strlen_double(char **str);
char **setenv_2(char **env, char **command);
char **setenv_1(char **env, char **command);
void my_unsetenv(char **env, char **command);
int my_strcomp_2(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
void my_cd(char *pwd, char **command);
int check_points_v(char **command, char **path, char **env, char *pwd);

#endif
