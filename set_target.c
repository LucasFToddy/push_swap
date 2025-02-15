#include "push_swap.h"

t_list	*verify_next_value(t_list **b, int value)
{
	t_list	*tmp;
	t_list	*next_value;
	t_list	*max_value;

	tmp = *b;
	next_value = NULL;
	max_value = *b;
	while (tmp != NULL)
	{
		if (tmp->data > max_value->data)
			max_value = tmp;
		if (tmp->data < value)
		{
			if (next_value == NULL)
				next_value = tmp;
			if (tmp->data > next_value->data)
				next_value = tmp;
		}
		tmp = tmp->next;
	}
	if (next_value == NULL)
		return (max_value);
	return (next_value);
}

void	set_target(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		tmp->target = verify_next_value(b, tmp->data);
		tmp = tmp->next;
	}
}
