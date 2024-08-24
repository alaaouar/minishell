/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:30:31 by alaaouar          #+#    #+#             */
/*   Updated: 2024/08/24 21:46:47 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!new)
		return (0);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}

t_cmd* create_t_cmd(char *value, t_id token)
{
    t_cmd* new_t_cmd;

    new_t_cmd = (t_cmd*)malloc(sizeof(t_cmd));
    if (new_t_cmd == NULL)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    new_t_cmd->value = ft_strdup(value);
    new_t_cmd->token = token;
    new_t_cmd->next = NULL;
    return new_t_cmd;
}

// t_cmd *link_node(t_cmd **node, t_cmd *node2)
// {
//     (*node)->next = node2;
//     return ()
// }

void add_to_end(t_cmd **head, t_cmd *new_node)
{
    t_cmd *current;
    
    if (new_node == NULL)
        return;
    if (*head == NULL)
        *head = new_node;
    else
        current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}
