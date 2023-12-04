/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/04 13:14:54 by hclaude          ###   ########.fr       */
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

static char *get_line(char *oldbuffer, char *buffer)
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

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static char *old_buffer;
	char *return_list;

	if (fd == -1)
		return (NULL);
	if (!buffer)
		read(fd, buffer, BUFFER_SIZE);
	else
		old_buffer = ft_strdup(buffer);
	return_list = get_line(old_buffer, buffer);
	
	
}
