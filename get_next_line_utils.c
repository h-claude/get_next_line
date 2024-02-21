/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:01 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/21 18:25:23 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (0 != s[i])
		i++;
	return (i);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[y++] = s1[i++];
	i = 0;
	while (s2[i])
		str[y++] = s2[i++];
	str[y] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	lenght;

	i = 0;
	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (start >= lenght)
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	if (len + start > lenght)
		len = lenght - start;
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
