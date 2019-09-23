/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poscase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:02:15 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/10 16:11:19 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_poscase(int num, int count)
{
	int		i;
	int		rem;
	char	*str;

	i = 0;
	rem = 0;
	if (!(str = ft_strnew(count + 1)))
		return (NULL);
	while (i < count)
	{
		rem = num % 10;
		num = num / 10;
		str[count - (i + 1)] = rem + '0';
		i++;
	}
	str[count] = '\0';
	return (str);
}
