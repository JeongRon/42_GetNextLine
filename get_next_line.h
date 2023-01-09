#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif 

typedef struct s_glist
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		buf_len;
	int		printed_buf_len;
	struct s_glist *next;
}	t_glist;

#endif