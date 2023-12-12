/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/12 15:43:21 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static t_list 	buffer = NULL;
	char			*new_line;
	
	// condition pour proteger fd, buffer_size
	if (fd == -1)
		return (NULL);
	// appelle de la fonction qui va read
	read_file(buffer, fd);
	// appelle de la fonction qui va creer la ligne de retour
	new_line = create_line(buffer);
	// appelle de la fonction qui va vider la chaine buffer
	free_list(buffer);
	// return la ligne
	return (new_line);
}

t_list read_file(t_list buffer, int fd)
{
	// creation des variables
	int i;

	while (!if_backslash(buffer))
	{
	// allocation de la premiere liste chaine
		buffer.content = ft_calloc(sizeof(char *), BUFFER_SIZE);
		if (!buffer.content == NULL)
			return (NULL);
	// i = read(fd, buffer, BUFFER_SIZE)
		i = read(fd, buffer.content, BUFFER_SIZE);
	// condition de si i = 0 ou -1
		if (i == 0)
			return (buffer);
		if (i == -1)
			return (NULL);
		buffer = buffer.next;
	}
	return (buffer);
	// une fois /n on renvoie t_list
	// sinon on refait un read ( peut etre boucle while )
}

char *create_line(t_list buffer)
{
	// creation de la chaine de caractere
	char	*str;
	int		i;
	// appelle de la fonction qui compte le nbre de caractere
	i = count_char(buffer);
	
	// alocation de la chaine avec calloc
	str = ft_calloc(sizeof(char), i + 1);
	// verif si pas nul
	if (!str)
		return (NULL);
	i = 0;
	// boucle while qui parcourt les listes | Soit on boucle  jusqu'a superieur a nbr de caractere | soit jusqu'au \n ou \0
	while (buffer.content)
	{
		while (buffer.content[i])
	}
	// Boucle while qui parcourt la liste
	// copie des caracteres 
	// retourner la chaine
}

int count_char(t_list buffer)
{
	// creation d'un indice
	
	// boucle while qui parcourt les listes
	// boucle while qui parcourt la liste
	// indice ++
	// retourner l'indice
}

void free_list(t_list buffer)
{
	// creation de variables

	// boucle while qui parcourt les listes
	// boucle while qui parcourt la liste
	// si indice != \n ou \0
	// appelle de fonction qui replace les caracteres
	// break
	// sinon free et liste = NULL
}

char *replace(t_list buffer_last_line, int i)
{
	// fonction qui cherche la bonne ligne et replace les elements apres \n au debut.
}