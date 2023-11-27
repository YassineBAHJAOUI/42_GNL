/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:32:19 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/13 13:01:11 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*hd[65534];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(hd[fd]);
		return (NULL);
	}
	buffer[0] = 0;
	hd[fd] = read_line(fd, buffer, hd[fd]);
	if (!hd[fd])
		return (NULL);
	if (!*hd[fd])
	{
		free(hd[fd]);
		hd[fd] = 0;
		return (NULL);
	}
	line = get_line(hd[fd]);
	hd[fd] = update_hd(hd[fd]);
	return (line);
}
