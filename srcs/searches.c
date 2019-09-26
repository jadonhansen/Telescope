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
			line_printing(NULL, 0, line, 0);
			while (temp != NULL && count <= line + 1)
			{
				if ((temp->page_no == line) || (temp->page_no == line - 1) || (temp->page_no == line + 1))
					line_printing(temp->text, temp->page_no, line, 1);
				temp = temp->next;
				count++;
			}
			return ;
		}
	}
	clear_print(NULL, NULL, NULL, 0);
	ft_putstr_colour(RED, "ERROR: We could not find the line you were looking for!\n");
}

void	word_search(t_line	**book, char *name, char *search)
{
	int	parameter = 0;
	char *ans = NULL;

	clear_print(book, name, NULL, 1);
	WORD:
	word_printing(search, NULL, 0);
	get_next_line(0, &ans);
	if (ft_atoi(ans) == 1 || ft_atoi(ans) == 2 || ft_atoi(ans) == 3)
	{
		ft_putstr(ans);
	}
	else
	{
		clear_print(book, name, "Please enter a valid option!\n\n", 4);
		goto WORD;
	}
}

void	phrase_search(t_line **book, char *name, char *search)
{
	int	parameter = 0;
	char *ans = NULL;

	clear_print(book, name, NULL, 1);
	PHRASE:
	phrase_printing(search, NULL, 0);
	get_next_line(0, &ans);
	if (ft_atoi(ans) == 1 || ft_atoi(ans) == 2 || ft_atoi(ans) == 3)
	{
		ft_putstr(ans);
	}
	else
	{
		clear_print(book, name, "Please enter a valid option!\n\n", 4);
		goto PHRASE;
	}
}