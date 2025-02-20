/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:56:29 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/15 10:56:31 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		mid;

	i = 0;
	mid = ft_len_stack(stack) / 2;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i;
		if (i <= mid)
			tmp->top_mid = 1;
		else
			tmp->top_mid = 0;
		tmp = tmp->next;
		i++;
	}
}

void	count_cost_push(t_list *a, t_list *b)
{
	int		len_a;
	int		len_b;

	len_a = ft_len_stack(a);
	len_b = ft_len_stack(b);
	while (a)
	{
		a->cost_push = a->index;
		if (!(a->top_mid))
			a->cost_push = len_a - a->index;
		if (a->target->top_mid)
			a->cost_push += a->target->index;
		else
			a->cost_push += len_b - a->target->index;
		a = a->next;
	}
}

void	set_cheaper(t_list *stack)
{
	t_list	*node_cheaper;
	int		cheaper_value;

	if (!stack)
		return ;
	cheaper_value = INT_MAX;
	while (stack)
	{
		if (stack->cost_push < cheaper_value)
		{
			cheaper_value = stack->cost_push;
			node_cheaper = stack;
		}
		stack = stack->next;
	}
	node_cheaper->cheaper = 1;
}

t_list	*get_cheaper(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->cheaper)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	init_stack_a(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target(&a, &b, 'a');
	count_cost_push(a, b);
	set_cheaper(a);
}
