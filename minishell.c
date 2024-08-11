/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:25:17 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/11 17:20:01 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

void  ft_putstr(char *str,int fd)
{
    int i = 0;

    while (str[i] != '\0')
    {
        ft_putchar(str[i], fd);
        i++;
    }
}
int ft_strlen(char *str)
{
    int i =  0;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void    ignor_signals(mini_t *gene)
{    
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}

void    initial(mini_t *gene)
{
    gene->signalset = false;
    
}

int main(int ac, char **av)
{
    mini_t gene;
    char *str;

    initial(&gene);
    while (1)
    {
        ignor_signals(&gene);
        read(0, str, ft_strlen(str));
        ft_putstr(str, 1);
    }
}
