/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:49:19 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/13 19:52:06 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_list(struct s_list **head, int value)
{
	struct s_list *tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->data == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return(0);
		i++;
	}
	return (1);
}

int	ft_check(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (!(ft_check_str(matrix[i])))
			return (1);
	}
	return (0);
}

void	ft_list_free(struct s_list **head)
{
	struct s_list *tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
