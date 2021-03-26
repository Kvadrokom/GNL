/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:07:17 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/18 19:14:35 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strnew(int size)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new)
	{
		while (i < size)
			new[i++] = '\0';
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

int			ft_free(char **buf, int ch)
{
	free(*buf);
	*buf = NULL;
	return (ch);
}

char		*ft_resize(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(2 * ft_strlen(str));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	str = tmp;
	return (str);
}
