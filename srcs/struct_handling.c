#include "../includes/telescope.h"

static void		add_tail(t_line **head, t_line *node)
{
	t_line	*temp;

	if (*head == NULL || node == NULL)
		return ;
	temp = *head;
	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

static t_line	*create_node(char *line, int num)
{
	t_line	*node;

	node = (t_line *)malloc(sizeof(t_line));
	if (node)
	{
		node->next = NULL;
		node->text = ft_strdup(line);
		node->page_no = num;
	}
	return (node);
}

void			add_line(t_line **head, char *line, int num)
{
	t_line	*book;
	t_line	*node = NULL;

	book = *head;
	if (book == NULL)
		*head = create_node(line, num);
	else
	{
		node = create_node(line, num);
		add_tail(head, node);
	}
}

void			free_book(t_line **book)
{
	t_line	*temp;
	t_line	*next;

	temp = *book;
	if (temp)
	{
		while (temp != NULL)
		{
			next = temp->next;
			free(temp->text);
			free(temp);
			temp = next;
		}
		*book = NULL;
	}
}