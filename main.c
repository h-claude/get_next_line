/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:31:18 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/21 19:31:19 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("fichier1.txt", O_RDONLY);
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	printf("---Nouvelle boucle---\n\n");
	printf("RETURN = %s\n", get_next_line(fd));
	close(fd);
}
