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

void	display_list(t_list *head)
{
	t_list *temp = head;

	while (temp != NULL)
	{
		printf("value = %d\n", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void	ft_swap(t_list *head)
{
	t_list *tmp_1;
	t_list *tmp_2;
	int	value_tmp;
	int	len_stack;

	len_stack = ft_len_stack(head);
	if (len_stack <= 1)
		return;
	tmp_1 = head;
	tmp_2 = tmp_1->next;
	value_tmp = tmp_1->data;
	tmp_1->data = tmp_2->data;
	tmp_2->data = value_tmp;
	return;
}

void	ft_push(t_list **src, t_list **dest)
{
	t_list *tmp;
	int	len_stack;

	len_stack = ft_len_stack(*src);
	tmp = *src;
	if (len_stack <= 1)
		return;
	insert_end(dest, tmp->data);
	ft_remove(src, tmp->index);
	//printf("P%s\n", );
}

void	ft_rotate(t_list **src)
{
	t_list *tmp;
	t_list *end;

	end = *src;
	tmp = *src;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = end;
	end->prev = tmp;
	*src = (*src)->next;
	(*src)->prev = NULL;
	end->next = NULL;
}

void	ft_reverse_rotate(t_list **src)
{
	t_list *tmp;
	t_list *end;

	tmp = *src;
	end = list_last(*src);
	(*src)->prev = end;
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = *src;
	*src = (*src)->prev;
}
