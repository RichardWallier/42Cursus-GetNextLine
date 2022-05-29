#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	char			*temp;
	unsigned int	index;
	size_t			size_read;

	line = NULL;
	if (buffer)
	{
		line = treat_trash(buffer);
		printf("GNLbuffer: %s, line: %s\n", buffer, line);
		return (line);
	}


	temp = NULL;
	index = 0;
	size_read = -2;
	while (size_read)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		size_read = read(fd, buffer, BUFFER_SIZE);
		buffer[size_read] = '\0';
		if (next_nl(buffer))
		{
			temp = ft_substr(buffer, 0, next_nl(buffer) + 1);
			line = ft_strjoin(line, temp);
			buffer = ft_substr(buffer, ft_strlen(temp), ft_strlen(&buffer[ft_strlen(temp)]));
			free(temp);
			return (line);
		}
		else
			line = ft_strjoin(line, buffer);
		free(buffer);
	}
	return (line);
}

char	*treat_trash(char *buffer)
{
	char			*line;
	unsigned int	index;

	index = 0;
	line = NULL;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
		{
			if (!line)
			{
				line = ft_substr(buffer, index + 1, end_line(&buffer[index + 1]) + 1);
				buffer = ft_substr(buffer, ft_strlen(line) + 1, BUFFER_SIZE);
				return (line);
			}
		}
		index++;
	}
	return (line);
}

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
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (index);
		index++;
	}
	return (0);
}

size_t	end_line(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	return (index);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		delete;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	delete = count * size;
	ft_bzero(ptr, delete);
	return (ptr);
}

void	ft_bzero(void *dest, size_t len)
{
	unsigned char	*ptr;

	ptr = dest;
	while (len-- > 0)
		*ptr++ = 0;
}
