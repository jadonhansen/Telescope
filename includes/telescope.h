#ifndef TELESCOPE_H
# define TELESCOPE_H

# include "../srcs/libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	line
{
	char		*text;
	int			page_no;
	struct line	*next;
}				t_line;

void			add_line(t_line **head, char *text, int num);
void			options(t_line **book, char *name);
void			free_book(t_line **book);
int				word_count(char *word);

void			phrase_search(t_line	**book, char *search);
void			word_search(t_line	**book, char *search);
void			line_search(t_line	**book, int line);

void			print_header();
void			print_param(t_line **book, char *name);
void			line_printing(char *text, int page, int line, int flag);
void			clear_print(t_line **book, char *name, char *error, int flag);

//emoji for pushing: 💡

#endif