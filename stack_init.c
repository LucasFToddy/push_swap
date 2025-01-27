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

int	stack_init(struct s_list **head, char **matrix, int arg)
{
	if (arg > 2)
		matrix++;
	while (*matrix != NULL)
	{
		if (ft_check_list(head, ft_atoi(*matrix)) == 1)
		{
			printf("numero duplicado!");
			ft_list_free(head);
			return (0);
		}
		insert_end(head, ft_atoi(*matrix));
		matrix++;
	}
	return (1);
}

void	ft_remove(struct s_list **head, int index)
{
	struct s_list *tmp;

	tmp  = *head;
	if (tmp != NULL && tmp->index == index)
	{
		*head = tmp->next;
		free(tmp);
		return;
	}
	
	while (tmp != NULL && tmp->index != index)
		tmp = tmp->next;

	if (tmp == NULL)
		return;

	tmp->prev->next = tmp->next;

	free(tmp);
	return;
}
