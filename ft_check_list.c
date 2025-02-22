/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:49:19 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 20:21:54 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplic(t_list **head, int value)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->data == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_error(t_list **head, char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (ft_putendl_fd("Error", 2), 0);
	if (ft_check_duplic(head, (int)nbr))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (ft_check_str(str))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}

void	ft_list_free(t_list **head)
{
	t_list	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}
