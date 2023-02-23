/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:22:34 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/23 16:34:32 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_list	*final;
	t_map	*map;

	if (argc == 2 && argv)
	{
		if (is_fdf(argv[1]) == -1)
			return (2);
		final = gnl_user(argv, NULL, NULL);
		map = char_to_int(final);
		do_it(map);
		//lst_final_clear(&info, NULL);
		//if (info)
		//	clear_map(NULL, info, info->max_y);
	}
	else
		return (1);
	return (0);
}
