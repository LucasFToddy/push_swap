/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserts_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:55:50 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/15 10:55:53 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_end(t_list **head, int value)
{
	t_list	*new_node;
	t_list	*temp;
	int		i;

	new_node = create_node(value);
	if (new_node == NULL)
		return (0);
	if (*head == NULL)
	{
		*head = new_node;
		return (1);
	}
	temp = *head;
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	temp->next = new_node;
	new_node->prev = temp;
	new_node->index = i;
	return (1);
}

int	insert_back(t_list **head, int value)
{
	t_list	*new_node;

	new_node = create_node(value);
	if (new_node == NULL)
		return (0);
	if (*head == NULL)
	{
		*head = new_node;
		return (1);
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = (*head)->prev;
	return (1);
}

void	indexing_stack(t_list **head)
{
	t_list	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	while (tmp->next == NULL)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}
