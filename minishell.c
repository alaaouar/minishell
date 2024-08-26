/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:25:17 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/26 18:23:37 by alaaouar         ###   ########.fr       */
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

void exit_command(char *str, t_cmd *cmd)
{
    int i = 0;
    char ext[] = "exit";

    while (str[i] && ext[i] && str[i] == ext[i])
        i++;
    if (i == 4 && (str[i] == '\0' || str[i] == '\n'))
    {
        free_cmd_list(cmd);
        free(str);
        exit(0);
    }
}

void    set_prompt(char *str, mini_t *gene)
{
    if (gene->prompt != NULL)
        free(gene->prompt);
    gene->prompt = malloc(ft_strlen(str) + 1);
    if (gene->prompt == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
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
    if (new == NULL)
    {
        perror("malloc failed");
        exit(1);
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

void parce(char *str, t_cmd **head) {
    int i = 0;
    t_cmd *current = NULL;
    t_cmd *last = NULL;
    
    *head = NULL;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '\0')
        return;

    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '\0')
            break;


        if (str[i] == '-') {
            current = create_t_cmd(copyfier(str + i), OPT, 0);
        } 
        else if (str[i] == '|') {
            current = create_t_cmd(NULL, PIPE, str[i]);
        }
        else {
            current = create_t_cmd(copyfier(str + i), CMD, 0);
        }

        if (*head == NULL) {
            *head = current;
        } else {
            last->next = current;
        }
        last = current;

        i += s_len(str + i);
    }
}

int    its_valide(char *str)
{
    int i;
    int g;

    i = 0;
    g = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '"')
            g++;
        i++;
    }
    if (g % 2 != 0)
    {
        printf("quotes command non valid\n");
        
        return(0);
    }
    return 1;
}
void print_cmd_list(const t_cmd *head)
{
    const t_cmd *current = head;
    while (current != NULL) {
        // Print the value and token of the current node
        const char *token_str;
        switch (current->token) {
            case WORD: token_str = "WORD"; break;
            case PIPE: token_str = "PIPE"; break;
            case APPEND: token_str = "APPEND"; break;
            case QUOTE: token_str = "QUOTE"; break;
            case HEREDOC: token_str = "HEREDOC"; break;
            case INFILE: token_str = "INFILE"; break;
            case OUTFILE: token_str = "OUTFILE"; break;
            case CMD: token_str = "CMD"; break;
            case OPT: token_str = "OPT"; break;
            default: token_str = "UNKNOWN"; break;
        }
        printf("Value: [%s], Token: [%s]\n", current->value, token_str);
        current = current->next; // Move to the next node
    }
}
int main(int ac, char **av)
{
    mini_t gene;
    t_cmd *cmd;
    lexer_t *lexer;
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
        if (its_valide(str))
            parce(str, &cmd);
        else
            continue;
        printf("lexer tests \n");
        
        lexer = init_lexer(str);
        
        exit_command(str, cmd);
        print_cmd_list(cmd);
        free_cmd_list(cmd);
    }
    return 0;
}
