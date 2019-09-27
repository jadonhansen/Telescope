#include "../includes/telescope.h"

int		main(int argc, char **argv)
{
	t_line	*head = NULL;
	char	*line = NULL;
	int		count = 0;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_colour(RED, "Oops! Please run with a filename.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
	{
		ft_putstr_colour(RED, "Oops! The file '");
		ft_putstr_colour(RED, argv[1]);
		ft_putstr_colour(RED, "' could not be found.\n");
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
		{
			add_line(&head, line, ++count);
			free(line);
		}
		else
		{
			ft_putstr_colour(RED, "Oops! Something went wrong.");
			return (0);
		}
	}
	close(fd);
	if (check_content(&head, argv[1]))		//not working
		options(&head, argv[1]);
	if (head != NULL)
		free_book(&head);
	return (0);
}