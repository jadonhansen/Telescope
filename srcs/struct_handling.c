#include "../includes/telescope.h"

static void		add_tail(t_line **head, t_line *node)
{
	*head = NULL;
	node = NULL;
	return ;
}

static t_line	*create_node(char *line)
{
	line = NULL;
	return (NULL);
}

void			add_line(t_line **head, char *line)
{
	t_line	*book;
	t_line	*node = NULL;

	book = *head;
	if (book == NULL)
		*head = create_node(line);
	else
	{
		node = create_node(line);
		add_tail(head, node);
	}
}