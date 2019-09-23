/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:38:39 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/05 15:21:10 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			x;
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	x = ((int)len - 1);
	if (dest == source && len > 0)
		return (NULL);
	if (source < dest)
		while (x >= 0)
		{
			dest[x] = source[x];
			x--;
		}
	else
	{
		x = 0;
		while (x < (int)len)
		{
			dest[x] = source[x];
			x++;
		}
	}
	return (dst);
}
