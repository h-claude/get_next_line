#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("fichier.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
