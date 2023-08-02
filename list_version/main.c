#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("../file1.txt", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (1);
	printf("%s", line);
	free(line);

	fd = open("../file2.txt", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (1);
	printf("%s", line);
	free(line);

	fd = open("../file1.txt", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (1);
	printf("%s", line);
	free(line);

	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		break;
	// 	printf("%s", line);
	// 	free(line);
	// }
}
