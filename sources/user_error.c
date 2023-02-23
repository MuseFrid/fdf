/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:36:57 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:17:33 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	user_error(int pick, t_list *head, t_list *tab, int fd)
{
	if (pick == 1)
	{
		perror("open failed ");
		exit(3);
	}
	if (pick == 2 || pick == 3)
	{
		if (pick == 2)
			write (2, "get_next_line failed\n", 21);
		else
			write (2, "lstnew failed\n", 14);
		lstclear(&head);
		lstclear(&tab);
		exit(4);
	}
	close(fd);
}
