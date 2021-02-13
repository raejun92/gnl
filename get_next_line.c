/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchoi <juchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:38:56 by juchoi            #+#    #+#             */
/*   Updated: 2021/02/14 02:07:11 by juchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (0);
}

static int		split_store(char **line, char **store, char *store_point,
		char *buf)
{
	char	*tmp;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	*store_point = '\0';
	if (!(*line = ft_strdup(*store)))
		return (-1);
	store_point++;
	if (*store_point == '\0')
	{
		free(*store);
		*store = 0;
		return (1);
	}
	if (!(tmp = ft_strdup(store_point)))
		return (-1);
	free(*store);
	*store = tmp;
	return (1);
}

static int		end_line(char **line, char **store, char *buf, int read_len)
{
	char	*store_point;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	if (read_len < 0)
		return (-1);
	if (*store && (store_point = ft_strchr(*store, '\n')))
		return (split_store(line, store, store_point, buf));
	if (*store)
	{
		*line = *store;
		*store = 0;
		return (0);
	}
	if (!(*line = ft_strdup("")))
		return (-1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX];
	char		*store_point;
	char		*buf;
	char		*tmp;
	int			read_len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_len] = '\0';
		tmp = store[fd];
		store[fd] = ft_strjoin(store[fd], buf);
		free(tmp);
		if ((store_point = ft_strchr(store[fd], '\n')))
			return (split_store(line, &store[fd], store_point, buf));
	}
	return (end_line(line, &store[fd], buf, read_len));
}
