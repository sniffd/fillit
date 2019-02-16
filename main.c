/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/17 02:41:18 by ldonnis          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_tr	*list;
	char	*m;

	m = 0;
	if (argc == 2)
	{
		if (validate(argv[1]))
			list = create_list(argv[1]);
		else
		{
			ft_putstr("error\n");
			return (0);
		}
		m = solve(m, list);
		ft_putstr(m);
		ft_putchar('\n');
		free(m);
	}
	return (0);
}
