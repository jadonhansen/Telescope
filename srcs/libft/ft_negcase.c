/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:01:39 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/10 16:11:34 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_negcase(int num, int count)
{
	char	*str;
	int		i;
	int		rem;

	i = 0;
	rem = 0;
	num *= -1;
	if (num == INTMIN)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = (char *)malloc(sizeof(char) * count + 2);
	if (str == NULL)
		return (NULL);
	while (i < count)
	{
		rem = num % 10;
		num = num / 10;
		str[count - i] = rem + '0';
		i++;
	}
	str[count - i] = '-';
	str[count + 1] = '\0';
	return (str);
}
