/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:24:47 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:22:14 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_double_tab(int **to_free, int size)
{
	int	i;

	i = 0;
	if (to_free)
	{
		while (i < size)
			free(to_free[i++]);
		free(to_free);
	}
}

static void	init_error(t_list *info, t_map *map, int y)
{
	if (errno)
		perror(NULL);
	if (map)
	{
		if (map->z)
			free_double_tab(map->z, y);
		if (map->color)
			free_double_tab(map->color, y);
		free(map);
	}
	lstclear(&info);
	exit(18);
}

int	**init_double_tab(int x, int y)
{
	int	**tab;
	int	*line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = (int **)malloc(sizeof(int *) * y);
	if (!tab)
		return (NULL);
	while (i < y)
	{
		line = (int *)malloc(sizeof(int) * x);
		if (!line)
		{
			while (j < i)
				free(tab[j++]);
			free(tab);
			return (NULL);
		}
		tab[i++] = line;
	}
	return (tab);
}

static void	fill_color(int **color, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
			color[i][j++] = 0;
		i++;
	}
}

t_map	*map_init(t_list *info)
{
	t_map	*map;
	int		y;

	y = lstsize(info);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		init_error(info, NULL, y);
	map->z = init_double_tab(info->lenght, y);
	if (!map->z)
		init_error(info, map, y);
	map->color = init_double_tab(info->lenght, y);
	if (!map->color)
		init_error(info, map, y);
	map->max_x = info->lenght;
	map->max_y = y;
	fill_color(map->color, map->max_x, map->max_y);
	return (map);
}
