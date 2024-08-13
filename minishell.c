/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:25:17 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/13 18:05:00 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void    ignor_signals(mini_t *gene)
{    
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}

void    initial(mini_t *gene)
{
    gene->signalset = false;
    gene->prompt = NULL;
}

void exit_command(char *str, mini_t *gene)
{
    int i = 0;
    char ext[] = "exit";

    while (str[i] && ext[i] && str[i] == ext[i])
        i++;
    if (i == 4 && (str[i] == '\0' || str[i] == '\n'))
    {
        free(str);
        free(gene->cmd);
        free(gene->prompt);
        exit(1);
    }
}

void    set_prompt(char *str, mini_t *gene)
{
    if (gene->prompt != NULL)
        free(gene->prompt);
    gene->prompt = malloc(ft_strlen(str) + 1);
    ft_strcpy(str, gene->prompt);
}

int s_len(char *s)
{
    int i;

    i = 0;
    while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
    {
        i++;
    }
    return i;
}

int count_options(char *str)
{
    int i;
    int opn;

    i = 0;
    opn = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '-')
            opn++;
        i++;
    }
    return (opn);
}

char *copyfier(char *str)
{
    int len;
    char *new;
    
    len = s_len(str);
    new = malloc(sizeof(char) * (len + 1));
    if (!new) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new[len] = '\0';
    len--;
    while (len >= 0)
    {
        new[len] = str[len];
        len--;
    }
    return new;
}

void parce(char *str, mini_t *gene) {
    int i = 0, x = 0;

    gene->cmd = NULL;
    gene->opt = malloc(sizeof(char*) * count_options(str)); // MAX_OPTIONS is a constant defining max number of options

    if (!gene->opt) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Skip initial whitespace
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    if (str[i] == '\0') // Empty input
        return;

    // Determine if the first part is a command or option
    if (str[i] == '-') {
        gene->opt[x++] = copyfier(str + i);
    } else {
        gene->cmd = copyfier(str + i);
    }

    i += s_len(str + i);

    // Process remaining part as options
    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '-' && x < count_options(str)) {
            gene->opt[x++] = copyfier(str + i);
        }
        i += s_len(str + i);
    }

    gene->opt[x] = NULL; // Null-terminate the options array
}

int main(int ac, char **av)
{
    mini_t gene;
    char *str;
    int test = 0;
    int rn;

    initial(&gene);
    ignor_signals(&gene);
    set_prompt("minishell:", &gene);
    while (1)
    {
        str = readline(gene.prompt);
        if (!ft_strlen(str))
            continue ;
        add_history(str);
        parce(str, &gene);
        exit_command(str, &gene);
        printf("Command received:[%s]\n", str);
        printf("cmd is [%s]\n", gene.cmd);
        test = 0;
        while(gene.opt[test])
        {
            printf("opt is [%s]\n", gene.opt[test]);
            test++;
        }
        free(gene.cmd);
        free(str);

    }
    return 0;
}
