/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:07:56 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/23 16:37:24 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	x += 600;
	y += 400;
	if (x < 2560 && y < 1440 && y >= 0 && x >= 0)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	close_win(int keycode, t_vars *vars, t_data img, t_map *map)
{
	(void) map;
	printf("keyhook : %d\n", keycode);
	if (keycode == MORE || keycode == MORE_NUM)
	{
		img.img = mlx_new_image(vars->mlx, 2560, 1440);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
		wash(&img);
		//value_iso(map, &img);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
	if (keycode == ESC || keycode == CROSS)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

/*t_vars *gd_mlx_init(void)
{
	t_vars	vars;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(1);
	vars->win = mlx_new_window(vars->mlx, 2560, 1440, "./fdf");
	if (vars->win)
		exit(1);
}*/

int	do_it(t_map *map)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;

	if (!map)
		return (1);
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 2560, 1440, "./fdf");
	img.img = mlx_new_image(mlx_ptr, 2560, 1440);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	vars.mlx = mlx_ptr;
	vars.win = mlx_win;
	//mlx_hook(mlx_win, 2, 1L<<0, close_win, &vars);
	printf("yo\n");
	value_iso(map, &img);
	//wash(&img);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x < 2560 && y < 1440 && y >= 0 && x >= 0)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	wash(t_data	*img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1440)
	{
		x = 0;
		while (x < 2560)
			my_pixel_put(img, x++, y, 0xEF3F0F0F);
		y++;
	}
}

t_point	go_iso(int x, int y, int z, t_data *img, int color)
{
	t_point	point;

	point.x = (x - y) * cos(0.523599);
	point.y = -z + (x + y) * sin(0.523599);
	if (!color)
		my_mlx_pixel_put(img, point.x, point.y, 0xFFFFFF);
	//else
	//	my_mlx_pixel_put(img, point.x, point.y, color);
	return (point);
}

void	aarg(t_map *map, int x, int y, t_data *img, int zoom)
{
	t_point	src;

	src = go_iso((x + 1) * zoom, (y + 1) * zoom, map->z[y][x] * zoom, img, map->color[y][x]);
	if (x != map->max_x - 1)
		display_lign(src, go_iso((x + 2) * zoom, (y + 1) * zoom, map->z[y][x + 1] * zoom, img, map->color[y][x + 1]), img);
	if (y != map->max_y - 1)
		display_lign(src, go_iso((x + 1) * zoom, (y + 2) * zoom, map->z[y + 1][x] * zoom, img, map->color[y + 1][x]), img);
}

void	value_iso(t_map *map, t_data *img)
{
	int	y;
	int	x;
	int	zoom;

	y = -1;
	x = 0;
	zoom = 6;
	while (++y < map->max_y)
	{
		x = -1;
		while (++x < map->max_x)
			aarg(map, x, y, img, zoom);
	}
}
