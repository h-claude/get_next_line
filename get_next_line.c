/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/05 17:20:35 by hclaude          ###   ########.fr       */
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
	char 	*return_string;
	int		i;

	i = 0;
	if (!dst)
		return_string = ft_calloc(2, sizeof(char));
	else
	{
		return_string = ft_calloc(ft_strlen(dst) + 2, sizeof(char));
		while (dst[i] != '\0')
		{
			return_string[i] = dst[i];
			i++;
		}
	}
	return_string[i] = c;
	return (return_string);
}

void ft_remove(char *lst, int start)
{
	char	*temp_lst;

	if (lst[start] == '\0')
		ft_bzero(lst, ft_strlen(lst));
	else
	{
		start++;
		temp_lst = ft_substr(lst, start, ft_strlen(lst + start));
		printf("Liste temporaire = %s\n", temp_lst);
		ft_memmove(lst, temp_lst, ft_strlen(temp_lst));
		ft_bzero(lst + start, ft_strlen(lst) - start);
		printf("Liste finale = %s\n", lst);
	}
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char		*return_buffer;
	int			i;

	i = 0;
	if (fd == -1)
		return (NULL);
	return_buffer = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			read(fd, buffer, BUFFER_SIZE);
			if (buffer[0] == '\0')
				return (NULL);
			i = 0;
			printf("i = %i ; buffer = ''%s''\n", i, buffer);
		}
		if (buffer[i] != '\n' && buffer[i] != '\0')
			return_buffer = put_char_in_buffer(return_buffer, buffer[i]);
		else
		{
			return_buffer = put_char_in_buffer(return_buffer, buffer[i]);
			ft_remove(buffer, i);
			printf("Valeur de buffer = %s\nValeur de retour = %s\n", buffer, return_buffer);
			if (return_buffer[ft_strlen(return_buffer)-1] == '\n' || return_buffer[ft_strlen(return_buffer)-1] == '\0')
				return (return_buffer);
		}
		printf("-Boucle-\n");
		printf("Buffer = %s\n", buffer);
		printf("return_buffer = %s\n", return_buffer);
		printf("--------\n");
		i++;
	}
}
