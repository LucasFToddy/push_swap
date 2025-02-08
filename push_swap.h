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

# include <stdlib.h>
# include <unistd.h>


# include <stdio.h>

typedef struct s_list
{
	int	data;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*list_last(t_list *head);
t_list	*create_node(int value);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int	ft_atoi(const char *nptr);
int	ft_len_stack(t_list *head);
int	ft_check_list(t_list **head, int value);
int	ft_check_str(char *str);
int	stack_init(t_list **head, char **matrix, int arg);
int	ft_strcmp(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int	insert_end(t_list **head, int value);
int	insert_back(t_list **head, int value);
void	ft_remove(t_list **head);
void	ft_push(t_list **a, t_list **b, char *str);
void	display_list(t_list *head);
void	ft_putstr(char *str);
void	ft_swap(t_list *head);
void	ft_list_free(t_list **head);
void	clear_split(char **str);
void	ft_rotate(t_list **src);
void	ft_reverse_rotate(t_list **src);
void	set_target(t_list **a, t_list **b);

#endif
