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

int		strdigitwhitespace(char *line)
{
	int	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' '  || line[i] == '\t' || (line[i] >= '0' && line[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	options(t_line **book, char *name)
{
	int		parameter = 0;
	char	*search;

	clear_print(book, name, NULL, 1);
	//ACTION
	scanf("%d", &parameter);
	if (parameter == 1)
	{
		clear_print(book, name, "Please enter your search word below and press ENTER:\n", 2);
		get_next_line(0, &search);
		if (word_count(search) == 1)
			word_search(book, search);
		else
		{
			clear_print(book, name, "You are searching for more than one word but have chosen the 'Search for a specific word' option! Please try again.\n", 3);
			//ACTION
		}
	}
	else if (parameter == 2)
	{
		clear_print(book, name, "Please enter your search phrase below and press ENTER:\n", 2);
		get_next_line(0, &search);
		if (word_count(search) > 1)
			phrase_search(book, search);
		else
		{
			clear_print(book, name, "Your input did not constitute to a phrase. Make sure you are typing in more than one word! Please try again.\n", 3);
			//ACTION
		}		
	}
	else if (parameter == 3)
	{
		clear_print(book, name, "Please enter your line number below and press ENTER:\n", 2);
		get_next_line(0, &search);
		if (word_count(search) == 1 && strdigitwhitespace(search))
			line_search(book, ft_atoi(search));
		else
		{
			clear_print(book, name, "Your input did not constitute to a line number. Make sure you are typing in a valid linenumber! Please try again.\n", 3);
			//ACTION
		}		
	}
	else if (parameter == 4)
	{
		free_book(book);
		clear_print(book, name, NULL, 1);
		ft_putstr_colour(BLUE, "THANK YOU FOR USING TELESCOPE©\n");
	}
	else
	{
		clear_print(book, name, "You have not entered a valid option! Please try again.\n", 2);
		//ACTION
	}
}