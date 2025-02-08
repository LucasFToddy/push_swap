#include "push_swap.h"

int	insert_end(t_list **head, int value)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = create_node(value);
	if (new_node == NULL)
		return (0);
	if (*head == NULL)
	{
		*head = new_node;
		return (1);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
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