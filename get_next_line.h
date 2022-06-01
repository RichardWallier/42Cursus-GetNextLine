/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:10:34 by rwallier          #+#    #+#             */
/*   Updated: 2022/06/01 18:59:29 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # define BUFFER_SIZE 5
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);

int		treat_trash(char **trash, char **line);

char	*make_line_no_nl(char *line, char *buffer);

char	*treat_read(int fd, int *size_read);

char	*treat_next_nl(char *buffer, char **trash, char *line);

void	free_pointer(char *buffer);

size_t	end_line(char *buffer);

size_t	next_nl(char *buffer);

char	*check_line(char *line);

void	*ft_memcpy(void *dest, const void *src, size_t len);

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t maxsize);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif
