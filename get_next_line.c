/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/11/28 15:37:57 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static int		i = 0;
	int				start;
	char			*return_buffer;

	start = i;	
	if (fd == -1 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	printf("Le fichier ressemble a ca : || %s ||\n", buffer);
	// printf("Voir si fd : %d est correct\n", fd);
	while(buffer[i] != '\n' && buffer[i])
	{
		printf("Parcours dans buffer i : '%c'\n", buffer[i]);
		i++;
	}
	return_buffer = ft_substr(buffer, i+1, ft_strlen(buffer) - i);
	printf("New buffer : ''%s''\n", return_buffer);
	return (ft_substr(buffer, start, i));
}
