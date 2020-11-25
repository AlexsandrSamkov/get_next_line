/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weambros <weambros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:48:46 by weambros          #+#    #+#             */
/*   Updated: 2020/11/25 06:18:58 by weambros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	str = malloc(sizeof(char) * (1 + (s1 ? ft_strlen(s1) : 0)
	+ (s2 ? ft_strlen(s2) : 0)));
	if (!str)
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

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
