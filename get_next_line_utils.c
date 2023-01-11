/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:54:36 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/12 03:37:24 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*temp;
	size_t	i;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	temp = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_linelen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *join_buff, char *tmp, int tmp_len)
{
	char	*re_join_buff;
	int		buff_len;
	int		i;
	int		j;

	if (!join_buff)
		return (ft_strdup(tmp));
	buff_len = ft_strlen(join_buff);
	re_join_buff = (char *)malloc(sizeof(char) * (buff_len + tmp_len + 1));
	if (!re_join_buff)
		return (NULL);
	i = -1;
	while (join_buff[i++] != '\0')
		re_join_buff[i] = join_buff[i];
	j = 0;
	while (tmp[j] != '\0')
	{
		re_join_buff[i + j] = tmp[j];
		j++;
	}
	re_join_buff[i + j] = '\0';
	free(join_buff);
	return (re_join_buff);
}
