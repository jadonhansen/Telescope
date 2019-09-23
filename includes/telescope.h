#ifndef TELESCOPE_H
# define TELESCOPE_H

# include "../srcs/libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	line
{
	char			*text;
	struct message	*next;
}				t_line;

void			add_line(t_line **head, char *text);


//emoji for pushing: 

#endif