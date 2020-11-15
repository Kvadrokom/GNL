#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "head_gnl.h"

#define BUF_SIZE 1000

int		ft_strlen(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while(str[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);;
		i++;
	}
}

char	*join_str(char* start, char	*end)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	if (!start)
		return(end);
	else if (!end)
		return(start);
	else
		tmp = (char*)malloc(sizeof(char) * (ft_strlen(start) + ft_strlen(end) + 1));
	while(start[i])
	{
		tmp[i] = start[i];
		i++;
	}
	while(end[j])
	{
		tmp[i] = end[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return(tmp);
}

char		*find_ch(char	c, char	*str)
{
	char	*tmp;
	int		cnt;

	cnt = 0;
	tmp = NULL;
	while(*str)
	{
		if (*str == c)
		{
			tmp = str;
			str = str -cnt;
			return(tmp);
		}
		str++;
		cnt++;
	}
	return(tmp);
}


char	*ft_strnew(int	n)
{
	char	*str;
	int		i;

	i = 0;
	str  = malloc(sizeof(char) * (n + 1));
	while(i < n)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return(str);
}


char	*ft_strdup(char	*str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while(str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return(tmp);
}


void	ft_strcpy(char	*dest, char	*src)
{
	while(*src)
		*dest++ = *src++;
	while(*dest)
		*dest++ = '\0';
}

void	ft_strclr(char	*str)
{
	while(*str)
		*str++ = '\0';
}

char	*check_rem(char	*rem, char	**line)
{
	char	*pn;

	pn = NULL;
	if(rem)
	{
		if ((pn = find_ch('\n', rem)))
			{
				*pn = '\0';
				pn++;
				*line = ft_strdup(rem);
				ft_strcpy(rem, pn);
			}
			else
			{
				*line = ft_strdup(rem);
				ft_strclr(rem);
			}
	}
	else
		*line = NULL;
	return(pn);
}


int		get_line(int fd, char	**line, char**	rem)
{
	int			ret;
	char		buf[BUF_SIZE + 1];
	char		*pn;
	char		*tmp;

	pn = check_rem(*rem, line);
	while(!pn && (ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if ((pn = find_ch('\n', buf)))
			{
				*pn = '\0';
				pn++;
				*rem = ft_strdup(pn);
			}
		tmp = *line;
		*line = join_str(*line, buf);
		free(tmp);
	}
	return (ret || ft_strlen(*line));
}


T_gnl	*ft_cr_n_element(int fd)
{
	T_gnl	*new;
	new = (T_gnl*)malloc(sizeof(T_gnl));
	new->fd = fd;
	new->rem = ft_strnew(BUF_SIZE);
	new->next = NULL;
	return(new);
}


int		get_next_line(int fd, char	**line)
{
	static T_gnl	*head;
	T_gnl			*tmp;

	if(head == NULL)
		head = ft_cr_n_element(fd);
	tmp = head;
		while(tmp->fd != fd)
		{
			if(tmp->next == NULL)
			tmp->next = ft_cr_n_element(fd);
			tmp = tmp->next;
		}
	return(get_line(tmp->fd, line, &tmp->rem));
}


int		main(void)
{
	int		fd1;
	//int		fd2;
	char	*line;

	fd1 = open("sudoku.txt", O_RDONLY);
	//fd2 = open("text.txt", O_RDONLY);
	while (get_next_line(fd1, &line))
	{
		ft_putstr(line);
		ft_putstr("\n\n");
	}
	return (0);
}