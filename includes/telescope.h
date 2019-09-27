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
int				strdigitwhitespace(char *line);
int				line_exists(t_line **book, int line);

int				phrase_search(t_line **book, char *name, char *search);
int				word_search(t_line **book, char *name, char *search);
int				line_search(t_line **book, char *name, char *search);

void			exit_print(t_line **book);
void			print_header();
void			print_param();
void			print_details(t_line **book, char *name);
void			line_printing(char *text, int page, int line);
void			clear_print(t_line **book, char *name, char *str, int flag); //under construction
void			word_printing(char *text, char *word, int flag);
void			phrase_printing(char *text, char *phrase, int flag);

//emoji for pushing: 💡

#endif