/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:00:47 by lucas-do          #+#    #+#             */
/*   Updated: 2025/01/04 14:37:29 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	data;
	int	index;
	struct	s_list *next;
	struct	s_list *prev;
}	t_list;

char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
int	ft_len_stack(struct s_list *head);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	stack_init(struct s_list **head, char **matrix, int arg);
void	insert_end(struct s_list **head, int value);
void	ft_push(struct s_list **src, struct s_list **dest);
void	display_list(struct s_list *head);
void	ft_putstr(char *str);
void	ft_swap(struct s_list *head);

#endif
