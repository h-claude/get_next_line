/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/04 19:23:46 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*target;

	i = 0;
	target = s;
	while (i < n)
	{
		target[i] = '\0';
		i++;
	}
}

char *put_char_in_buffer(char *dst, char c)
{
	char 	*temp;
	int		i;

	temp = ft_calloc(ft_strlen(dst) + 2, sizeof(char));
	while (dst[i] != '\0')
	{
		temp[i] = dst[i];
		i++;
	}
	temp[i] = c;
	return (temp);
}

void ft_remove(char *lst, int start)
{
	char	*temp_lst;
	int		i;

	i = 0;
	temp_lst = ft_substr(lst, start, ft_strlen(lst + start));
	ft_bzero(lst, ft_strlen(lst));
	ft_memmove(lst, temp_lst, ft_strlen(temp_lst));
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char		*return_buffer;
	int			i;

	i = 0;
	if (fd == -1)
		return (NULL);
	while (1)
	{
		if (buffer[0] == '\0')
			if (read(fd, buffer, BUFFER_SIZE) == 0);
				if (!return_buffer)
					return (NULL); // Pour voir si il y a plus rien a lire
		if (return_buffer[i] == '\n' || return_buffer[i] == '\0') // On teste si on est en fin de ligne ou de fichier
		{
			if (return_buffer[i] == '\0') // Si fin de fichier
			{
				ft_bzero(buffer, ft_strlen(buffer));	
				return (return_buffer);
			}
			ft_remove(buffer, i); // Si fin de ligne
			return (return_buffer);
		}
		if 
		
	}
}
