/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/05 15:14:30 by hclaude          ###   ########.fr       */
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

	i = 0;
	if (!dst)
		temp = ft_calloc(2, sizeof(char));
	else
	{
		temp = ft_calloc(ft_strlen(dst) + 1, sizeof(char));
		while (dst[i] != '\0')
		{
			temp[i] = dst[i];
			i++;
		}
	}
	temp[i] = c;
	return (temp);
}

void ft_remove(char *lst, int start)
{
	char	*temp_lst;
	int		i;

	i = 0;
	if (lst[start] == '\0')
		ft_bzero(lst, ft_strlen(lst));
	else
	{
		temp_lst = ft_substr(lst, start, ft_strlen(lst + start));
		printf("Liste temporaire = %s\n", temp_lst);
		ft_bzero(lst, ft_strlen(lst));
		ft_memmove(lst, temp_lst, ft_strlen(temp_lst));
		printf("Liste finale = %s\n", lst);
	}
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
		{
			read(fd, buffer, BUFFER_SIZE);
			if (buffer[0] == '\0')
				return (NULL);
			printf("i = %i ; buffer = ''%s''\n", i, buffer);
		}
		if (buffer[i] != '\n' && buffer[i] != '\0')
			return_buffer = put_char_in_buffer(return_buffer, buffer[i]);
		else
		{
			return_buffer = put_char_in_buffer(return_buffer, buffer[i]);
			ft_remove(buffer, i+1);
			printf("Valeur de buffer = %s\nValeur de retour = %s\n", buffer, return_buffer);
			return (return_buffer);
		}
		printf("-Boucle-\n");
		printf("Buffer = %s\n", buffer);
		printf("return_buffer = %s\n", return_buffer);
		printf("--------\n");
		i++;
	}
}
