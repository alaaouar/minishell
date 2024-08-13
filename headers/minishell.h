/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:29:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/13 18:52:02 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "lexer.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct minishell_s
{
    bool signalset;
    char *prompt;
    char *cmd;
    char **opt;
    
}   mini_t;



typedef struct s_token
{
    char            *value;
    t_id            token;
    struct s_token  *next;
}               t_token;

typedef struct s_cmd
{
    char *cmd;
    
    // char **arguments;
    // a linked list of redirections here
}   t_cmd;

// typedef struct s_list
// {
//     char            *cmd;
//     char            *opt;
// 	struct s_list	*next;
// }					t_list;

void        set_prompt(char *str, mini_t *gene);
void        ft_strcpy(char *s1, char *s2);
void	    *ft_memset(void *s, int c, size_t n);
void        exit_command(char *str, mini_t *gene);
void        ignor_signals(mini_t *gene);
int         ft_strlen(char *str);
void        ft_putstr_fd(char *str,int fd);
void        ft_putchar_fd(char c, int fd);

#endif


// ls -a -l

// char **cmd, cmd[0] = "ls";
// char **opt, opt[0] = "-a", opt[1] = "-l";
// execve(cmd[0], opt, env);