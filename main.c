/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:31:18 by hclaude           #+#    #+#             */
/*   Updated: 2024/01/04 18:18:26 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;
	char	*test;
	int		fd2;

	fd = open("fichier1.txt", O_RDONLY);
	fd2 = open("fichier.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("RETURN = %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("RETURN fd2 = %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("RETURN = %s\n", str);
	free(str);
	(printf("CLOSE FD %i\n", close(fd)));
	str = get_next_line(fd2);
	printf("RETURN fd2 = %s\n", str);
	free(str);
	open("fichier1.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("RETURN = %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("RETURN fd2 = %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("RETURN = %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("RETURN fd2 = %s\n", str);
	free(str);
	close(fd);
}
