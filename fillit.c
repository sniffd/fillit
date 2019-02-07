/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:04:29 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/07 04:29:00 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int get_w(const char *str)
{
	int i;
	int min_w;
	int max_w;

	i = 0;
	min_w = -1;
	max_w = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (min_w < 0)
				min_w = i % 5;
			if (max_w < i % 5)
				max_w = i % 5;
		}
		i++;
	}
	return ((max_w - min_w) + 1);
}

int get_h(const char *str)
{
	int i;
	int min_h;
	int max_h;

	i = 0;
	min_h = -1;
	max_h = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (min_h < 0)
				min_h = i / 5;
			if (max_h < i / 5)
				max_h = i / 5;
		}
		i++;
	}
	return ((max_h - min_h) + 1);
}

//int get_tetros(char *file)
//{
//	int		fd;
//	char	buf[22];
//
//	fd = open(file, O_RDONLY);
//	while (read(fd, buf, 21))
//	{
//
//	}
//}