/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 18:45:50 by scristia      #+#    #+#                 */
/*   Updated: 2022/02/07 12:52:17 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == '\0' && (char) c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_len_to_char(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	char		*d1;
	const char	*s1;
	size_t		len_s;
	size_t		i;

	len_s = ft_len_to_char(src, '\0');
	d1 = dest;
	s1 = src;
	i = 0;
	if (dstsize == 0)
		return (len_s);
	while (i < dstsize - 1 && s1[i] != 0)
	{
		d1[i] = s1[i];
		i++;
	}
	d1[i] = 0;
	return (len_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full_s;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_len_to_char(s1, '\0');
	len_s2 = ft_len_to_char(s2, '\0');
	full_s = malloc(len_s1 + len_s2 + 1);
	if (full_s == NULL)
	{
		free((char *)s1);
		return (full_s);
	}
	ft_strlcpy(full_s, s1, len_s1 + 1);
	ft_strlcpy(full_s + len_s1, s2, len_s2 + 1);
	free((char *)s1);
	return (full_s);
}

char	*ft_strdup(char *s1)
{
	char	*cpy_s1;
	size_t	len_s1;

	len_s1 = ft_len_to_char(s1, '\0');
	cpy_s1 = (char *)malloc(len_s1 + 1);
	if (cpy_s1 == NULL)
		return (cpy_s1);
	ft_strlcpy(cpy_s1, s1, len_s1 + 1);
	return (cpy_s1);
}
