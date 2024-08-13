/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:49:00 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/13 17:55:36 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

bool isKeyword(char* str)
{
	int i;
	int keyword_count;
	const char* keywords[] = {"ls", "cat", "lol"};

	i = 0;
	keyword_count = sizeof(keywords) / sizeof(keywords[0]);
	while (i < keyword_count) { 
		if (strcmp(str, keywords[i]) == 0) { 
			return true; 
		} 
		i++; 
	} 

	return false; 
}