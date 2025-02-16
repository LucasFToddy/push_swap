/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:59:33 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/15 19:59:34 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_b(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target(&a, &b, 'b');
}

void	min_on_top(t_list **a)
{
	while ((*a)->data != find_min_value(*a)->data)
	{
		if (find_min_value(*a)->top_mid)
			ft_rotate(a, 'a');
		else
			ft_reverse_rotate(a, 'a');
	}
}