

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("arquivo1.txt", O_RDONLY);
	fd2 = open("arquivo2.txt", O_RDONLY);
	fd3 = open("arquivo3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);

	line = get_next_line(fd1);
	printf("FD1 -> %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("FD2 -> %s", line);
	free(line);

	line = get_next_line(fd1);
	printf("FD1 -> %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("FD3 -> %s", line);
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);
}
