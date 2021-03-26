/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:31:05 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/18 19:14:44 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_gnl
{
	int				ret[1024];
	char			*buf[1024];
	char			*bufl[1024];
}					t_gnl;

size_t				ft_strlen(const char *str);

char				*ft_strnew(int size);

char				*ft_resize(char *str);

int					ft_getchar(t_gnl *obj, int fd);

int					get_line(t_gnl *head, char **line, int fd, char c);

t_gnl				*ft_cr_n_elem(int fd);

int					get_next_line(int fd, char **line);

int					remove_lst(t_gnl **head, t_gnl *lst, int r);

int					ft_free(char **buf, int ch);

#endif
