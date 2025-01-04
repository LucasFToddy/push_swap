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
#include <stdio.h>

struct s_list *createNode(int value)
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

void	insertEnd(struct s_list **head, int value)
{
	int i;
	struct s_list *newNode;

	newNode = createNode(value);

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

void	displayList(struct s_list *head)
{
	struct s_list *temp = head;

	while (temp != NULL)
	{
		printf("value = %d index = %d -> ", temp->data, temp->index);
		temp = temp->next;
	}
	printf("NULL\n");
}

void	stack_init(struct s_list **head, char **matrix, int arg)
{
	if (arg > 2)
		matrix++;
	while (*matrix != NULL)
	{
		insertEnd(head, ft_atoi(*matrix));
		matrix++;
	}
}

int	main(int argc, char **argv)
{
	struct s_list *a;

	a = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv, argc);
	displayList(a);
}

// int main() 
// {
//     struct s_list *head = NULL;

//     insertEnd(&head, 10);
//     insertEnd(&head, 20);
//     insertEnd(&head, 30);
//     insertEnd(&head, 40);

//     printf("Lista original:\n");
//     displayList(head);
// }
