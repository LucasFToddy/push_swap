/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:12:42 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 19:38:48 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->index = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->cheaper = 0;
	new_node->cost_push = 0;
	new_node->top_mid = 0;
	return (new_node);
}

int	stack_init(t_list **head, char **matrix)
{
	while (*matrix != NULL)
	{
		if (!check_error(head, *matrix))
			return (0);
		if (!insert_end(head, ft_atol(*matrix)))
			return (0);
		matrix++;
	}
	return (1);
}

void	different_parameters(int argc, char ***argv)
{
	char	*str;
	int		i;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		str = ft_strjoin(str, (*argv)[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	*argv = ft_split(str, ' ');
	free(str);
}

void	ft_remove(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	if (tmp != NULL)
	{
		*head = tmp->next;
		free(tmp);
		return ;
	}
}

void	prep_to_push(t_list **stack, t_list *node_top, char name_stack)
{
	while (*stack != node_top)
	{
		if (name_stack == 'a')
		{
			if (node_top->top_mid)
				ft_rotate(stack, 'a');
			else
				ft_reverse_rotate(stack, 'a');
		}
		if (name_stack == 'b')
		{
			if (node_top->top_mid)
				ft_rotate(stack, 'b');
			else
				ft_reverse_rotate(stack, 'b');
		}
	}
}
