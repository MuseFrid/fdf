/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:33:42 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:31:37 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_H
# define REAL_H
# define ESC 53
# define MORE 24
# define MORE_NUM 69
# define CROSS 17

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

t_point	go_iso(int x, int y, int z, t_data *img, int color);
void	display_lign(t_point p1, t_point p2, t_data *img);
void	wash(t_data	*img);
int		do_it(t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	value_iso(t_map *map, t_data *img);
void	aarg(t_map *map, int x, int y, t_data *img, int zoom);
void	my_pixel_put(t_data *data, int x, int y, int color);

#endif
