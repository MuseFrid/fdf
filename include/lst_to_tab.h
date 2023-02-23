/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:28:14 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:28:16 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_TO_TAB_H
# define LST_TO_TAB_H

typedef struct s_map
{
	int				**z;
	int				**color;
	int				max_x;
	int				max_y;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int		ft_atoi(const char *str, int *j);
int		**init_double_tab(int x, int y);
int		ft_isdigit(int c);
int		define_color(char **color, char *str, int *j, int where);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**init_color_line(t_list *info, char **color, int **line);

void	free_double_tab(int **to_free, int size);
void	fill_map(t_list *head, t_map *map);
void	color_get(t_list *snake, int color, int *j);

t_map	*char_to_int(t_list *head);
t_map	*map_init(t_list *info);

#endif
