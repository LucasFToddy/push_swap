/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:53:41 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/13 17:57:56 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	struct s_list *a;
	struct s_list *b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	if (stack_init(&a, argv, argc) == 0)
		return 0;
	display_list(a);
	// ft_swap(a);
	// display_list(a);
	// ft_push(&a, &b);
	// display_list(a);
	// display_list(b);
}
