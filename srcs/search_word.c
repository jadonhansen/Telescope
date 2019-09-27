#include "../includes/telescope.h"

void	every_inst_wrd(t_line **book, char *name, char *search)
{
	t_line	*temp = *book;
	int		found = 0;

	if (temp)
	{
		word_printing(book, name, search, 1);
		while (temp != NULL)
		{
			if (find(temp->text, search))
			{
				found = 1;
				word_printing(&temp, NULL, search, 2);
			}
			temp = temp->next;
		}
		if (found == 1)
			return ;
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	word_printing(NULL, NULL, search, 3);
}

void	first_inst_wrd(t_line **book, char *name, char *search)
{
	t_line	*temp = *book;

	if (temp)
	{
		word_printing(book, name, search, 1);
		while (temp != NULL)
		{
			if (find(temp->text, search))
			{
				word_printing(&temp, NULL, search, 2);
				return ;
			}
			temp = temp->next;
		}
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	word_printing(NULL, NULL, search, 3);
}

void	last_inst_wrd(t_line **book, char *name, char *search)
{
	return ;
}