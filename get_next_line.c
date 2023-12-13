/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/13 19:00:30 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int is_backslash(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void replace(char *buffer)
{
	int i;

	i = is_backslash(buffer);
	buffer = ft_substr(buffer, is_backslash(buffer), ft_strlen(buffer) - i);
}

int read_and_get(int fd, char **buffer)
{
	char	new_str[BUFFER_SIZE];
	int		empty;
	
	empty = 0;
	while (is_backslash(*buffer) == -1 && empty == 0)
	{
		if (read(fd, new_str, BUFFER_SIZE) == 0)
				empty = 1;
		else
			*buffer = ft_strjoin(*buffer, new_str);
		printf("Dans read and get :\n buffer = %s\n new_str == %s\n", *buffer, new_str);
	}
	if (empty == 1)
		return (1);
	else
	{
		return (0);
	}
}

// la fonction is_backslash renvera la position du \n sinon renvera -1

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char 		*return_line;

	if (fd == -1 || read(fd, buffer, 0) == -1)
		return (NULL);
	if (read_and_get(fd, &buffer) == 0)
	{
		return_line = ft_substr(buffer, 0, is_backslash(buffer));
		replace(buffer);
		printf("La chaine buffer = %s\n La chaine return_line = %s\n", buffer, return_line);
		return (return_line);
	}
	printf("Dans GNL = %s\n", buffer);
	return (buffer);
}