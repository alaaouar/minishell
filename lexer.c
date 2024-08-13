/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:49:00 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/13 18:55:54 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

lexer_t *init_lexer(char *content)
{
	lexer_t lexer;

	lexer = ft_calloc(1, sizeof())
}
void    lexer_advance(lexer_t *lexer)
{
	
}
void    lexer_skipe_white(lexer_t)
{
	
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