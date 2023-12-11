/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/11 14:52:34 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static t_list buffer;
	// creer variable qu'il faut 

	// condition pour proteger fd, buffer_size
	// appelle de la fonction qui va read
	// appelle de la fonction qui va creer la ligne de retour
	// appelle de la fonction qui va vider la chaine buffer
	// return la ligne
}

t_list read_file(t_list buffer, int fd)
{
	// creation des variables
	
	// allocation de la premiere liste chaine
	// i = read(fd, buffer, BUFFER_SIZE)
	// condition de si i = 0 ou -1
	// appelle de fonction qui va verif si /n dans chaine
	// sinon on refait un read ( peut etre boucle while )
	// une fois /n on renvoie t_list
}