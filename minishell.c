/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:25:17 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/12 19:39:09 by alaaouar         ###   ########.fr       */
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
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }

    if (str[i] == '\0') {
        // No command to process
        gene->cmd = NULL;
        gene->opt = NULL;
        return;
    }

    if (str[i] == '-') {
        // Extract option
        gene->opt = copyfier(str + i);
        gene->cmd = NULL;
    } else {
        // Extract command
        gene->cmd = copyfier(str + i);
        gene->opt = NULL;
    }

    // Move `i` past the command or option
    i += s_len(str + i);

    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }

    // If there's more text left, it might be an option
    if (str[i] != '\0' && str[i] == '-') {
        gene->opt = copyfier(str + i);
    }
}

int main(int ac, char **av)
{
    mini_t gene;
    char *str;
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
        printf("opt is [%s]\n", gene.opt);
        free(gene.cmd);
        free(str);
    }

    return 0;
}
