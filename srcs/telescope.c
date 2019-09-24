#include "../includes/telescope.h"

void	debug_print(t_line **head)
{
	t_line	*temp;

	temp = *head;
	while (temp != NULL)
	{
		ft_putnbr(temp->page_no);
		ft_putstr(": ");
		ft_putstr(temp->text);
		ft_putchar('\n');
		temp = temp->next;
	}
}

int		main(int argc, char **argv)
{
	t_line	*head = NULL;
	char	*line = NULL;
	int		count = 0;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_colour(RED, "Nothing has been given as input!\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
	{
		ft_putstr_colour(RED, "Could not find the suggested input!\n");
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
			ft_putstr_colour(RED, "No content found!\n");
			return (0);
		}
	}
	close(fd);
	//debug_print(&head);
	options(&head, argv[1]);
	free_book(&head);
	return (0);
}