/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:26:54 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/15 12:26:56 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_list **a, t_list **b, t_list *node_cheaper)
{
	while (*b != node_cheaper->target && *a != node_cheaper)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	reverse_rotate_both(t_list **a, t_list **b, t_list *node_cheaper)
{
	while (*b != node_cheaper->target && *a != node_cheaper)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*node_cheaper;

	node_cheaper = get_cheaper(*a);
	if (node_cheaper->top_mid && node_cheaper->target->top_mid)
		rotate_both(a, b, node_cheaper);
	else if (!(node_cheaper->top_mid) && !(node_cheaper->target->top_mid))
		reverse_rotate_both(a, b, node_cheaper);
	prep_to_push(a, node_cheaper, 'a');
	prep_to_push(b, node_cheaper->target, 'b');
	ft_push(a, b, 'b');
}

static void	move_b_to_a(t_list **a, t_list **b)
{
	prep_to_push(a, (*b)->target, 'a');
	ft_push(a, b, 'a');
}

void	sort_stack(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_len_stack(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		ft_push(a, b, 'b');
	if (len_a-- > 3 && !stack_sorted(*a))
		ft_push(a, b, 'b');
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}
