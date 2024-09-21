/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:53:12 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/18 16:57:39 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers/minishell.h"

t_token *token_init(int type , char *value)
{
    t_token *token;

    token = (t_token *)malloc(sizeof(t_token));
    token->value = value;
    token->token = type;
    return (token);
}
