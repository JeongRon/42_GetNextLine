/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:54:42 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/12 03:34:21 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		check_buff(char *buff);
char	*make_buff(char *buff, int fd);
char	*make_line(char *buff, int line_len);
char	*make_cache(char *buff, int line_len, int buff_len);
char	*get_next_line(int fd);

char	*ft_strdup(const char *src);
int		ft_strlen(const char *s);
int		ft_linelen(const char *s);
char	*ft_strjoin(char *join_buff, char *tmp, int tmp_len);

#endif