/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 16:41:16 by scristia      #+#    #+#                 */
/*   Updated: 2022/01/24 16:51:29 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int 	fd;
	char	*str;

	fd = open("/gnlTester/files/41_with_nl", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
}
