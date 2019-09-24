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

void	print_param(t_line **book, char *name)
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
		ft_putstr_colour(CYAN, "\n\n\nHow would you like to search your document? Enter your chosen option and press ENTER\n");
		ft_putstr("(1) : Search for a specific word\n(2) : Search for specific phrase\n(3) : Search by line number\n(4) : Quit program\n\n");
	}
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