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
				highlight_output(temp->text, temp->page_no, search);
			}
			temp = temp->next;
		}
		if (found == 1)
			return ;
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	word_printing(NULL, NULL, search, 2);
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
				highlight_output(temp->text, temp->page_no, search);
				return ;
			}
			temp = temp->next;
		}
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	word_printing(NULL, NULL, search, 2);
}

void	last_inst_wrd(t_line **book, char *name, char *search)
{
	t_line	*temp = *book;
	t_line	*save = NULL;

	if (temp)
	{
		word_printing(book, name, search, 1);
		while (temp != NULL)
		{
			if (find(temp->text, search))
				save = temp;
			temp = temp->next;
		}
		if (save != NULL)
		{
			highlight_output(save->text, save->page_no, search);
			return ;
		}
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	word_printing(NULL, NULL, search, 2);
}