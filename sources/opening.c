/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:30:33 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/16 11:29:04 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	count_l(char *to_c)
{
	int	i;
	int	count;
	int	save;

	i = 0;
	count = 0;
	while (1)
	{
		while (to_c[i] == ' ')
			i++;
		if (to_c[i] == '+' || to_c[i] == '-')
			i++;
		if (ft_isdigit(to_c[i]) && ++count)
			while (ft_isdigit(to_c[i]))
				i++;
		save = i + 9;
		if (to_c[i] == ',' && ++i)
			while (to_c[i] && i < save)
				i++;
		if (!(to_c[i] && to_c[i] == ' '))
			break ;
	}
	if (to_c[i] != '\0' && to_c[i] != '\n')
		return (-1);
	return (count);
}

t_list	*check_conformity(t_list *head, int fd)
{
	t_list	*parsing;

	parsing = head->next;
	head->lenght = count_l(head->line);
	if (head->lenght == -1)
		return (lstclear(&head));
	while (parsing)
	{
		parsing->lenght = count_l(parsing->line);
		if (parsing->lenght != head->lenght || parsing->lenght == -1)
			return (lstclear(&head));
		parsing = parsing->next;
	}
	user_error(0, NULL, NULL, fd);
	return (head);
}

t_list	*gnl_user(char **argv, t_list *tab, t_list *head)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		user_error(1, NULL, NULL, fd);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			if (errno == 0)
				break ;
			user_error(2, head, tab, fd);
		}
		tab = lstnew(str, ft_strlen(str));
		lstadd_back(&head, tab);
		if (!tab || !head)
			user_error(3, head, tab, fd);
	}
	return (check_conformity(head, fd));
}
