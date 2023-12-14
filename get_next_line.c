/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/14 18:13:13 by hclaude          ###   ########.fr       */
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

void replace(char **buffer)
{
	int i;
	char *new_buffer;

	i = is_backslash(*buffer);
	new_buffer = ft_substr(*buffer, is_backslash(*buffer) + 1, ft_strlen(*buffer) - i);
	free(*buffer);
	*buffer = new_buffer;
}

int read_and_get(int fd, char **buffer)
{
	char	new_str[BUFFER_SIZE];
	int		empty;
	char	*new_buffer;
	
	empty = 0;
	while (is_backslash(*buffer) == -1 && empty == 0)
	{
		if (read(fd, new_str, BUFFER_SIZE) == 0)
				empty = 1;
		else
		{
			new_buffer = ft_strjoin(*buffer, new_str);
			free(*buffer);
			*buffer = new_buffer;
		}
		// printf("Dans read and get :\n buffer = %s\n new_str == %s\n", *buffer, new_str);
		ft_bzero(new_str, BUFFER_SIZE);
	}
	if (empty == 1)
		return (1);
	else
		return (0);
}

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char 		*return_line;

	if (buffer == NULL)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (fd == -1 || read(fd, buffer, 0) == -1)
		return (NULL);
	if (read_and_get(fd, &buffer) == 0)
	{
		return_line = ft_substr(buffer, 0, is_backslash(buffer) + 1);
		replace(&buffer);
		// printf("La chaine buffer = %s\n La chaine return_line = %s\n", buffer, return_line);
		return (return_line);
	}
	// printf("Dans GNL = %s\n", buffer);
	return_line = ft_substr(buffer, 0, ft_strlen(buffer));
	free(buffer);
	return (return_line);
}
