/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:12:42 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/04 14:55:32 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_list *create_node(int value)
{
	struct s_list *newNode;

	newNode = (struct s_list *)malloc(sizeof(struct s_list));
	if (!newNode)
		return (NULL);

	newNode->data = value;
	newNode->index = 0;
	newNode->next = NULL;
	newNode->prev = NULL;

	return (newNode);
}

void	insert_end(struct s_list **head, int value)
{
	int i;
	struct s_list *newNode;

	newNode = create_node(value);

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	struct s_list *temp;

	temp = *head;	
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	
	temp->next = newNode;
	newNode->prev = temp;
	newNode->index = i;
}

int	ft_len_stack(struct s_list *head)
{
	struct s_list *temp;
	int	len_stack;

	temp = head;
	len_stack = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		len_stack++;
	}
	return (len_stack);
}

void	stack_init(struct s_list **head, char **matrix, int arg)
{
	if (arg > 2)
		matrix++;
	while (*matrix != NULL)
	{
		insert_end(head, ft_atoi(*matrix));
		matrix++;
	}
}
