#include "../includes/telescope.h"

void	options(t_line **book, char *name)
{
	char	*param = NULL;
	char	*search = NULL;

	clear_print(book, name, NULL, 0);
	ACTION:
	get_next_line(0, &param);
	if (ft_atoi(param) == 1)
	{
		clear_print(book, name, "Please enter your search word below and press ENTER:\n", 1);
		WORD_ERR:
		get_next_line(0, &search);
		if (word_search(book, name, search) == 0)
			goto WORD_ERR;
	}
	else if (ft_atoi(param) == 2)
	{
		clear_print(book, name, "Please enter your search phrase below and press ENTER:\n", 1);
		PHRASE_ERR:
		get_next_line(0, &search);
		if (phrase_search(book, name, search) == 0)
			goto PHRASE_ERR;
	}
	else if (ft_atoi(param) == 3)
	{
		clear_print(book, name, "Please enter your line number below and press ENTER:\n", 1);
		LINE_ERR:
		get_next_line(0, &search);
		if (line_search(book, name, search) == 0)
			goto LINE_ERR;
	}
	else if (ft_atoi(param) == 4)
		exit_print();
	else
	{
		clear_print(book, name, "YOU HAVE NOT ENTERED A VALID OPTION! PLEASE TRY AGAIN.\n", 2);
		goto ACTION;
	}
	free(param);
	free(search);
}