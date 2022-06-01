/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:49:33 by rwallier          #+#    #+#             */
/*   Updated: 2022/06/01 17:52:21 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	fullsize;

	if (!s1 || !s2)
		return (NULL);
	fullsize = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	newstr = (char *)malloc(fullsize * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&newstr[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (newstr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t maxsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (srcsize + 1 < maxsize)
		ft_memcpy(dest, src, srcsize + 1);
	else if (maxsize != 0)
	{
		ft_memcpy(dest, src, maxsize - 1);
		dest[maxsize - 1] = '\0';
	}
	return (srcsize);
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (char *)src;
	while (len--)
		*d++ = *s++;
	return (dest);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char		*ret;
	size_t		sz_temp;
	size_t		sz_str;

	if (!str)
		return (NULL);
	if (len > ft_strlen(str))
		ret = (char *)malloc(ft_strlen(str) + 1);
	else
		ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	sz_temp = 0;
	sz_str = 0;
	while (str[sz_str] != '\0')
	{
		if (sz_str >= start && sz_temp < len)
			ret[sz_temp++] = str[sz_str];
		sz_str++;
	}
	ret[sz_temp] = '\0';
	return (ret);
}

size_t	next_nl(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] != '\n')
	{
		if (!buffer[index])
			return (0);
		index++;
	}
	return (1);
}

size_t	end_line(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	return (index);
}
