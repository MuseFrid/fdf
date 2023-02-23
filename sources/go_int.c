/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:13:15 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/23 16:35:22 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*void	*clear_map(t_list *head, t_info *info, int size)
{
	int	i;

	i = 0;
	if (info)
	{
		if (info->map)
		{
			while (size > i)
				free(info->map[i++]);
			free(info->map);
		}
		free(info);
	}
	if (head)
		return (lstclear(&head));
	return (NULL);
}

int	swap_to_int(int *line, char *str, int lenght)
{
	int		j;
	int		i;
	int		size;
	//char	*color;

	i = 0;
	j = 0;
	size = 0;
	while (i < lenght)
	{
		line[i] = ft_atoi(str, &j);
		if (errno != 0)
		{	
			write(2, "atoi fail\n", 10);
			return (-1);
		}
		if (str[j] == ',' && ++j)
		{
			size = j + 8;
			while (str[j] && j < size)
			{
				j++;
			}
		}
		i++;
	}
	return (0);
}

t_info	*info_init(int max_y, int max_x)
{
	t_info	*info;
	int		**map;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->max_x = max_x;
	info->max_y = max_y;
	map = (int **)malloc(sizeof(int *) * max_y);
	if (!map)
	{
		free(info);
		return (NULL);
	}
	info->map = map;
	return (info);
}

t_info	*map_init(t_list *head, int i)
{
	int		*line;
	int		size_head;
	t_list	*snake;
	t_info	*info;

	size_head = lstsize(head);
	snake = head;
	info = info_init(size_head, head->lenght);
	if (!info)
		return (clear_map(head, info, size_head));
	while (size_head > 0)
	{
		line = (int *)malloc(sizeof(int) * head->lenght);
		if (!line)
			return (clear_map(head, info, size_head));
		info->map[i++] = line;
		printf("%s\n", snake->line);
		if (swap_to_int(line, snake->line, snake->lenght) == -1)
			return (clear_map(head, info, size_head));
		snake = snake->next;
		size_head--;
	}
	//printf("%d\n", i);
	//printf("OOEE");
	*//*snake = head;
	while (snake)
	{
		printf("%s\n", snake->line);
		printf("%d\n", snake->lenght);
		snake = snake->next;
	}*//*
	//return (clear_map(map, head, info, size_head));
	lstclear(&head);
	return (info);
}

t_info *go_int(t_list *head)
{
	t_info	*info;

	if (!head)
		return (NULL);
	info = map_init(head, 0);
	if (!info)
		return (NULL);
	*//*int	i = 0;
	int	j = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
			printf("%d  ", info->map[i][j++]);
		printf("\n");
		i++;
	}*//*
	//printf("%d\n", head->lenght);
	//printf("check\n");
	printf("OOEE\n");
	return (info);
}*/

/*int	define_color(char **color, char *str, int *j, int where)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (i == 0)
		{
			if (!(str[(*j) + i] == '0' && str[(*j) + i + 1] == 'x'))
			{
				printf("its identification\n");
				return (-1);
			}
			i += 2;
		}
		else
		{
			if (!(ft_isdigit(str[(*j) + i]) || (str[(*j) + i] >= 'A' \
							&& str[(*j) + i] <= 'F') \
							|| (str[(*j) + i] >= 'a' && str[(*j) + i] <= 'f')))
			{
				printf("its hex\n");
				return (-1);
			}
			i++;
		}
	}
	color[where] = ft_substr(str, *j, 8);
	if (!color[where])
	{	
		printf("its substr\n");
		return (-1);
	}
	(*j) += 8;
	return (0);
}

char	**init_color_line(t_list *info, char **color, int **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	color = (char **)malloc(sizeof(char *) * info->lenght);
	if (!color)
		return (NULL);
	*line = (int *)malloc(sizeof(int) * info->lenght);
	if (!*line)
	{
		free(color);
		return (NULL);
	}
	while (i < info->lenght)
	{
		(*line)[i] = ft_atoi(info->line, &j);
		if (errno != 0)
		{	
			write(2, "atoi fail\n", 10);
			return (NULL);
		}
		if (info->line[j] == ',' && ++j)
		{
			if (define_color(color, info->line, &j, i) == -1)
			{
				write(2, "define_color failed\n", 20);
				return (NULL);//les leaks
			}
		}
		else
			color[i] = NULL;
		i++;
	}
	return (color);
}

t_lst_final	*get_info(t_list *head)
{
	t_lst_final	*head_final;
	t_lst_final	*new_final;
	t_list		*snake;
	int			size_snake;
	int			i;
	char		**color;
	int			*line;

	size_snake = lstsize(head);
	i = size_snake;
	snake = head;
	head_final = NULL;
	line = NULL;
	color = NULL;
	while (snake)
	{
		color = init_color_line(snake, color, &line);
		if (!color)
		{
			printf("AH\n");
			return (lst_final_clear(&head_final, &head));
		}
		//printf("%d\n");
		int	u = 0;
		while (u < head->lenght)
		{
			//printf("%s\n", color[u]);
			printf("%d ", line[u++]);
		}
		printf("\n");
		new_final = lstnew_final(color, line, head->lenght, size_snake);
		if (!new_final)
			return (lst_final_clear(&head_final, &head));
		lstadd_back_final(&head_final, new_final);
		snake = snake->next;
	}
	lstclear(&head);
	return (head_final);
}*/

void	color_get(t_list *snake, int color, int *j)
{
	int	i;

	(*j)++;
	i = *j + 8;
	(void) snake;
	(void) color;
//	while (i < 6)
//		snake->line[(*j)];
}

void	init_z_color(t_list *snake, int *z, int *color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < snake->lenght)
	{
		z[i] = ft_atoi(snake->line, &j);
		if (errno)
			break ;//create error function
			//gd_error("ft_atoi : ");
		if (snake->line[j] == ',')
			color_get(snake, color[i], &j);
		i++;
	}
}

void	fill_map(t_list *head, t_map *map)
{
	t_list	*snake;
	int	i;

	i = 0;
	snake = head;
	while (snake)
	{
		init_z_color(snake, map->z[i], map->color[i]);
		i++;
		snake = snake->next;
	}
	lstclear(&head);
}

t_map	*char_to_int(t_list *head)
{
	t_map	*map;

	if (!head)
		return (NULL);
	map = map_init(head);
	fill_map(head, map);
	return (map);
}
