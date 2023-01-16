/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:54:42 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/16 18:11:56 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define _OPEN_MAX 256

char	*get_next_line(int fd);

char	*ft_strdup(const char *src);
void	free_all(char *a, char *b);
int		ft_strlen(const char *s);
int		ft_linelen(const char *s);
char	*ft_strjoin(char *join_buff, char *tmp, int tmp_len);

#endif