/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 18:39:40 by scristia      #+#    #+#                 */
/*   Updated: 2022/01/16 02:56:43 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 10

static char	*read_line(int fd, char *store_line)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	read_bytes;

	read_bytes = 1;
	while (TRUE && !(ft_strchr(buffer, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (read_bytes == 0)
			break ;
		store_line = ft_strjoin(store_line, buffer);
	}
	return (store_line);
}

static char	*get_line(char const *store_line)
{
	size_t	size_of_line;
	char	*line;

	if (!ft_strchr(store_line, '\n'))
		size_of_line = ft_len_to_char(store_line, '\0') + 1;
	size_of_line = ft_len_to_char(store_line, '\n') + 2;
	line = malloc(size_of_line);
	if (line == NULL)
		return (line);
	ft_strlcpy(line, store_line, size_of_line);
	return (line);
}

static char	*save_remainder_line(char *store_line)
{
	char	*save;

	
}

char	*get_next_line(int fd)
{
	static char		*store_line;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	store_line = read_line(fd, store_line);
	line = get_line(store_line);
	
	return (line);
}
