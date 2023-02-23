/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:44:50 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:20:36 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(long *len, int *sign)
{
	long	count;
	long	i;

	count = 0;
	if (*len < 0)
	{
		*len = -(*len);
		count++;
		*sign = -1;
	}
	i = *len;
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	count;
	long	len;
	int		sign;

	len = n;
	count = ft_count_len(&len, &sign);
	if (len == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (sign < 0)
		str[0] = 45;
	str[count] = 0;
	while (len != 0)
	{
		str[count - 1] = ((len % 10) + 48);
		len = len / 10;
		count--;
	}
	return (str);
}
