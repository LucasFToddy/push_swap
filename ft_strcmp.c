/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:57:12 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/15 10:58:39 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s2) == 0)
		return (-1);
	while (s1[i] == s2[i] && s1[i])
		i++;

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
