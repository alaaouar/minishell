/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:26:22 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/26 18:23:51 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include "token.h"

typedef struct lexer_s
{
    char *content;
    char c;
    unsigned int i;
}               lexer_t;

lexer_t *init_lexer(char *content);
void    lexer_advance(lexer_t *lexer);
void    lexer_skipe_white(lexer_t *lexer);
char    *lex_c_str(lexer_t *lexer);

#endif