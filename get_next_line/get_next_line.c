/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 18:39:40 by scristia      #+#    #+#                 */
/*   Updated: 2022/02/07 12:52:20 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *store_line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buffer[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		if (!store_line)
			store_line = ft_strdup(buffer);
		else
			store_line = ft_strjoin(store_line, buffer);
		if (ft_strchr(store_line, '\n'))
			return (store_line);
	}
	return (store_line);
}

static char	*save_remainder(char **store_line, size_t line_size)
{
	char	*buffer;
	char	*ret_remainder;
	size_t	size_remainder;
	size_t	full_buffer_len;

	buffer = *store_line;
	full_buffer_len = ft_len_to_char(buffer, '\0');
	size_remainder = full_buffer_len - line_size;
	if (size_remainder == 0 || !ft_strchr(buffer, '\n'))
	{
		free(*store_line);
		return (NULL);
	}
	ret_remainder = ft_strdup(buffer + line_size);
	free(*store_line);
	return (ret_remainder);
}

static char	*get_line(char **store_line)
{
	size_t	line_size;
	char	*line;

	if (ft_strchr(*store_line, '\n'))
		line_size = ft_len_to_char(*store_line, '\n') + 1;
	else
		line_size = ft_len_to_char(*store_line, '\0');
	line = malloc(line_size + 1);
	if (line == NULL)
	{
		free(*store_line);
		return (line);
	}
	ft_strlcpy(line, *store_line, line_size + 1);
	*store_line = save_remainder(store_line, line_size);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*store_line;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	store_line = read_line(fd, store_line);
	if (!store_line)
		return (NULL);
	line = get_line(&store_line);
	return (line);
}
