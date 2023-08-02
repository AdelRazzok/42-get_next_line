#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*stock;
	char				*line;

	stock = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_stock(fd, &stock);
	if (!stock)
		return (NULL);
	extract_line(stock, &line);
	clear_stock(&stock);
	if (line[0] == '\0')
	{
		free_stock(stock);
		stock = NULL;
		free(line);
		return (NULL);
	}
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
		nb_char = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stock == NULL && nb_char == 0) || nb_char == -1)
		{
			free(buff);
			return ;
		}
		buff[nb_char] = '\0';
		add_to_stock(stock, buff, nb_char);
		free(buff);
	}
}

// Fills the end of the list with the buffer
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

	if (!stock)
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
				(*line)[j++] = stock->content[i];
				break ;
			}
			(*line)[j++] = stock->content[i++];
		}
		stock = stock->next;
	}
	(*line)[j] = '\0';
}

// Clears the list of all chars already returned in the output line
void	clear_stock(t_list **stock)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!stock || !clean_node)
		return ;
	clean_node->next = NULL;
	last_node = get_last(*stock);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content && last_node->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last_node->content) - i) + 1));
	if (!clean_node->content)
		return ;
	j = 0;
	while (last_node->content[i])
		clean_node->content[j++] = last_node->content[i++];
	clean_node->content[j] = '\0';
	free_stock(*stock);
	*stock = clean_node;
}
