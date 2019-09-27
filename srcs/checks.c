#include "../includes/telescope.h"

int		find(char *line, char *search)
{
	int	i = 0;
	int	j;

	if (line && search)
	{
		while (line[i] != '\0')
		{
			j = 0;
			while (line[i] != '\0' && search[j] != '\0' && line[i] == search[j])
			{
				i++;
				j++;
			}
			if (search[j] == '\0')
				return (1);
			i++;
		}
	}
	return (0);
}

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

int		line_exists(t_line **book, int line)
{
	t_line	*temp = *book;

	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
		if (temp->page_no >= line && line >= 1)
			return (1);
		else
			return (0);		
	}
	return (0);
}