/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:53:41 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 20:28:27 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putendl_fd("Error", 2), 1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	else
		different_parameters(argc, &argv);
	if (stack_init(&a, argv) == 0)
	{
		ft_list_free(&a);
		clear_split(argv);
		return (0);
	}
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	ft_list_free(&a);
	clear_split(argv);
}
