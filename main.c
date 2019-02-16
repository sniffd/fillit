/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/17 02:04:55 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill(char *str, int **c)
{
	char	*num;
	int		i;
	int		index;

	i = 0;
	index = 0;
	num = "0123456789ABCDEF";
	while (*str)
	{
		while (num[i] != *str)
			i++;
		(*c)[index] = i;
		index++;
		str++;
		i = 0;
	}
}

void	get_coord_h(char n, int o, int **mas)
{
	if (n == 'L' && o == 3)
		fill("2567", mas);
	if (n == 'J' && o == 3)
		fill("0127", mas);
	if (n == 'L' && o == 1)
		fill("0125", mas);
	if (n == 'J' && o == 1)
		fill("0567", mas);
	if (n == 'T' && o == 0)
		fill("0126", mas);
	if (n == 'T' && o == 2)
		fill("1567", mas);
	if (n == 'S' && o == 0)
		fill("1256", mas);
	if (n == 'Z' && o == 0)
		fill("0167", mas);
}

void	get_coord_v(char n, int o, int **mas)
{
	if (n == 'L' && o == 0)
		fill("05AB", mas);
	if (n == 'J' && o == 0)
		fill("16AB", mas);
	if (n == 'L' && o == 2)
		fill("016B", mas);
	if (n == 'J' && o == 2)
		fill("015A", mas);
	if (n == 'T' && o == 1)
		fill("156B", mas);
	if (n == 'T' && o == 3)
		fill("056A", mas);
	if (n == 'S' && o == 1)
		fill("056B", mas);
	if (n == 'Z' && o == 1)
		fill("156A", mas);
}

void	get_coord(char n, int o, int **mas)
{
	if (n == 'O')
		fill("0156", mas);
	if (n == 'I' && o == 0)
		fill("05AF", mas);
	if (n == 'I' && o == 1)
		fill("0123", mas);
	get_coord_v(n, o, mas);
	get_coord_h(n, o, mas);
}

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

int		check_and_place(t_tr *list, int *c, char **m, int i)
{
	size_t	size;

	size = ft_strchr(*m, '\n') - *m + 1;
	if ((c[3] / 5 * size) + (c[3] % 5) + i < ft_strlen(*m) &&
	(*m)[(c[0] / 5 * size) + (c[0] % 5) + i] == '.' &&
	(*m)[(c[1] / 5 * size) + (c[1] % 5) + i] == '.' &&
	(*m)[(c[2] / 5 * size) + (c[2] % 5) + i] == '.' &&
	(*m)[(c[3] / 5 * size) + (c[3] % 5) + i] == '.')
	{
		(*m)[(c[0] / 5 * size) + (c[0] % 5) + i] = list->l;
		(*m)[(c[1] / 5 * size) + (c[1] % 5) + i] = list->l;
		(*m)[(c[2] / 5 * size) + (c[2] % 5) + i] = list->l;
		(*m)[(c[3] / 5 * size) + (c[3] % 5) + i] = list->l;
		return (1);
	}
	else
		return (0);
}

void	replace(int *c, char **m, int i)
{
	size_t	size;

	size = ft_strchr(*m, '\n') - *m + 1;
	(*m)[(c[0] / 5 * size) + (c[0] % 5) + i] = '.';
	(*m)[(c[1] / 5 * size) + (c[1] % 5) + i] = '.';
	(*m)[(c[2] / 5 * size) + (c[2] % 5) + i] = '.';
	(*m)[(c[3] / 5 * size) + (c[3] % 5) + i] = '.';
}

void	out_of_range(t_tr **list, int **c, char **m)
{
	if ((*list)->prev)
	{
		(*list)->i = 0;
		(*list) = (*list)->prev;
		get_coord((*list)->name, (*list)->o, c);
		replace(*c, m, (*list)->i);
		((*list)->i)++;
	}
	else
	{
		free(*m);
		*m = map((*list)->head, (ft_strchr(*m, '\n') - *m + 1));
		(*list) = (*list)->head;
		while ((*list)->next && ((*list)->i = 0))
			(*list) = (*list)->next;
		(*list) = (*list)->head;
		(*list)->i = 0;
	}
}

char	*solve(char *m, t_tr *list)
{
	int *c;

	m = map(list, 0);
	c = (int*)ft_memalloc(sizeof(int) * 4);
	while (list)
	{
		get_coord(list->name, list->o, &c);
		if (check_and_place(list, c, &m, list->i))
			list = list->next;
		else if ((size_t)((c[3] / 5 * (ft_strchr(m, '\n') - m + 1)) +
		(c[3] % 5)) + list->i > ft_strlen(m))
			out_of_range(&list, &c, &m);
		else
			(list->i)++;
	}
	return (m);
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
			printf("error\n");
			return (0);
		}
		m = solve(m, list);
		ft_putstr(m);
		ft_putchar('\n');
		free(m);
	}
	return (0);
}
