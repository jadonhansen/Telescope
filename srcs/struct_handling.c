#include "../includes/telescope.h"

static void		add_tail(t_line **head, t_line *node)
{
	t_line	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}

static t_line	*create_node(char *line, int num)
{
	t_line	*node;

	node = (t_line *)malloc(sizeof(t_line));
	node->next = NULL;
	node->text = line;
	node->page_no = num;
	return (node);
}

void			add_line(t_line **head, char *line, int num)
{
	t_line	*book;
	t_line	*node = NULL;

	book = *head;
	if (book == NULL)
	{
		*head = create_node(line, num);
	}
	else
	{
		node = create_node(line, num);
		add_tail(head, node);
	}
}