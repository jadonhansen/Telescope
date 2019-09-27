#include "../includes/telescope.h"

int	word_search(t_line	**book, char *name, char *search)
{
	int	parameter = 0;
	char *ans = NULL;

	if (word_count(search) != 1)
	{
		ft_putstr("\e[1;1H\e[2J");	//
		print_header();
		print_details(book, name);
		print_param();
		ft_putstr_colour(RED, "You have entered more than one word but have chosen the 'Search for a specific word' option! Please try again.\n\n");
		ft_putstr_colour(CYAN, "Please enter your search word below and press ENTER:\n");
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
	return (1);
}

int	phrase_search(t_line **book, char *name, char *search)
{
	int	parameter = 0;
	char *ans = NULL;

	if (word_count(search) < 2)
	{
		ft_putstr("\e[1;1H\e[2J");		//
		print_header();
		print_details(book, name);
		print_param();
		ft_putstr_colour(RED,  "Your input did not constitute to a phrase. Make sure you are typing in more than one word! Please try again.\n\n");
		ft_putstr_colour(CYAN, "Please enter your search phrase below and press ENTER:\n");
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
	return (1);
}

int	line_search(t_line	**book, char *name, char *search)
{
	int		count = 0;
	int		line = ft_atoi(search);
	t_line	*temp = *book;

	if (word_count(search) != 1 || !(strdigitwhitespace(search)))
	{
		ft_putstr("\e[1;1H\e[2J");	//
		print_header();
		print_details(book, name);
		print_param();
		ft_putstr_colour(RED, "Your input did not constitute to a line number. Make sure you are typing in a valid line number! Please try again.\n\n");
		ft_putstr_colour(CYAN, "Please enter your line number below and press ENTER:\n");
		return (0);
	}
	if (temp)
	{
		ft_putchar('\n');
		if (line_exists(book, line))
		{
			ft_putstr("\e[1;1H\e[2J");	//
			print_header();
			print_details(book, name);
			ft_putstr_colour(CYAN, "RESULTS OF THE SEARCH FOR LINE ");
			ft_putstr_colour(CYAN, ft_itoa(line));
			ft_putstr_colour(CYAN, ":\n\n");
			while (temp != NULL && count <= line + 1)
			{
				if ((temp->page_no == line) || (temp->page_no == line - 1) || (temp->page_no == line + 1))
					line_printing(temp->text, temp->page_no, line);
				temp = temp->next;
				count++;
			}
			return (1);
		}
		line_printing(NULL, 0, line);
	}
	else
		clear_print(book, name, "ACCESS ERROR\n", 3);
	return (1);
}