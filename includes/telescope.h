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
int				is_content(t_line **book, char *name);
void			options(t_line **book, char *name);
void			free_book(t_line **book);
int				word_count(char *word);
int				strdigitwhitespace(char *line);
int				line_exists(t_line **book, int line);
int				find(char *line, char *search);

void			every_inst_wrd(t_line **book, char *name, char *search);
void			every_inst_ph(t_line **book, char *name, char *search);
void			first_inst_wrd(t_line **book, char *name, char *search);
void			first_inst_ph(t_line **book, char *name, char *search);
void			last_inst_wrd(t_line **book, char *name, char *search);
void			last_inst_ph(t_line **book, char *name, char *search);
int				phrase_search(t_line **book, char *name, char *search);
int				word_search(t_line **book, char *name, char *search);
int				line_search(t_line **book, char *name, char *search);

void			exit_print();
void			print_header();
void			print_param();
void			print_details(t_line **book, char *name);
void			input_err(t_line **book, char *name, char *one, char *two);
void			line_printing(t_line **book, char *text, int page, int line, int flag);
void			word_printing(t_line **book, char *name, char *word, int flag);
void			phrase_printing(t_line **book, char *name, char *phrase, int flag);
void			highlight_output(char *text, int page, char *search);
void			clear_print(t_line **book, char *name, char *str, int flag); //under construction

//emoji for pushing: 💡

#endif