/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 09:48:30 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/11 13:58:01 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_elsecase(int stop, int start, const char *s)
{
	size_t	j;
	char	*string;

	j = 0;
	if (!(string = ft_strnew(stop - start + 1)))
		return (NULL);
	while (start <= stop && j < ft_strlen(s))
		string[j++] = s[start++];
	string[j] = '\0';
	return (string);
}

char		*ft_strtrim(char const *s)
{
	int		stop;
	int		i;
	char	*string;

	i = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == ','
			|| s[i] == '\0'))
		i--;
	stop = i;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == ',')
		i++;
	if (stop < i)
	{
		string = (char *)malloc(sizeof(char));
		string[0] = '\0';
	}
	else
		string = ft_elsecase(stop, i, s);
	return (string);
}
