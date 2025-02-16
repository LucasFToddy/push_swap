/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:53:41 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/08 18:40:51 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	char	*str;
	int	i;

	a = NULL;
	str = NULL;
	b = NULL;
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
	if (!stack_sorted(a))
	{
		sort_stack(&a, &b);
	}
	ft_list_free(&a);
	ft_list_free(&b);
	// display_list(a);
	// clear_split(argv);
	// // ft_list_free(&a);
	// //ft_rotate(&a);	
	// //display_list(a);
	// //ft_reverse_rotate(&a);
	// //display_list(a);
	// ft_push(&a, &b, "b");
	// ft_push(&a, &b, "b");
	// // ft_push(&a, &b, "b");
	// printf("print stack A\n");
	// display_list(a);
	// printf("fim stack A ------\n");
	// printf("print stack B\n");
	// display_list(b);
	// printf("fim stack B ------\n");
	// ft_push(&a, &b, "b");
	// printf("print stack A\n");
	// display_list(a);
	// printf("fim stack A ------\n");
	// printf("print stack B\n");
	// display_list(b);
	// printf("fim stack B ------\n");
	// ft_swap(a);
	// display_list(a);
	// display_list(a);
	// display_list(b);
}
