/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 18:44:51 by scristia      #+#    #+#                 */
/*   Updated: 2022/02/07 12:52:13 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);

size_t	ft_len_to_char(char const *str, char c);

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(char *s1);

#endif
