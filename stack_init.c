/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:12:42 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/13 19:36:25 by lucas-do         ###   ########.fr       */
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
	return (new_node);
}

int	stack_init(t_list **head, char **matrix, int arg)
{
	if (arg > 2)
		matrix++;
	while (*matrix != NULL)
	{
		if (ft_check_list(head, ft_atoi(*matrix)) == 1)
		{
			printf("duplicate number!\n");
			ft_list_free(head);
			return (0);
		}
		else if (ft_check_str(*matrix))
		{
			printf("please enter only numbers!\n");
			ft_list_free(head);
			return (0);
		}
		if (!insert_end(head, ft_atoi(*matrix)))
		{
			ft_list_free(head);
			return (0);
		}
		matrix++;
	}
	return (1);
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
