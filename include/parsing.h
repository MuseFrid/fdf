/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:21:28 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:18:57 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_list
{
	char			*line;
	int				lenght;
	struct s_list	*next;
}	t_list;

int		is_fdf(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*gnl_user(char **argv, t_list *tab, t_list *head);
t_list	*check_conformity(t_list *head, int fd);
void	user_error(int pick, t_list *head, t_list *tab, int fd);

#endif
