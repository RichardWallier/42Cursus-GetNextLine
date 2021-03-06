/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:10:34 by rwallier          #+#    #+#             */
/*   Updated: 2022/06/04 09:59:28 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);

int		treat_trash(char **trash, char **line);

char	*treat_read(int fd, int *size_read);

char	*make_line_no_nl(char *line, char *buffer);

char	*make_line_with_nl(char *buffer, char **trash, char *line);

size_t	end_line(char *buffer);

size_t	next_nl(char *buffer);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif
