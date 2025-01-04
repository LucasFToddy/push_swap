/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:12:42 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/04 13:37:26 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

struct s_list *createNode(int value)
{
	struct s_list *newNode = (struct s_list *)malloc(sizeof(struct s_list));
	if (!newNode)
		return (NULL);

	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;

	return (newNode);
}

void	insertEnd(struct s_list **head, int value)
{
	struct s_list *newNode = createNode(value);

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	struct s_list *temp = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = newNode;
	newNode->prev = temp;
}

void	displayList(struct s_list *head)
{
	struct s_list *temp = head;

	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() 
{
    struct s_list *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Lista original:\n");
    displayList(head);
}
