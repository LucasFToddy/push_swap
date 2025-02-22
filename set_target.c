/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:56:09 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 17:13:19 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*verify_next_value(t_list **stack, int value)
{
	t_list	*tmp;
	t_list	*next_value;
	t_list	*max_value;

	tmp = *stack;
	next_value = NULL;
	max_value = *stack;
	while (tmp != NULL)
	{
		if (tmp->data > max_value->data)
			max_value = tmp;
		if (tmp->data < value)
		{
			if (next_value == NULL)
				next_value = tmp;
			if (tmp->data > next_value->data)
				next_value = tmp;
		}
		tmp = tmp->next;
	}
	if (next_value == NULL)
		return (max_value);
	return (next_value);
}

t_list	*verify_next_value_b(t_list **stack, int value)
{
	t_list	*tmp;
	t_list	*next_value;
	t_list	*max_value;

	tmp = *stack;
	next_value = NULL;
	max_value = *stack;
	while (tmp != NULL)
	{
		if (tmp->data < max_value->data)
			max_value = tmp;
		if (tmp->data > value)
		{
			if (next_value == NULL)
				next_value = tmp;
			if (tmp->data < next_value->data)
				next_value = tmp;
		}
		tmp = tmp->next;
	}
	if (next_value == NULL)
		return (max_value);
	return (next_value);
}

void	set_target(t_list **a, t_list **b, char name_stack)
{
	t_list	*tmp;

	if (name_stack == 'a')
	{
		tmp = *a;
		while (tmp != NULL)
		{
			tmp->target = verify_next_value(b, tmp->data);
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = *b;
		while (tmp != NULL)
		{
			tmp->target = verify_next_value_b(a, tmp->data);
			tmp = tmp->next;
		}
	}
}
