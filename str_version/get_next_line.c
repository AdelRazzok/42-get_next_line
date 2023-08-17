/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:17:50 by arazzok           #+#    #+#             */
/*   Updated: 2023/08/17 15:20:57 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stock = read_and_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = extract_line(stock);
	stock = clear_stock(stock);
	return (line);
}

char	*read_and_stock(int fd, char *stock)
{
	char	*buff;
	int		rd_chars;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	rd_chars = 1;
	while (!is_newline(stock) && rd_chars != 0)
	{
		rd_chars = (int)read(fd, buff, BUFFER_SIZE);
		if (rd_chars == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_chars] = '\0';
		stock = ft_strjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*extract_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] && stock[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear_stock(char * stock)
{
	int		i;
	int		j;
	char	*clean;

	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	clean = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!clean)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		clean[j++] = stock[i++];
	clean[j] = '\0';
	free(stock);
	return (clean);
}
