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
	// struct s_list *b;
	char	*str;
	int	i;

	a = NULL;
	str = NULL;
	// b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	else
	{
		i = 0;
		while(i < argc)
		{
			str = ft_strjoin(str, argv[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
		argv = ft_split(str, ' ');
		free(str);
	}
	if (stack_init(&a, argv, argc) == 0)
	{
		clear_split(argv);
		ft_list_free(&a);
		return 0;
	}
	display_list(a);
	clear_split(argv);
	ft_list_free(&a);
	// ft_list_free(&a);
	// ft_swap(a);
	// display_list(a);
	// ft_push(&a, &b);
	// display_list(a);
	// display_list(b);
}
