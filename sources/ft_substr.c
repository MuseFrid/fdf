/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:38:37 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/21 17:20:50 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = (char *) s;
	i = ft_strlen(new);
	if ((size_t) start > i)
		return (ft_strdup(""));
	if (i < len)
		return (ft_strdup((char *) s + start));
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (start >= i)
		return (new);
	i = 0;
	while (i < len)
		new[i++] = s[start++];
	new[i] = 0;
	return (new);
}
