/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weambros <weambros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:31:59 by weambros          #+#    #+#             */
/*   Updated: 2020/11/23 12:42:14 by weambros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_free(char **s, int res)
{
	if (!*s)
		return(res);
	free(*s);
	s = 0;
	return (res);
}

int ft_read_line(char **save, int fd)
{
	char *buff;
	char *tmp;
	int len;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return(-1);
	while ((len = read(fd, buff,BUFFER_SIZE)) > 0)
	{
		buff[len] = '\0';
		tmp = *save;
		if (!(*save = ft_strjoin(*save, buff)))
			return(ft_free(&buff, -1));
		ft_free(&tmp,0);
		if (ft_strchr(buff,'\n'))
			break;
	}
	return (ft_free(&buff, len));
}

int ft_check_line(char **line, char **save)
{
	char *check;
	char *tmp;

	check = ft_strchr(*save,'\n');
	if (check)
		{
			*check = '\0';
			if (!(*line = ft_strdup(*save)))
				return (-1);
			tmp = *save;
			if (!(*save = (ft_strdup(++check))))
				return (ft_free(&tmp, -1));
			return (ft_free(&tmp, 1));
		}
	if (!(*line = ft_strdup(*save)))
		return (-1);
	return (ft_free(&*save, 0));
}

int		get_next_line(int fd, char **line)
{
	static char *save;
	int len;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if ((len = ft_read_line(&save, fd)) == -1)
		return (-1);
	if (len == 0 && save[0] == '\0')
		{
			if (!(*line = ft_strjoin(*line, "")))
				return (-1);
			return (0);
		}
	return(ft_check_line(&*line, &save));
}
