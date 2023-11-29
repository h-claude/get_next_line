/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/11/29 11:56:25 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE];
	static char *old_buffer;
	static int	i = 0;
	
	if (fd == -1 || read(fd, buffer, BUFFER_SIZE) <= 0)
	{
		if (old_buffer == NULL)
			return (NULL);
		return (old_buffer);
	}
	if (buffer != NULL && old_buffer != NULL)
		get_line(buffer, old_buffer);
	else
		old_buffer = get_futurline(buffer);
		return (ft_substr(buffer, 0, get_backslash(buffer)));
}

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
	dst = 
}