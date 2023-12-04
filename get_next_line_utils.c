/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:01 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/04 17:26:30 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(char *)s == (char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	i;
	char	*target;

	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	target = tab;
	while (i < count * size)
	{
		target[i] = 0;
		i++;
	}
	return (tab);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	else if (dst >= src)
	{
		while (len != 0)
		{
			*(char *)(dst + (len - 1)) = *(char *)(src + (len - 1));
			len--;
		}
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
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
