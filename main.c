#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("fichier1.txt", O_RDONLY);
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	// printf("---Nouvelle boucle---\n\n");
	close(fd);
}
