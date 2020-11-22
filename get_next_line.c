/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weambros <weambros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 06:37:24 by aleksandrsa       #+#    #+#             */
/*   Updated: 2020/11/22 09:49:09 by weambros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free(char **s1, int res)
{
	free(*s1);
	*s1 = 0;
	return (res);
}

int		ft_read_line(int fd, char **line)
{
	int		len;
	char	*tmp;
	char	*buff;

	tmp = 0;
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (read(fd, buff, 0) < 0)
		return (ft_free(&buff, -1));
	while ((len = read(fd, buff, BUFFER_SIZE)))
	{
		buff[len] = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buff)))
			return (ft_free(&buff, -1));
		ft_free(&tmp, 1);
		if (ft_strchr(buff, '\n') != -1)
			break ;
	}
	ft_free(&tmp, 0);
	return (ft_free(&buff, len));
}

int		ft_check_line(char **line, char **save)
{
	int		i;
	int		res;
	char	*tmp;

	tmp = *save;
	if ((i = ft_strchr(*save, '\n')) == -1)
	{
		if (!(*line = (ft_strdup(tmp, 0, 0, 0))))
			return (-1);
		if (!(*save = (ft_strdup("", 0, 0, 0))))
			return (-1);
		res = 0;
	}
	else
	{
		if (!(*line = (ft_strdup(tmp, i, 0, 1))))
			return (-1);
		if (!(*save = ft_strdup(tmp, 0, i + 1, 0)))
			return (-1);
		res = 1;
	}
	return (ft_free(&tmp, res));
}

int		get_next_line(int fd, char **line)
{
	static char	*save[4096];
	int			len;
	char		*tmp;

	tmp = save[fd];
	if (!(save[fd] = ft_strjoin(save[fd], "")))
		return (ft_free(&tmp,-1));
	free(tmp);
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ft_free(&save[fd], -1));
	if ((len = ft_read_line(fd, &save[fd])) == -1)
		return (ft_free(&save[fd], -1));
	if (len == 0 && save[fd][0] == '\0')
	{
		if (!(*line = ft_strdup("", 0, 0, 0)))
			return (ft_free(&save[fd], -1));
		return (ft_free(&save[fd], 0));
	}
	if ((len = ft_check_line(&*line, &save[fd])) == -1)
		return (ft_free(&save[fd], 0));
	if (len == 0)
		return (ft_free(&save[fd], 0));
	return (1);
}
