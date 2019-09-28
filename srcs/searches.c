#include "../includes/telescope.h"

int	word_search(t_line	**book, char *name, char *search)
{
	char *ans = NULL;

	if (word_count(search) != 1)
	{
		input_err(book, name, "You have entered more than one word but have chosen the 'Search for a specific word' option! Please try again.\n", "Please enter your search word below and press ENTER:\n");
		return (0);
	}
	ft_putstr("\e[1;1H\e[2J");	//
	print_header();
	print_details(book, name);
	WORD:
	word_printing(NULL, NULL, NULL, 0);
	get_next_line(0, &ans);
	if (ft_atoi(ans) == 1)
		every_inst_wrd(book, name, search);
	else if (ft_atoi(ans) == 2)
		first_inst_wrd(book, name, search);
	else if (ft_atoi(ans) == 3)
		last_inst_wrd(book, name, search);
	else
	{
		ft_putstr("\e[1;1H\e[2J");	//
		print_header();
		print_details(book, name);
		ft_putstr_colour(RED, "Please enter a valid option!\n\n");
		goto WORD;
	}
	free(ans);
	return (1);
}

int	phrase_search(t_line **book, char *name, char *search)
{
	char *ans = NULL;

	if (word_count(search) < 2)
	{
		input_err(book, name, "Your input did not constitute to a phrase. Make sure you are typing in more than one word! Please try again.\n", "Please enter your search phrase below and press ENTER:\n");
		return (0);
	}
	ft_putstr("\e[1;1H\e[2J");		//
	print_header();
	print_details(book, name);
	PHRASE:
	phrase_printing(NULL, NULL, NULL, 0);
	get_next_line(0, &ans);
	if (ft_atoi(ans) == 1)
		every_inst_ph(book, name, search);
	else if (ft_atoi(ans) == 2)
		first_inst_ph(book, name, search);
	else if (ft_atoi(ans) == 3)
		last_inst_ph(book, name, search);
	else
	{
		ft_putstr("\e[1;1H\e[2J");		//
		print_header();
		print_details(book, name);
		ft_putstr_colour(RED, "Please enter a valid option!\n\n");
		goto PHRASE;
	}
	free(ans);
	return (1);
}

int	line_search(t_line	**book, char *name, char *search)
{
	int		count = 0;
	int		line = ft_atoi(search);
	t_line	*temp = *book;

	if (word_count(search) != 1 || !(strdigitwhitespace(search)))
	{
		input_err(book, name, "Your input did not constitute to a line number. Make sure you are typing in a valid line number! Please try again.\n", "Please enter your line number below and press ENTER:\n");
		return (0);
	}
	if (temp)
	{
		if (line_exists(book, line))
		{
			line_printing(book, name, 0, line, 0);
			while (temp != NULL && count <= line + 1)
			{
				if ((temp->page_no == line) || (temp->page_no == line - 1) || (temp->page_no == line + 1))
					line_printing(book, temp->text, temp->page_no, line, 100);
				temp = temp->next;
				count++;
			}
			return (1);
		}
		line_printing(book, name, 0, line, 1);
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	return (1);
}