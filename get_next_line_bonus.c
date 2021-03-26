/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:15:44 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/18 19:15:58 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_getchar(t_gnl *obj, int fd)
{
	if (obj->ret[fd] == 0)
	{
		obj->ret[fd] = read(fd, obj->buf[fd], BUFFER_SIZE);
		if ((obj->ret[fd]) == -1)
			return (ft_free(&(obj->buf[fd]), -2));
		obj->bufl[fd] = obj->buf[fd];
	}
	if (obj->ret[fd] == 0)
		return (EOF);
	else
	{
		--(obj->ret[fd]);
		return ((unsigned char)(*(obj->bufl)[fd]++));
	}
}

int		get_line(t_gnl *obj, char **line, int fd, char c)
{
	int			i;
	int			n;

	n = BUFFER_SIZE;
	i = 0;
	while ((c = ft_getchar(obj, fd)) != EOF)
	{
		if (c == -2)
			return (ft_free(&(obj->buf[fd]), -1));
		if (c == '\n')
		{
			(*line)[i] = '\0';
			return (1);
		}
		(*line)[i] = c;
		++i;
		if (i == n)
		{
			if (!(*line = ft_resize(*line)))
				return (ft_free(&(obj->buf[fd]), -1));
			n = 2 * n;
		}
	}
	return (ft_free(&(obj->buf[fd]), 0));
}

int		get_next_line(int fd, char **line)
{
	static	t_gnl	head;
	char			c;

	c = '\0';
	if (head.buf[fd] == 0)
		head.buf[fd] = malloc(sizeof(char*) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || !(*line = ft_strnew(BUFFER_SIZE)))
		return (ft_free(&(head.buf[fd]), -1));
	return (get_line(&head, line, fd, c));
}
