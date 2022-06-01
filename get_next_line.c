#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*trash;
	char			*buffer;
	char			*line;
	char			*temp;
	int			size_read;

	if (fd < 0)
		return (NULL);
	line = NULL;
	temp = NULL;
	buffer = NULL;
	if (trash)
	{
		if (next_nl(trash))
		{
			buffer = trash;
			temp = ft_substr(buffer, 0, end_line(buffer) + 1);
			trash = ft_substr(buffer, ft_strlen(temp), ft_strlen(&buffer[ft_strlen(temp)]));
			free(buffer);
			buffer = NULL;
			line = ft_substr(temp, 0, ft_strlen(temp));
			free(temp);
			temp = NULL;
			return (line);
		}
		else
		{
			buffer = line;
			line = ft_substr(trash, 0, ft_strlen(trash));
			free(trash);
			trash = NULL;
		}
	}

	size_read = -2;
	while (size_read)
	{
		buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
		size_read = read(fd, buffer, BUFFER_SIZE);
		buffer[size_read] = '\0';
		if (size_read == -1 || !buffer)
		{
			free(buffer);
			return (NULL);
		}
		if (next_nl(buffer))
		{
			temp = ft_substr(buffer, 0, end_line(buffer) + 1);
			trash = ft_substr(buffer, ft_strlen(temp), ft_strlen(&buffer[ft_strlen(temp)]));
			free(buffer);
			buffer = NULL;
			buffer = line;
			if (!line)
			{
				line = ft_substr(temp, 0, ft_strlen(temp));
				free(temp);
				temp = NULL;
			}
			else
				line = ft_strjoin(line, temp);
			free(temp);
			temp = NULL;
			free(buffer);
			buffer = NULL;
			return (line);
		}
		else
		{
			if (!line)
				line = ft_substr(buffer, 0, ft_strlen(buffer));
			else
			{
				temp = line;
				line = ft_strjoin(line, buffer);
				free(temp);
				temp = NULL;
			}
		}
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

// char	*treat_trash(char *buffer)
// {
// 	char			*line;
// 	unsigned int	index;

// 	index = 0;
// 	line = NULL;
// 	while (buffer[index])
// 	{
// 		if (buffer[index] == '\n')
// 		{
// 			if (!line)
// 			{
// 				line = ft_substr(buffer, index + 1, end_line(&buffer[index + 1]) + 1);
// 				buffer = ft_substr(buffer, ft_strlen(line) + 1, BUFFER_SIZE);
// 				return (line);
// 			}
// 		}
// 		index++;
// 	}
// 	return (line);
// }

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
	int	true;
	int false;

	index = 0;
	false = 0;
	true = 1;
	while (buffer[index] != '\n')
	{
		if (!buffer[index])
			return (false);
		index++;
	}
	return (true);
}

size_t	end_line(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	return (index);
}

