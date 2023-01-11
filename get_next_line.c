/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:54:32 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/12 06:32:42 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buff(char *buff)
{
	int	i;

	if (!buff)
		return (1);
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*make_buff(char *buff, int fd)
{
	char	*join_buff;
	char	*tmp;
	int		read_size;

	join_buff = buff;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	while (check_buff(join_buff) == 1)
	{
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(join_buff);
			free(tmp);
			return (NULL);
		}
		else if (read_size == 0)
			break ;
		else
			join_buff = ft_strjoin(join_buff, tmp, read_size);
	}
	free(tmp);
	return (join_buff);
}

char	*make_line(char *buff, int line_len)
{
	char	*new_line;
	int		i;

	if (line_len == -1)
		new_line = ft_strdup(buff);
	else
	{
		new_line = (char *)malloc(sizeof(char) * (line_len + 1));
		if (!new_line)
			return (NULL);
		i = 0;
		while (i < line_len)
		{
			new_line[i] = buff[i];
			i++;
		}
		new_line[i] = '\0';
	}
	return (new_line);
}

char	*make_cache(char *buff, int line_len, int buff_len)
{
	char	*new_cache;
	int		i;
	int		j;

	if (line_len == -1 || buff_len == line_len)
		return (NULL);
	new_cache = (char *)malloc(sizeof(char) * (buff_len - line_len + 1));
	if (!new_cache)
		return (NULL);
	i = 0;
	j = line_len;
	while (j < buff_len)
	{
		new_cache[i] = buff[j];
		i++;
		j++;
	}
	new_cache[i] = '\0';
	return (new_cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buff;
	char		*line;
	int			buff_len;
	int			line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_strdup(cache);
	if (cache)
	{
		free(cache);
		cache = NULL;
	}
	buff = make_buff(buff, fd);
	if (!buff)
		return (NULL);
	buff_len = ft_strlen(buff);
	line_len = ft_linelen(buff);
	line = make_line(buff, line_len);
	cache = make_cache(buff, line_len, buff_len);
	free(buff);
	return (line);
}
