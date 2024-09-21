/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:29:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/25 17:37:50 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "token.h"

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

typedef struct s_cmd
{
    char *value;
    t_id token;
    struct s_cmd *next;

}   t_cmd;

int         s_len(char *s);
void        free_cmd_list(t_cmd *head);
t_cmd*      create_t_cmd(char *value, t_id token, char c);
void        set_prompt(char *str, mini_t *gene);
void        ft_strcpy(char *s1, char *s2);
void	    *ft_memset(void *s, int c, size_t n);
void        exit_command(char *str, t_cmd *cmd);
void        ignor_signals(mini_t *gene);
int         ft_strlen(char *str);
void        ft_putstr_fd(char *str,int fd);
void        ft_putchar_fd(char c, int fd);
void	    *ft_calloc(size_t count, size_t size);

#endif


// ls -a -l

// char **cmd, cmd[0] = "ls";
// char **opt, opt[0] = "-a", opt[1] = "-l";
// execve(cmd[0], opt, env);