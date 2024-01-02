/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:31:18 by hclaude           #+#    #+#             */
/*   Updated: 2024/01/02 15:23:32 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char *str;
	char *test;

	fd = open("fichier1.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("RETURN = %s\n", str);
	free(str);
	// str = get_next_line(fd);
	// printf("RETURN = %s\n", str);
	// free(str);	str = get_next_line(fd);
	// printf("RETURN = %s\n", str);
	// free(str);	str = get_next_line(fd);
	// printf("RETURN = %s\n", str);
	// free(str);	str = get_next_line(fd);
	// printf("RETURN = %s\n", str);
	// free(str);	str = get_next_line(fd);
	// printf("RETURN = %s\n", str);
	// free(str);	str = get_next_line(fd);
	// printf("RETURN = %s\n", str);
	// free(str);	str = get_next_line(fd);
	// printf("RETURN = %s\n", str);
	// free(str);
	close(fd);
}
