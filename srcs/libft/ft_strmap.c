/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:01:16 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/05 16:49:52 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*string;

	i = 0;
	if (s == NULL)
		return (NULL);
	string = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (string == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		string[i] = f(s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
