/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:33:33 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/13 15:52:32 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*read_line 
--fonction lit le contenu d'un fichier à 
partir d'un (fd) en utilisant la fonction read.
--stocke les données lues dans (buffer) et 
les concatène avec les données stockées dans hd .
--retourne le contenu total lu ou NULL en cas d'erreur. */
static char	*read_line(int fd, char *buffer, char *hd)
{
	ssize_t	ret;
	char	*str;

	ret = 1;
	while (ret != 0 && !ft_strchr(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = 0;
		str = ft_strjoin(hd, buffer);
		free(hd);
		hd = str;
	}
	free(buffer);
	return (hd);
}

/*get_line - fonction extrait la première ligne de 
hd en utilisant la fonction ft_substr et la retourne. */
static char	*get_line(char *hd)
{
	int		i;
	char	*s;

	i = 0;
	while (hd[i] && hd[i] != '\n')
		i++;
	s = ft_substr(hd, 0, i + 1);
	return (s);
}

/*update_hd - fonction met à jour hd en supprimant 
la première ligne extraite par get_line.*/
static char	*update_hd(char *hd)
{
	char	*s;
	int		i;

	i = 0;
	while (hd[i] && hd[i] != '\n')
		i++;
	if (hd[i] == '\n')
		i++;
	s = ft_substr(hd, i, ft_strlen(hd + i));
	free(hd);
	return (s);
}

/*get_next_line - entrée principal du programme 
-- vérifie d'abord si le descripteur de fichier 
est valide et si la taille du tampon est supérieure à zéro 

--alloue ensuite de la mémoire pour buffer 
et appelle read_line pour lire le contenu du fichie 

--appelle ensuite get_line pour extraire 
la première ligne et update_hd pour mettre à jour hd.

--retourne la première ligne extraite 
ou NULL en cas d'erreur. */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*hd;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(hd);
		return (NULL);
	}
	buffer[0] = 0;
	hd = read_line(fd, buffer, hd);
	if (!hd)
		return (NULL);
	if (!*hd)
	{
		free(hd);
		hd = 0;
		return (NULL);
	}
	return (line = get_line(hd), hd = update_hd(hd), line);
}
