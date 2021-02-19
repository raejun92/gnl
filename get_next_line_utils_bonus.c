/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchoi <juchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:42:10 by juchoi            #+#    #+#             */
/*   Updated: 2021/02/19 11:47:56 by juchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	int		l;
	int		i;
	char	*str;

	l = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_l;

	src_l = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	while (src[src_l])
		src_l++;
	if (dstsize == 0)
		return (src_l);
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_l);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	i = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (dstsize == 0)
		return (src_l);
	if (dstsize <= dst_l)
		return (src_l + dstsize);
	while (dst_l + i + 1 < dstsize && src[i])
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (src_l + dst_l);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	s1_l;
	unsigned int	s2_l;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_l + s2_l + 1))))
		return (0);
	ft_strlcpy(str, s1, s1_l + 1);
	ft_strlcat(str, s2, (s1_l + s2_l + 1));
	return (str);
}
