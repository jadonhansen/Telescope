#include "../includes/telescope.h"

void	print_header()
{
	ft_putstr_colour(GREEN, "============================================\n");
	ft_putstr_colour(GREEN, "/\\                                        /\\\n");
	ft_putstr_colour(GREEN, "||                                        ||\n||");
	ft_putstr_colour(BLUE, "               TELESCOPE©               ");
	ft_putstr_colour(GREEN, "||\n||");
	ft_putstr_colour(BLUE, "          A light in the dark 💡         ");
	ft_putstr_colour(GREEN, "||\n||                                        ||\n");
	ft_putstr_colour(GREEN, "||                                        ||\n");
	ft_putstr_colour(GREEN, "============================================\n\n");
}

void	print_details(t_line **book, char *name)
{
	t_line	*temp;

	temp = *book;
	if (temp)
	{
		ft_putstr_colour(CYAN, "Document title: ");
		ft_putstr(name);
		ft_putchar('\n');
		ft_putstr_colour(CYAN, "Number of lines read: ");
		while (temp->next != NULL)
			temp = temp->next;
		ft_putnbr(temp->page_no);
		ft_putstr("\n\n");
	}
	else
	{
		clear_print(NULL, NULL, NULL, 0);
		ft_putstr_colour(RED, "ERROR: \"");
		ft_putstr_colour(RED, name);
		ft_putstr_colour(RED, "\" NOT FOUND!\n");
		free_book(book);
		exit (1);
	}
}

void	print_param()
{
	ft_putstr_colour(CYAN, "\nHow would you like to search your document? Enter your chosen option and press ENTER\n");
	ft_putstr("(1) : Search for a specific word\n(2) : Search for specific phrase\n(3) : Search by line number\n(4) : Quit program\n\n");
}
void	exit_print(t_line **book)
{
	free_book(book);
	ft_putstr("\e[1;1H\e[2J");
	print_header();
	ft_putstr_colour(BLUE, "THANK YOU FOR USING TELESCOPE©\n");
}

void	line_printing(char *text, int page, int line)
{
	if (page < line || page > line)
	{
		ft_putnbr(page);
		ft_putstr(": ");
		ft_putstr(text);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr_colour(BOLD_YELLOW, ft_itoa(page));
		ft_putstr_colour(BOLD_YELLOW, ": ");
		ft_putstr_colour(BOLD_YELLOW, text);
		ft_putchar('\n');
	}
}

void	word_printing(char *text, char *word, int flag)
{
	if (flag == 0)
	{
		ft_putstr_colour(CYAN, "WORD SEARCH:\nSelect a more detailed search option:\n");
		ft_putstr("(1) : Search for every instance\n(2) : The first instance\n(3) : The last instance\n\n");
	}
}

void	phrase_printing(char *text, char *phrase, int flag)
{
	if (flag == 0)
	{
		ft_putstr_colour(CYAN, "PHRASE SEARCH:\nSelect a more detailed search option:\n");
		ft_putstr("(1) : Search for every instance\n(2) : The first instance\n(3) : The last instance\n\n");
	}
}

void	clear_print(t_line **book, char *name, char *str, int flag)
{
	if (flag == 0)
	{
		ft_putstr("\e[1;1H\e[2J");	//for main search options (entering in 1, 2 or 3)
		print_header();
		print_details(book, name);
		print_param();
	}
	if (flag == 1)
	{
		ft_putstr("\e[1;1H\e[2J");	//input prompts
		print_header();
		print_details(book, name);
		print_param();
		ft_putstr_colour(CYAN, str);
	}
	if (flag == 2)
	{
		ft_putstr("\e[1;1H\e[2J");	//for error of main search options
		print_header();
		print_details(book, name);
		print_param();
		ft_putstr_colour(RED, str);
	}
	if (flag == 3)
	{
		ft_putstr("\e[1;1H\e[2J");	//line, wordds OR phrases not found
		print_header();
		print_details(book, name);
		ft_putstr_colour(RED, str);
	}
}