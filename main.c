/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:31:18 by hclaude           #+#    #+#             */
/*   Updated: 2024/01/15 14:20:26 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;
	// int		fd2;

	fd = open("fichier1.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("%s\n", str);
		free(str);
	}
	printf("%s\n", str);
	close(fd);
}
