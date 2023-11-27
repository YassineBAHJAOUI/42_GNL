/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:30:08 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/11 12:30:38 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s + start);
	i = 0;
	if (len > slen)
		len = slen;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	slen = ft_strlen(s);
	i = -1;
	while (++i < len && start[s] && start < slen)
		*(str + i) = *(s + start + i);
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (*(s + (++i)))
		if (*(s + i) == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		j;
	char	*str;
	char	*str1;
	int		i;

	i = -1;
	if (!s1)
		str1 = ft_strdup("");
	else
		str1 = ft_strdup(s1);
	str = malloc(sizeof (char) * ((ft_strlen(str1)) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (str1[++i])
		str[i] = str1[i];
	j = i;
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free(str1);
	return (str);
}
