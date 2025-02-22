/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:09 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 15:55:32 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("v = %d", temp->data);
		ft_printf("\n");
		temp = temp->next;
	}
	ft_printf("NULL\n");
}

int	ft_len_stack(t_list *head)
{
	t_list	*temp;
	int		len_stack;

	temp = head;
	len_stack = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		len_stack++;
	}
	return (len_stack);
}

t_list	*list_last(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	stack_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
