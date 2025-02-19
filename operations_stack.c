/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:48:56 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/13 19:35:23 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *head, char name_stack)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		value_tmp;
	int		len_stack;

	len_stack = ft_len_stack(head);
	if (len_stack <= 1)
		return ;
	tmp_1 = head;
	tmp_2 = tmp_1->next;
	value_tmp = tmp_1->data;
	tmp_1->data = tmp_2->data;
	tmp_2->data = value_tmp;
	if (name_stack == 'a')
		printf("sa\n");
	if (name_stack == 'b')
		printf("sb\n");
	return ;
}

void	ft_push(t_list **a, t_list **b, char *str)
{
	t_list	*tmp;
	int		len_stack;

	if (!ft_strcmp(str, "b"))
	{
		len_stack = ft_len_stack(*a);
		tmp = *a;
		if (len_stack <= 1)
			return ;
		insert_back(b, tmp->data);
		ft_remove(a);
	}
	if (!ft_strcmp(str, "a"))
	{
		len_stack = ft_len_stack(*b);
		tmp = *b;
		if (len_stack < 1)
			return ;
		insert_back(a, tmp->data);
		ft_remove(b);
	}
	printf("p%s\n", str);
}
