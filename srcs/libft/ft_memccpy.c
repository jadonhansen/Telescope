/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:19:21 by jhansen           #+#    #+#             */
/*   Updated: 2019/05/27 17:03:54 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int			i;
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	i = 0;
	while ((size_t)i < n)
	{
		dest[i] = source[i];
		if (source[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
