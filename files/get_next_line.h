/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:41:25 by skharjo           #+#    #+#             */
/*   Updated: 2020/11/19 20:31:41 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int			ft_getchar(int fd, char *buf);

int			get_next_line(int fd, char **line);

size_t		ft_strlen(const char *str);

char		*ft_strnew(int size);

char		*ft_resize(char *str);

int			get_line(int fd, char **line, int i, int n);

#endif
