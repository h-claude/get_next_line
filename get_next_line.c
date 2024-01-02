/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2024/01/02 17:05:31 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_backslash(char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i])
	{
		if ('\n' == buffer[i])
			return (i);
		i++;
	}
	return (-1);
}

void	replace(char **buffer)
{
	int		i;
	char	*new_buffer;

	i = is_backslash(*buffer);
	new_buffer = ft_substr(*buffer, i + 1, ft_strlen(*buffer) - i);
	free(*buffer);
	*buffer = new_buffer;
}

int	read_and_get(int fd, char **buffer)
{
	char	*new_str;
	int		empty;
	char	*new_buffer;

	empty = 0;
	new_str = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!new_str)
		return (1);
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
		ft_bzero(new_str, BUFFER_SIZE);
	}
	free(new_str);
	return (empty);
}

char	*get_next_line_part2(int fd, char **buffer)
{
	char	*return_line;

	if (read_and_get(fd, &*buffer) == 0)
	{
		return_line = ft_substr(*buffer, 0, is_backslash(*buffer) + 1);
		replace(&*buffer);
		return (return_line);
	}
	if (*buffer[0] == '\0')
		return_line = NULL;
	else
		return_line = ft_substr(*buffer, 0, ft_strlen(*buffer));
	free(*buffer);
	*buffer = NULL;
	return (return_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer == NULL)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	return (get_next_line_part2(fd, &buffer));
}
