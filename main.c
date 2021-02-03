#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *line;
	int check;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while ((check = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);

	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
