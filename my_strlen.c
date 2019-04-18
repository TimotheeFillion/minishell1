/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Count number of characters in string
*/

int my_strlen(char *str)
{
    int n = 0;

    while (str[n] != '\0')
        n++;
    return (n);
}

int my_strlen_double(char **str)
{
    int n = 0;

    while (str[n] != 0) {
        n++;
    }
    return (n);
}