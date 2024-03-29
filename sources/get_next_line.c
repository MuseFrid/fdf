/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:14:55 by gduchesn          #+#    #+#             */
/*   Updated: 2023/01/31 19:06:13 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*set_errno(int pick)
{
	errno = pick;
	return (NULL);
}

char	*set_stash(char *buf, char (*stash)[BUFFER_SIZE + 1], int *ret)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n' && ++i)
	{
		*ret = (*ret) - 1;
		new = ft_substr(buf, 0, i);
		while (buf[i])
			(*stash)[j++] = buf[i++];
		(*stash)[j] = 0;
	}
	else
		new = ft_substr(buf, 0, i);
	free(buf);
	return (new);
}

char	*get_next(int fd, char (*stash)[BUFFER_SIZE + 1], char *str, int *ret)
{
	char		*buf;
	char		*new;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (str)
			free(str);
		return (NULL);
	}
	(*ret) = read(fd, buf, BUFFER_SIZE);
	if (*ret <= 0)
	{
		free(buf);
		return (str);
	}
	buf[(*ret)] = 0;
	new = ft_strjoin(str, buf);
	free(buf);
	if (str)
		free(str);
	if (!new)
		return (set_errno(3));
	buf = set_stash(new, stash, ret);
	return (buf);
}

char	*is_empty(char (*stash)[BUFFER_SIZE + 1])
{
	char	*str;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(*stash);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (set_errno(2));
	while (++i < len)
		str[i] = (*stash)[i];
	str[i] = 0;
	i = 0;
	while ((*stash)[i])
		(*stash)[i++] = 0;
	str = set_stash(str, stash, &i);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*str;
	int			ret;

	str = NULL;
	ret = BUFFER_SIZE;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (set_errno(1));
	if (stash[0] != 0)
	{
		str = is_empty(&(stash));
		if (!str)
			return (NULL);
	}
	if (stash[0] == 0)
	{
		while (ret == BUFFER_SIZE)
		{
			str = get_next(fd, &(stash), str, &ret);
			if (!str)
				return (NULL);
		}
	}
	return (str);
}
