#include "../includes/telescope.h"

void	every_inst_ph(t_line **book, char *name, char *search)
{
	t_line	*temp = *book;

	if (temp)
	{
		phrase_printing(book, name, search, 1);
		while (temp != NULL)
		{
			if (find(temp->text, search))
				phrase_printing(&temp, NULL, search, 2);
			temp = temp->next;
		}
	}
	clear_print(book, name, "ACCESS ERROR\n", 3);
}

void	first_inst_ph(t_line **book, char *name, char *search)
{
	t_line	*temp = *book;

	if (temp)
	{
		phrase_printing(book, name, search, 1);
		while (temp != NULL)
		{
			if (find(temp->text, search))
			{
				phrase_printing(&temp, NULL, search, 2);
				return ;
			}
			temp = temp->next;
		}
		phrase_printing(NULL, NULL, search, 3);
	}
	clear_print(book, name, "ACCESS ERROR\n", 3);
}

void	last_inst_ph(t_line **book, char *name, char *search)
{
	return ;
}