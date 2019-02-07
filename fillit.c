/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:04:29 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/07 07:37:47 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_w(const char *str)
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

int		get_h(const char *str)
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

//...
//...
char	get_name_h(char *str, int *o)
{
	while (*str != '#')
		str++;
	*o = 3;
	if (*(str + 3) == '#')
		return ('L');
	if ((*(str + 7) == '#') && (*(str + 2) == '#'))
		return ('J');
	*o = 2;
	if ((*(str + 4) == '#') && (*(str + 6) == '#'))
		return ('T');
	*o = 1;
	if ((*(str + 7) == '#') && (*(str + 5) == '#'))
		return ('J');
	if ((*(str + 2) == '#') && (*(str + 5) == '#'))
		return ('L');
	*o = 0;
	if ((*(str + 2) == '#') && (*(str + 6) == '#'))
		return ('T');
	if ((*(str + 4) == '#') && (*(str + 1) == '#'))
		return ('S');
	else
		return ('Z');
}

//..
//..
//..
char	get_name_v(char *str, int *o)
{
	while (*str != '#')
		str++;
	*o = 3;
	if ((*(str + 6) == '#') && (*(str + 10) == '#'))
		return ('T');
	*o = 0;
	if ((*(str + 10) == '#') && (*(str + 11) == '#'))
		return ('L');
	if ((*(str + 9) == '#') && (*(str + 10) == '#'))
		return ('J');
	*o = 2;
	if ((*(str + 1) == '#') && (*(str + 10) == '#'))
		return ('J');
	if ((*(str + 1) == '#') && (*(str + 6) == '#'))
		return ('L');
	*o = 1;
	if ((*(str + 4) == '#') && (*(str + 10) == '#'))
		return ('T');
	if ((*(str + 6) == '#') && (*(str + 11) == '#') && (*(str + 5) == '#'))
		return ('S');
	else
		return ('Z');
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