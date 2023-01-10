/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:54:32 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/10 21:03:21 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buff;
	
}

int	main(void)
{
	int		fd;
	char	*fin_line;

	fd = open("test.txt", O_RDONLY);

	fin_line = get_next_line(fd);
	printf("1. {%s}\n", fin_line);
	free(fin_line);

	fin_line = get_next_line(fd);
	printf("2. {%s}\n", fin_line);
	free(fin_line);
	
	fin_line = get_next_line(fd);
	printf("3. {%s}\n", fin_line);
	free(fin_line);
	
	fin_line = get_next_line(fd);
	printf("4. {%s}\n", fin_line);
	free(fin_line);
	
	fin_line = get_next_line(fd);
	printf("5. {%s}\n", fin_line);
	free(fin_line);
	
	fin_line = get_next_line(fd);
	printf("6. {%s}\n", fin_line);
	free(fin_line);

	// printf("-----------------leaks test---------------------\n\n");
	// system("leaks a.out");
	close(fd);
	return (0);
}
