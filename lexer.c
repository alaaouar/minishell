/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:49:00 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/24 22:44:30 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

lexer_t *init_lexer(char *content)
{
    lexer_t *lexer;

    lexer = (lexer_t *)malloc(sizeof(lexer_t));
    if (!lexer)
        return NULL;

    lexer->content = content;
    lexer->i = 0;
    lexer->c = content[lexer->i];

    return lexer;
}
void    lexer_advance(lexer_t *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		lexer->i += 1;
		lexer->c = lexer->content[lexer->i];
	}
}
void    lexer_skipe_white(lexer_t *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t')
	{
		lexer_advance(lexer);
	}
}
char *lex_c_str(lexer_t *lexer)
{
    char *str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return NULL;
    str[0] = lexer->c;
    str[1] = '\0';
    return str;
}
t_token *lexer_advance_with_token(lexer_t *lexer, t_token *token)
{
	lexer_advance(lexer);
	return(token);
}
int quote_len(lexer_t *lexer)
{
	int i;
	char *str;

	i = lexer->i;
	str = lexer->content;
	while (str[i] != '\0' && str[i] != '"')
		i++;
	return 0;
}

char *lexer_collect_string(lexer_t *lexer)
{
	char *value;
	int i;
	
	i = 0;
	lexer_advance(lexer);
	value = (char *)malloc(quote_len(lexer) * sizeof(char));
	value[0] = '\0';
	while (lexer->c != '"')
	{
		if (lexer->c == '\0')
			perror("no ending quote ");
		value[i] = lexer->c;
		lexer_advance(lexer);
		i++;
	}
	return (value);
}
t_token	*lexer_get_next_token(lexer_t *lexer)
{
	t_token *token;
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
		if (lexer->c == ' ' || lexer->c == '\t')
			lexer_skipe_white(lexer);

	if (lexer->c == '"')
		return (lexer_advance_with_token(lexer, token_init(QUOTE, lexer_collect_string(lexer))));

	if (lexer->c == '|')
		return (lexer_advance_with_token(lexer, token_init(PIPE, lex_c_str(lexer))));
	else if (lexer->c == '<')
		return (lexer_advance_with_token(lexer, token_init(INFILE, lex_c_str(lexer))));	
	else if (lexer->c == '>')
		return (lexer_advance_with_token(lexer, token_init(OUTFILE, lex_c_str(lexer))));	
	
	
	return (token);
}

// bool isKeyword(char* str)
// {
// 	int i;
// 	int keyword_count;
// 	const char* keywords[] = {"ls", "cat", "lol"};

// 	i = 0;
// 	keyword_count = sizeof(keywords) / sizeof(keywords[0]);
// 	while (i < keyword_count) { 
// 		if (strcmp(str, keywords[i]) == 0) { 
// 			return true; 
// 		} 
// 		i++; 
// 	} 

// 	return false; 
// }