#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char buffer[10];
	int fd;
	char *test;
	fd = open("fichier.txt", O_RDONLY);
	printf("%li\n", read(fd, buffer, 10));
	printf("%s\n", buffer);
	read(fd, buffer, 10);
	printf("%s\n", buffer);
	char test = "salut";
	if (!test)
		*test = *buffer;
	printf("%s\n", test);
}