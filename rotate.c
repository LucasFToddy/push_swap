/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:42:32 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 17:14:38 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **src, char name_stack)
{
	t_list	*tmp;
	t_list	*end;

	end = *src;
	tmp = *src;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = end;
	end->prev = tmp;
	*src = (*src)->next;
	(*src)->prev = NULL;
	end->next = NULL;
	if (name_stack == 'a')
		ft_printf("ra\n");
	if (name_stack == 'b')
		ft_printf("rb\n");
}

void	ft_reverse_rotate(t_list **src, char name_stack)
{
	t_list	*end;

	end = list_last(*src);
	(*src)->prev = end;
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = *src;
	*src = (*src)->prev;
	if (name_stack == 'a')
		ft_printf("rra\n");
	if (name_stack == 'b')
		ft_printf("rrb\n");
}

void	rr(t_list **a, t_list **b)
{
	ft_rotate(a, 'r');
	ft_rotate(b, 'r');
	ft_printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a, 'r');
	ft_reverse_rotate(b, 'r');
	ft_printf("rrr\n");
}
