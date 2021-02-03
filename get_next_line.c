/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchoi <juchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:38:56 by juchoi            #+#    #+#             */
/*   Updated: 2021/02/01 11:19:16 by juchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 3

int	get_next_line(int fd, char **line)
{
	char		*tmp;
	char		*buf;
	static char	*store[OPEN_MAX];
	int			read_len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!(tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))));
		return (-1);
	while (read_len = read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[read_len] = '\0';
	}
}
