/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:50:37 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/02/04 19:50:37 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_block(const char *str)
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

void	cmp(const char *str, int i, int *sum)
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

int		check_tetro(const char *str)
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

int		check_file(char **buf, int fd, ssize_t *ret, int *counter)
{
	if (!(check_block(*buf)) || !(check_tetro(*buf)))
	{
		free(*buf);
		return (0);
	}
	free(*buf);
	*buf = ft_memalloc(1);
	read(fd, *buf, 1);
	if (!((**buf == '\n') || (!(**buf))))
	{
		free(*buf);
		return (0);
	}
	free(*buf);
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

int		validate(char *file)
{
	int		fd;
	ssize_t	ret;
	char	*buf;
	int		counter;

	buf = ft_memalloc(21);
	fd = open(file, O_RDONLY);
	ret = read(fd, buf, 20);
	counter = 0;
	if (ret)
		counter++;
	else
	{
		free(buf);
		return (0);
	}
	while (ret)
	{
		if (!(check_file(&buf, fd, &ret, &counter)))
			return (0);
	}
	free(buf);
	close(fd);
	return (1);
}
