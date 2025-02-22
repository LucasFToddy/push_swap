/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:32:53 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 17:15:57 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max_value(t_list *a)
{
	t_list	*max_value_node;
	t_list	*tmp;

	max_value_node = a;
	tmp = a;
	while (tmp)
	{
		if (tmp->data > max_value_node->data)
			max_value_node = tmp;
		tmp = tmp->next;
	}
	return (max_value_node);
}

void	sort_three(t_list **a)
{
	t_list	*max_value_node;

	max_value_node = find_max_value(*a);
	if (max_value_node == *a)
		ft_rotate(a, 'a');
	else if ((*a)->next == max_value_node)
		ft_reverse_rotate(a, 'a');
	if ((*a)->data > (*a)->next->data)
		ft_swap(*a, 'a');
}

t_list	*find_min_value(t_list *a)
{
	t_list	*min_value_node;
	t_list	*tmp;

	min_value_node = a;
	tmp = a;
	while (tmp)
	{
		if (tmp->data < min_value_node->data)
			min_value_node = tmp;
		tmp = tmp->next;
	}
	return (min_value_node);
}
