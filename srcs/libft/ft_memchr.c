/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:13:33 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/10 17:24:41 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*string;

	string = (unsigned char *)s;
	while (n--)
	{
		if (*string == (unsigned char)c)
			return (string);
		string++;
	}
	return (NULL);
}
