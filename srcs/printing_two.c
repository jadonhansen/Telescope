#include "../includes/telescope.h"

void	highlight_output(char *text, int page, char *search)
{
	int	i = 0;
	int	j;
	int save;

	ft_putstr_colour(YELLOW, ft_itoa(page));
	ft_putstr(" : ");
	while (text[i] != '\0')
	{
		j = 0;
		save = i;
		while (text[i] != '\0' && search[j] != '\0' && text[i] == search[j])
		{
			i++;
			j++;
		}
		if (search[j] == '\0' && (text[i] == ' ' || text[i] == '\t'))
		{
			ft_putstr_colour(YELLOW, search);
			i = save + j;
		}
		else if (j > 0)
		{
			i = save;
			ft_putchar(text[i]);
			i++;
		}
		else
		{
			ft_putchar(text[i]);
			i++;
		}
	}
	ft_putchar('\n');
}

void	line_printing(t_line **book, char *text, int page, int line, int flag)
{
	if (flag == 0)
	{
		ft_putstr("\e[1;1H\e[2J");
		print_header();
		print_details(book, text);
		ft_putstr_colour(CYAN, "RESULTS OF THE SEARCH FOR LINE ");
		ft_putstr_colour(CYAN, ft_itoa(line));
		ft_putstr_colour(CYAN, ":\n\n");
	}
	else if (flag == 1)
	{
		ft_putstr("\e[1;1H\e[2J");
		print_header();
		ft_putstr_colour(CYAN, "RESULTS OF THE SEARCH FOR LINE ");
		ft_putstr_colour(CYAN, ft_itoa(line));
		ft_putstr_colour(CYAN, ":\n\n");
		ft_putstr_colour(YELLOW, "Sorry, we could not find line '");
		ft_putstr_colour(YELLOW, ft_itoa(line));
		ft_putstr_colour(YELLOW, "'.\n");
	}
	else if (page < line || page > line)
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

void	word_printing(t_line **book, char *name, char *word, int flag)
{
	if (flag == 0)
	{
		ft_putstr_colour(CYAN, "WORD SEARCH:\nSelect a more detailed search option:\n");
		ft_putstr("(1) : Search for every instance\n(2) : The first instance\n(3) : The last instance\n\n");
	}
	if (flag == 1)
	{
		ft_putstr("\e[1;1H\e[2J");
		print_header();
		print_details(book, name);
		ft_putstr_colour(CYAN, "RESULTS OF THE SEARCH FOR THE WORD '");
		ft_putstr_colour(CYAN, word);
		ft_putstr_colour(CYAN, "':\n\n");
	}
	if (flag == 2)
	{
		ft_putstr_colour(YELLOW, "Sorry, no instance of the word '");
		ft_putstr_colour(YELLOW, word);
		ft_putstr_colour(YELLOW, "' was found.\n");
	}
}

void	phrase_printing(t_line **book, char *name, char *phrase, int flag)
{
	if (flag == 0)
	{
		ft_putstr_colour(CYAN, "PHRASE SEARCH:\nSelect a more detailed search option:\n");
		ft_putstr("(1) : Search for every instance\n(2) : The first instance\n(3) : The last instance\n\n");
	}
	if (flag == 1)
	{
		ft_putstr("\e[1;1H\e[2J");
		print_header();
		print_details(book, name);
		ft_putstr_colour(CYAN, "RESULTS OF THE SEARCH FOR THE PHRASE '");
		ft_putstr_colour(CYAN, phrase);
		ft_putstr_colour(CYAN, "':\n\n");
	}
	if (flag == 2)
	{
		ft_putstr_colour(YELLOW, "Sorry, no instance of the phrase '");
		ft_putstr_colour(YELLOW, phrase);
		ft_putstr_colour(YELLOW, "' was found.\n");
	}
}