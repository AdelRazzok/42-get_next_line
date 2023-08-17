/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:00:28 by arazzok           #+#    #+#             */
/*   Updated: 2023/08/03 15:06:40 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	read_and_stock(int fd, t_list **stock);
void	add_to_stock(t_list **stock, char *buff, int nb_char);
void	extract_line(t_list *stock, char **line);
void	clear_stock(t_list **stock);
int		is_newline(t_list *stock);
t_list	*get_last(t_list *stock);
void	generate_line(char **line, t_list *stock);
void	free_stock(t_list *stock);
int		ft_strlen(const char *str);

#endif