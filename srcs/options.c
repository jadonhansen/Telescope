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

void	options(t_line **book)
{
	// int	parameter = 0;
	// int	instances = 0;
	*book = NULL;
	print_header();

}