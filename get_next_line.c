#include "get_next_line.h"

void	read_and_stock(int fd, t_list **stock)
{
	char	*buff;
	int	nb_char;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	nb_char = 1;
	while (is_newline(*stock) && nb_char != 0)
	{
		nb_char = (int) read(fd, buff, BUFFER_SIZE);
		if ((*stock == NULL && nb_char == 0) || nb_char == -1)
		{
			free(buff);
			return ;
		}
		buff[nb_char] = '\0';
	}
}

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
	return (line);
}
