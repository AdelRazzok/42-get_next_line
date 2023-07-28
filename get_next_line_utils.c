#include "get_next_line.h"

// Looks for a newline char in a linked list
int	is_newline(t_list *stock)
{
	int		i;
	t_list	*current;

	if (stock == NULL)
		return (0);
	current = get_last(stock);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Returns the last node of a linked list
t_list	*get_last(t_list *stock)
{
	t_list	*current;

	current = stock;
	while (current && current->next)
		current = current->next;
	return (current);
}