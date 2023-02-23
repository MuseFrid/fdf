/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:19:26 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/10 16:12:34 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

t_list	*lstnew(char *str, int lenght);
void	*lstclear(t_list **lst);
void	lstadd_back(t_list **lst, t_list *new);
t_list	*lstlast(t_list *lst);
int		lstsize(t_list *lst);

#endif
