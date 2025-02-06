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

t_list *create_node(int value)
{
	t_list *newNode;

	newNode = (t_list *)malloc(sizeof(t_list));
	if (!newNode)
		return (NULL);

	newNode->data = value;
	newNode->index = 0;
	newNode->next = NULL;
	newNode->prev = NULL;

	return (newNode);
}

int	insert_end(t_list **head, int value)
{
	int i;
	t_list *newNode;

	newNode = create_node(value);
	if (newNode == NULL)
		return 0;

	if (*head == NULL)
	{
		*head = newNode;
		return 1;
	}
	t_list *temp;

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
	return 1;
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

void	ft_remove(t_list **head, int index)
{
	t_list *tmp;

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
