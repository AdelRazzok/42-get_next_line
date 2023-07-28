#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char				*content;
	struct s_list	*next;
}						t_list;

char	*get_next_line(int fd);
void	read_and_stock(int fd, t_list **stock);
int	is_newline(t_list *stock);

#endif