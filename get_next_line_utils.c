/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weambros <weambros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 06:53:18 by weambros          #+#    #+#             */
/*   Updated: 2020/11/18 06:55:55 by weambros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *pstr;

	if (!s1 && !s2)
		return (0);
	if (!(str = malloc(sizeof(char) + (s1 ? ft_strlen(s1) + 1 : 0)
	+ (s2 ? ft_strlen(s2) + 1 : 0))))
		return (0);
	pstr = str;
	if (s1)
		while (*s1)
			*pstr++ = *s1++;
	if (s2)
		while (*s2)
			*pstr++ = *s2++;
	*pstr = '\0';
	return (str);
}

int		ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s1, size_t len, size_t start, int flag)
{
	char	*s;
	size_t	i;

	i = 0;
	flag == 0 ? (len = ft_strlen(s1)) : (len);
	if (!(s = malloc(sizeof(char) * (len + 1 - start))))
		return (0);
	while (i + start < len && s1[i + start] != '\0')
	{
		s[i] = s1[i + start];
		i++;
	}
	s[i] = '\0';
	return (s);
}
