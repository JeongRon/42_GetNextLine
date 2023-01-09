#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_glist	*list;
	t_glist			*now_node;
	char			*line;
	int				total_len;

	line = NULL;
	total_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	now_node = set_now_node(&list, fd);
	if (now_node == NULL)
		return (NULL);
	if (read(now_node->fd, NULL, 0) < 0)
		return (free_all(&list, now_node, line));
	
}

int main(void)
{
	while (1)
	{
		get_next_line();

	}
	return (0);
}