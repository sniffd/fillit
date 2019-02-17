/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 03:05:26 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/02/17 03:06:03 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tetr(t_tr *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	*create_map(int map_size)
{
	size_t	i;
	size_t	size;
	int		eol;
	char	*map;

	eol = map_size + 1;
	size = (size_t)(eol * map_size);
	i = 0;
	map = (char*)ft_memalloc(size + 1);
	while (i < size - 1)
	{
		if ((i + 1) % eol == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

char	*map(t_tr *list, int s)
{
	int		map_size;
	int		size;

	if (!s)
		map_size = 2;
	else
		map_size = s;
	size = (count_tetr(list)) * 4;
	while (map_size * map_size < size)
		map_size++;
	return (create_map(map_size));
}
