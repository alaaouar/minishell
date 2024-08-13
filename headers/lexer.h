/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:26:22 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/13 18:51:37 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include "../libft/libft.h"

typedef struct lexer_s
{
    char c;
    unsigned int i;
    char *content;
}               lexer_t;

typedef enum s_id
{
    WORD,
    PIPE,
    APPEND,
    HEREDOC,
    INFILE,
    OUTFILE,
}   t_id;

lexer_t *init_lexer(char *content);
void    lexer_advance(lexer_t *lexer);
void    lexer_skipe_white(lexer_t);


#endif