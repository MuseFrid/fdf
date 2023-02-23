/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:55:06 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:20:42 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_atoi(const char *str, int *j)
{
	long long	i;
	long long	num;
	int			sign;

	sign = 1;
	i = (long long) *j;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			sign *= -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
		if (sign == -1 && (-num) > 2147483648 && ++errno)
			return (0);
		if (sign == 1 && (-num) > 2147483647 && ++errno)
			return (-1);
	}
	*j = (int) i;
	if (sign == -1)
		return (-num);
	return (num);
}
