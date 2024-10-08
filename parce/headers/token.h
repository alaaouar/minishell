/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:35:11 by alaaouar          #+#    #+#             */
/*   Updated: 2024/09/13 15:13:03 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
#define TOKEN_H

typedef enum s_id
{
    STRING,
    PIPE,
    APPEND,
    QUOTE,
    HEREDOC,
    INFILE,
    OUTFILE,
    CMD,
    OPT,
}   t_id;

typedef struct s_token
{
    char            *value;
    t_id            token;
    struct s_token  *next;
}               t_token;

t_token *token_init(int type , char *value);


#endif