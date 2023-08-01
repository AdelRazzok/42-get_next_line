#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stock;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stock = NULL;
	line = NULL;
	read_and_stock(fd, &stock);
	if (stock == NULL)
		return (NULL);
	extract_line(stock, &line);
	clear_stock(&stock);
	return (line);
}

// Reads the document and stocks the line when it finds a newline char
void	read_and_stock(int fd, t_list **stock)
{
	char	*buff;
	int	nb_char;

	nb_char = 1;
	while (!is_newline(*stock) && nb_char != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		nb_char = (int) read(fd, buff, BUFFER_SIZE);
		if ((*stock == NULL && nb_char == 0) || nb_char == -1)
		{
			free(buff);
			return ;
		}
		buff[nb_char] = '\0';
		add_to_stock(fd, buff, nb_char);
		free(buff);
	}
}

// Fills the list with the buffer
void	add_to_stock(t_list **stock, char *buff, int nb_char)
{
	int		i;
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (nb_char + 1));
	if (!new_node->content)
		return ;
	i = 0;
	while (buff[i] && i < nb_char)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stock == NULL)
	{
		*stock = new_node;
		return ;
	}
	last_node = get_last(*stock);
	last_node->next = new_node;
}

// Extracts all characters until the \n (included) from the list to the output line
void	extract_line(t_list *stock, char **line)
{
	int	i;
	int	j;

	if (stock == NULL)
		return ;
	generate_line(line, stock);
	if (*line == NULL)
		return ;
	j = 0;
	while (stock)
	{
		i = 0;
		while (stock->content[i])
		{
			if (stock->content[i] == '\n')
			{
				*line[j++] = stock->content[i];
				break;
			}
			*line[j++] = stock->content[i++];
		}
		stock = stock->next;
	}
	*line[j] = '\0';
}

void	clear_stash(t_list **stock)
{
	
}
