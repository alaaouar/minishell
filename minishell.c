/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:25:17 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/12 02:27:07 by alaaouar         ###   ########.fr       */
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

void exit_command(char *str)
{
    int i = 0;
    char ext[] = "exit";

    while (str[i] && ext[i] && str[i] == ext[i])
    {
        i++;
    }
    if (i == 4 && (str[i] == '\0' || str[i] == '\n'))
    {
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

void    parce(char *str, mini_t *gene)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int huh = 0;
    
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    huh = i;
    while (str[huh] != '\0' && str[huh] != ' ' && str[huh] != 't')
    {
        tmp++;
        huh++;
    }
    gene->cmd = malloc(sizeof(char) * tmp + 1);
    while (str[i] != '\0' && str[i] != ' ' && str[i] != 't')
    {
        gene->cmd[j] = str[i];
        i++;
        j++;
    }
    gene->cmd[j] = '\0';
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
        exit_command(str);
        printf("Command received:[%s]\n", str);
        printf("cmd is [%s]\n", gene.cmd);
    }

    return 0;
}
