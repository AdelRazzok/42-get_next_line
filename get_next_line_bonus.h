/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:18:08 by arazzok           #+#    #+#             */
/*   Updated: 2023/08/17 17:15:41 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 2048
# endif

char	*get_next_line(int fd);
char	*read_and_stock(int fd, char *stock);
char	*extract_line(char *stock);
char	*clear_stock(char *stock);
int		is_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif