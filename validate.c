/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:50:37 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/02/06 22:04:39 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_block(const char *str)
{
	int hash;
	int eol;
	int i;

	i = 0;
	eol = 0;
	hash = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '\n')
			eol++;
		if (!((str[i] == '.') || (str[i] == '#') || (str[i] == '\n')))
			return (0);
		if (!((i + 1) % 5) && (!(str[i] == '\n' || str[i] == '\0')) && i < 20)
			return (0);
		i++;
	}
	if (hash != 4 || (eol < 3 || eol > 4))
		return (0);
	if (!(str[19] == '\n' || !(str[19])))
		return (0);
	return (1);
}

static void	cmp(const char *str, int i, int *sum)
{
	if (i > 0)
	{
		if (i > 4)
		{
			if (str[i - 1] == '#')
				(*sum)++;
			if (str[i - 5] == '#')
				(*sum)++;
		}
		else if (str[i - 1] == '#')
			(*sum)++;
	}
	if (i < 19)
	{
		if (i < 15)
		{
			if (str[i + 1] == '#')
				(*sum)++;
			if (str[i + 5] == '#')
				(*sum)++;
		}
		else if (str[i + 1] == '#')
			(*sum)++;
	}
}

static int	check_tetro(const char *str)
{
	int sum;
	int i;

	sum = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			cmp(str, i, &sum);
		i++;
	}
	if (sum == 6 || sum == 8)
		return (1);
	return (0);
}

static int	check_file(char **buf, int fd, ssize_t *ret, int *counter)
{
	if (!(check_block(*buf)) || !(check_tetro(*buf)) || !(((*buf)[20] == '\n')
	|| (!((*buf)[20]))))
	{
		free(*buf);
		return (0);
	}
	*buf = ft_memalloc(21);
	*ret = read(fd, *buf, 20);
	if (*ret)
		(*counter)++;
	if (*counter > 26)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

int			validate(char *file)
{
	int		fd;
	ssize_t	ret;
	ssize_t oret;
	char	*buf;
	int		counter;

	buf = ft_memalloc(22);
	fd = open(file, O_RDONLY);
	ret = 1;
	counter = 0;
	while (ret)
	{
		oret = ret;
		ret = read(fd, buf, 21);
		if (oret == 21 && !ret)
		{
			free(buf);
			return (0);
		}
		if (!(check_file(&buf, fd, &ret, &counter)))
			return (0);
	}
	free(buf);
	close(fd);
	return (1);
}
