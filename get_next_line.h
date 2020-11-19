/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weambros <weambros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 06:53:51 by weambros          #+#    #+#             */
/*   Updated: 2020/11/19 05:18:28 by weambros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> // удалить
# include <stdio.h> // удлаить
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1, size_t len, size_t start, int flag);
int		ft_read_line(int fd, char **line);
int		ft_check_line(char **line, char **save);
int		get_next_line(int fd, char **line);
#endif
