/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/04 15:21:03 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *get_line(char *oldbuffer, char *buffer)
{
	
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
	char *old_buffer;
	char *return_list;

	if (fd == -1)
		return (NULL);
	if (!buffer)
		read(fd, buffer, BUFFER_SIZE);
	else
	{
		old_buffer = ft_strdup(buffer);
		read(fd, buffer, BUFFER_SIZE);
	}
	return_list = get_line(old_buffer, buffer);
}
