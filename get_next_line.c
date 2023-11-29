/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/11/29 12:49:50 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int get_backslash(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0' || str[i] != '\n')
		i++;
	return (i);
}

static char *get_line(char *newbuffer, char *oldbuffer)
{
	char	*dst;
	int		len;

	len = ft_strlen(oldbuffer) + get_backslash(newbuffer);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcat(dst, oldbuffer, ft_strlen(oldbuffer));
	ft_strlcat(dst, newbuffer, get_backslash(newbuffer));
	free(oldbuffer);
	return (dst);
}

static char *get_futurline(char *buffer)
{
	int	start;
	int i;
	char *newbuffer;
	
	start = get_backslash(buffer) + 1;
	i = start;
	while (buffer[i] != '\0' || buffer[i] != '\n')
		i++;
	newbuffer = ft_calloc(i + 1, sizeof(char));
	if (!newbuffer)
		return (NULL);
	i = 0;
	while (buffer[start] != '\0' || buffer[start] != '\n')
	{
		newbuffer[i] = buffer[start];
		i++;
		start++;
	}
	return(newbuffer);
}

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE];
	static char *old_buffer;
	char *tempbuffer;

	if (fd == -1 || read(fd, buffer, BUFFER_SIZE) <= 0)
	{
		if (old_buffer == NULL)
			return (NULL);
		return (old_buffer);
	}
	if (buffer && old_buffer)
	{
		tempbuffer = old_buffer;
		
		get_line(buffer, old_buffer);
	}
	else
	{
		old_buffer = get_futurline(buffer);
		return (ft_substr(buffer, 0, get_backslash(buffer)));
	}
}
