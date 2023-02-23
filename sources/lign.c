/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:26:50 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:29:21 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_lign(t_point p1, t_point p2, t_data *img)
{
	float	m;
	float	p;
	int		i;

	if (p1.x == p2.x)
		m = INFINITY;
	else
		m = ((float)p2.y - (float)p1.y) / ((float)p2.x - (float)p1.x);
	p = (float)p1.y - m * (float)p1.x;
	if (m <= 1 && m >= -1 && p1.x <= p2.x)
	{
		i = p1.x;
		while (i <= p2.x)
		{
			my_mlx_pixel_put(img, i, (int)(m * (float)i + p), 0xFFFFFF);
			i++;
		}
	}
	else if (m <= 1 && m >= -1 && p1.x > p2.x)
	{
		i = p1.x;
		while (i >= p2.x)
		{
			my_mlx_pixel_put(img, i, (int)(m * (float)i + p), 0xFFFFFF);
			i--;
		}
	}
	if ((m > 1 || m < -1) && p1.y <= p2.y)
	{
		i = p1.y;
		while (i <= p2.y)
		{	
			if (m != INFINITY)
				my_mlx_pixel_put(img, (int)(((float)i - p) / m), i, 0xFFFFFF);
			else
				my_mlx_pixel_put(img, p1.x, i, 0xFFFFFF);
			i++;
		}
	}
	else if ((m > 1 || m < -1) && p1.y > p2.y)
	{
		i = p1.y;
		while (i >= p2.y)
		{
			if (m != INFINITY)
				my_mlx_pixel_put(img, (int)(((float)i - p) / m), i, 0xFFFFFF);
			else
				my_mlx_pixel_put(img, p1.x, i, 0xFFFFFF);
			i--;
		}
	}
}
