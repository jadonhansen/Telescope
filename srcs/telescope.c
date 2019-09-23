#include "../includes/telescope.h"

int		main(int argc, char **argv)
{
	t_line	*head = NULL;
	char	*line = NULL;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("No file given as input!\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
	{
		ft_putstr("Could not find file!\n");
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
		{
			add_line(&head, line);
			free(line);
		}
		else
		{
			ft_putstr("No content read!\n");
			return (0);
		}
	}
	close(fd);
	return (0);
}