/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populatearray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:04:27 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/10 16:10:30 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_populatearray(int count, char c, char const *s, char **array)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 0;
	while (j < count)
	{
		k = 0;
		if (!(array[j] = ft_strnew(ft_word_len(s, c, i))))
			return (NULL);
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			array[j][k++] = s[i++];
		array[j++][k] = '\0';
	}
	array[j] = 0;
	return (array);
}
