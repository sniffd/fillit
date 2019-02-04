/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/04 16:45:38 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_checktetr(const char *str)
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
		i++;
		if (!((i + 1) % 5) && (!(str[i] == '\n' || str[i] == '\0')) && i < 20)
			return (0);
	}
	if (hash != 4 || (eol < 3 || eol > 4))
		return (0);
	if (!(str[19] == '\n' || !(str[19])))
		return (0);
	return (1);
}

int ft_read(char *file)
{
	int fd;
	ssize_t ret;
	char *buf;
	int counter;

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
		if (!(ft_checktetr(buf)))
		{
			free(buf);
			return (0);
		}
		free(buf);
		buf = ft_memalloc(1);
		read(fd, buf, 1);
		if (!((*buf == '\n') || (!(*buf))))
		{
			free(buf);
			return (0);
		}
		free(buf);
		buf = ft_memalloc(21);
		ret = read(fd, buf, 20);
		if (ret)
			counter++;
		if (counter > 26)
		{
			free(buf);
			return (0);
		}
	}
	free(buf);
	close (fd);
	return (1);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		if(ft_read(argv[1]))
			printf("GOOD");
		else
			printf("error");
	}
	return (0);
}