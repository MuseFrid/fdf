/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:39:44 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/23 16:32:09 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	*lstclear(t_list **lst)
{
	t_list	*buf_lst;

	if (!lst)
		return (NULL);
	while (*lst)
	{
		buf_lst = *lst;
		*lst = (*lst)->next;
		free(buf_lst->line);
		free(buf_lst);
	}
	lst = NULL;
	return (NULL);
}
