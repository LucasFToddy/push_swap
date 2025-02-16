/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:00:47 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/13 19:35:43 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# ifndef INT_MAX

#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN

#  define INT_MIN -2147483648
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				cost_push;
	int				top_mid;
	int				cheaper;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*list_last(t_list *head);
t_list				*create_node(int value);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char *s1, char *s2);
int					ft_atoi(const char *nptr);
int					ft_len_stack(t_list *head);
int					ft_check_list(t_list **head, int value);
int					ft_check_str(char *str);
int					stack_init(t_list **head, char **matrix, int arg);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					insert_end(t_list **head, int value);
int					insert_back(t_list **head, int value);
void				ft_remove(t_list **head);
void				ft_push(t_list **a, t_list **b, char *str);
void				display_list(t_list *head);
void				ft_putstr(char *str);
void				ft_swap(t_list *head);
void				ft_list_free(t_list **head);
void				clear_split(char **str);
void				ft_rotate(t_list **src, char name_stack);
void				rr(t_list **a, t_list **b);
void				rrr(t_list **a, t_list **b);
void				ft_reverse_rotate(t_list **src, char name_stack);
void				set_target(t_list **a, t_list **b, char name_stack);
void				indexing_stack(t_list **head);
void				init_stack_a(t_list *a, t_list *b);
void				init_stack_b(t_list *a, t_list *b);
t_list				*get_cheaper(t_list *stack);
void				set_index(t_list *stack);
void				prep_to_push(t_list **stack, t_list *node_top,
						char name_stack);
int					stack_sorted(t_list *stack);
void				sort_stack(t_list **a, t_list **b);
t_list				*find_max_value(t_list *a);
t_list				*find_min_value(t_list *a);
void				sort_three(t_list **a);
void				min_on_top(t_list **a);

#endif
