#include "../includes/telescope.h"

void	every_inst_ph(t_line **book, char *name, char *search)
{
	t_line	*temp = *book;
	int		found = 0;

	if (temp)
	{
		phrase_printing(book, name, 0, search, 1);
		while (temp != NULL)
		{
			if (find(temp->text, search))
			{
				found = 1;
				phrase_printing(NULL, temp->text, temp->page_no, search, 2);
			}
			temp = temp->next;
		}
		if (found == 1)
			return ;
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	phrase_printing(NULL, NULL, 0, search, 3);
}

void	first_inst_ph(t_line **book, char *name, char *search)
{
	t_line	*temp = *book;

	if (temp)
	{
		phrase_printing(book, name, 0, search, 1);
		while (temp != NULL)
		{
			if (find(temp->text, search))
			{
				phrase_printing(NULL, temp->text, temp->page_no, search, 2);
				return ;
			}
			temp = temp->next;
		}
		return ;
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	phrase_printing(NULL, NULL, 0, search, 3);
}

void	last_inst_ph(t_line **book, char *name, char *search)
{
	return ;
}