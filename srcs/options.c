#include "../includes/telescope.h"

int		word_count(char *word)
{
	int i = 0;
	int	count = 0;

	if (word)
	{
		while (word[i] != '\0')
		{
			while (word[i] != '\0' && (word[i] == ' ' || word[i] == '\t'))
				i++;
			if (word[i] != '\0')
			{
				while (word[i] != '\0' && word[i] != ' ' && word[i] != '\t' && word[i] != '\n' && word[i] != '\r')
					i++;
				count++;
			}
			else
				return (count);
		}
		return (count);
	}
	return (0);
}

void	options(t_line **book, char *name)
{
	int		parameter = 0;
	char	search[1000];

	print_header();
	print_param(book, name);
	//ACTION
	scanf("%d", &parameter);
	if (parameter == 1)
	{
		ft_putstr_colour(CYAN, "Please enter your search word below and press ENTER:\n");
		scanf("%s", search);
		if (word_count(search) == 1)
			word_search(book, search);
		else
		{
			ft_putstr_colour(RED, "You are searching for more than one word but have chosen the 'Search for a specific word' option! Please try again.\n");
			//ACTION
		}
	}
	else if (parameter == 2)
	{
		ft_putstr_colour(CYAN, "Please enter your search phrase below and press ENTER:\n");
		scanf("%s", search);
		if (word_count(search) > 1)
			phrase_search(book, search);
		else
		{
			ft_putstr_colour(RED, "Your input did not constitute to a phrase. Make sure you are typing in more than one word! Please try again.\n");
			//ACTION
		}		
	}
	else if (parameter == 3)
	{
		ft_putstr_colour(CYAN, "Please enter your line number below and press ENTER:\n");
		scanf("%s", search);
		if (ft_str_is_numeric(search))
			line_search(book, ft_atoi(search));
		else
		{
			ft_putstr_colour(RED, "Your input did not constitute to a line number. Make sure you are typing in a valid linenumber! Please try again.\n");
			//ACTION
		}		
	}
	else if (parameter == 'Q')
	{
		free_book(book);
		ft_putstr_colour(BLUE, "THANK YOU FOR USING TELESCOPE©\n");
	}
	else
	{
		ft_putstr_colour(RED, "You have not entered valid option! Please try again.\n");
		//ACTION
	}
}