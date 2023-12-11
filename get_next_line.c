/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2023/12/11 17:11:35 by hclaude          ###   ########.fr       */
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
	// une fois /n on renvoie t_list
	// sinon on refait un read ( peut etre boucle while )
}

char *create_line(t_list buffer)
{
	// creation de la chaine de caractere
	
	// appelle de la fonction qui compte le nbre de caractere
	// alocation de la chaine avec calloc
	// verif si pas nul
	// boucle while qui parcourt les listes | Soit on boucle  jusqu'a superieur a nbr de caractere | soit jusqu'au \n ou \0
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