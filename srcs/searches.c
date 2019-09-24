#include "../includes/telescope.h"

int		line_exists(t_line **book, int line)
{
	t_line	*temp = *book;

	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	if (temp->page_no >= line)
		return (1);
	else
		return (0);
}

void	line_search(t_line	**book, int line)
{
	int		count = 0;
	t_line	*temp = *book;

	if (temp)
	{
		ft_putchar('\n');
		if (line_exists(book, line))
		{
			while (temp != NULL && count <= line + 1)
			{
				if ((temp->page_no == line) || (temp->page_no == line - 1) || (temp->page_no == line + 1))
					line_printing(temp->text, temp->page_no, line);
				temp = temp->next;
				count++;
			}
			return ;
		}
	}
	ft_putstr_colour(RED, "ERROR: We could not find the line you were looking for!\n");
}

void	word_search(t_line	**book, char *search)
{
	//options for every instance or first or last instance
	return ;
}

void	phrase_search(t_line	**book, char *search)
{
	//options for every instance or first or last instance
	return ;
}