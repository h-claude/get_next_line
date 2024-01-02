/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2024/01/02 14:21:33 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_backslash(char *buffer)
{
	int	i;

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

char	*read_and_get(int fd, char **buffer)
{
	char	new_str[BUFFER_SIZE + 1];
	char	*new_buffer;

	ft_bzero(new_str, BUFFER_SIZE + 1);
	while (1)
	{
		if (read(fd, new_str, BUFFER_SIZE) == 0 && *buffer[0] == '\0')
		{
			printf("caca\n");
			free(*buffer);
			*buffer = NULL;
			return(new_buffer);
		}
		else if (is_backslash(new_str) > -1)
		{
			printf("Avant substr = %s\nPROUT\n", new_buffer);
			new_buffer = ft_strjoin(new_buffer, ft_substr(new_str, 0, is_backslash(new_str) + 1));
			printf("new-str = %s\nNEW BUFF = %s\n", new_str, new_buffer);
			free(*buffer);
			*buffer = ft_substr(new_str, is_backslash(new_str) + 1, BUFFER_SIZE - is_backslash(new_str));
			printf("buffer = %s\n", *buffer);
			return (new_buffer);
		}
		new_buffer = ft_strjoin(new_buffer, new_str);
		printf("New_buffer = %s\n", new_buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*return_line;

	printf("BUFF GNL = %s\n", buffer);
	if (fd == -1 || read(fd, buffer, 0) == -1)
	{
		if (buffer == NULL) 
			free(buffer);
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	return (read_and_get(fd, &buffer));
}
