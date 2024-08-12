/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:18:53 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/12 16:25:04 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void  ft_putstr_fd(char *str,int fd)
{
    int i = 0;

    while (str[i] != '\0')
    {
        ft_putchar_fd(str[i], fd);
        i++;
    }
}

int ft_strlen(char *str)
{
    int i =  0;

    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((unsigned char *)s)[i] = (unsigned char)c;
	return (s);
}

void    ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0')
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
}
