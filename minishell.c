/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:25:17 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/12 00:38:22 by alaaouar         ###   ########.fr       */
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
        exit_command(str);
        printf("Command received:[%s]\n", str);
    }

    return 0;
}
