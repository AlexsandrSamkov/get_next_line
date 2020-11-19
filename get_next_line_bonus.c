/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weambros <weambros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 06:37:24 by aleksandrsa       #+#    #+#             */
/*   Updated: 2020/11/19 10:59:57 by weambros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_read_line(int fd, char **line)
{
	int		len;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	while ((len = read(fd, buff, BUFFER_SIZE)))
	{
		buff[len] = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(buff, '\n') != -1)
			break ;
	}
	return (len);
}

int		ft_check_line(char **line, char **save)
{
	int		i;
	char	*tmp;
	int		res;

	res = 0;
	tmp = *line;
	i = ft_strchr(tmp, '\n');
	if (i == -1)
		if (!(*line = (ft_strdup(tmp, 0, 0, 0)))
		|| !(*save = (ft_strdup("", 0, 0, 0))))
			return (-1);
		else
			res = 0;
	else
	{
		if (!(*line = (ft_strdup(tmp, i, 0, 1)))
		|| !(*save = ft_strdup(tmp, 0, i + 1, 0)))
			return (-1);
		res = 1;
	}
	free(tmp);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save;
	char		*tmp;
	int			len;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	tmp = save;
	if ((len = ft_read_line(fd, &tmp)) == -1)
		return (-1);
	if (len <= 0 && !tmp)
	{
		if (!(*line = ft_strdup("", 0, 0, 0)))
			return (-1);
		return (0);
	}
	if ((len = ft_check_line(&tmp, &save)) == -1)
		return (-1);
	*line = tmp;
	if (len == 0)
		return (0);
	return (1);
}