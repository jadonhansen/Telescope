/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:03:56 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/10 16:26:03 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n > 0)
	{
		while ((str1[i] == str2[i] && str1[i] != '\0'
				&& str2[i] != '\0' && ((size_t)i < n - 1)))
		{
			i++;
		}
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] < str2[i])
			return (-1);
	}
	return (0);
}
