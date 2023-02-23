/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:44:14 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/23 16:31:56 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_last;

	if (!new)
	{
		return ;
	}
	if (!lst)
	{
		return ;
	}
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_last = lstlast(*lst);
	lst_last->next = new;
}
