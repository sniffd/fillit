/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/16 05:14:46 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*get_coord_h(char n, int o, int **mas)
{
	int *a;

    a = *mas;
	if (n == 'L' && o == 3 && (a[0] = 2) && (a[1] = 5) && (a[2] = 6) && (a[3] = 7))
		return (a);
	if (n == 'J' && o == 3 && !(a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 7))
		return (a);
	if (n == 'L' && o == 1 && !(a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 7))
		return (a);
	if (n == 'J' && o == 1 && !(a[0] = 0) && (a[1] = 5) && (a[2] = 6) && (a[3] = 7))
		return (a);
	if (n == 'T' && o == 0 && !(a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 6))
		return (a);
	if (n == 'T' && o == 2 && (a[0] = 1) && (a[1] = 5) && (a[2] = 6) && (a[3] = 7))
		return (a);
	if (n == 'S' && o == 0 && (a[0] = 1) && (a[1] = 2) && (a[2] = 5) && (a[3] = 6))
		return (a);
	if (n == 'Z' && o == 0 && !(a[0] = 0) && (a[1] = 1) && (a[2] = 6) && (a[3] = 7))
		return (a);
	return (0);
}

int	*get_coord_v(char n, int o, int **mas)
{
	int *a;

    a = *mas;
	if (n == 'L' && o == 0 && !(a[0] = 0) && (a[1] = 5) && (a[2] = 10)
		&& (a[3] = 11))
		return (a);
	if (n == 'J' && o == 0 && (a[0] = 1) && (a[1] = 6) && (a[2] = 10)
		&& (a[3] = 11))
		return (a);
	if (n == 'L' && o == 2 && !(a[0] = 0) && (a[1] = 1) && (a[2] = 6) && (a[3] = 11))
		return (a);
	if (n == 'J' && o == 2 && !(a[0] = 0) && (a[1] = 1) && (a[2] = 5) && (a[3] = 10))
		return (a);
	if (n == 'T' && o == 1 && (a[0] = 1) && (a[1] = 5) && (a[2] = 6) && (a[3] = 11))
		return (a);
	if (n == 'T' && o == 3 && !(a[0] = 0) && (a[1] = 5) && (a[2] = 6) && (a[3] = 10))
		return (a);
	if (n == 'S' && o == 1 && !(a[0] = 0) && (a[1] = 5) && (a[2] = 6) && (a[3] = 11))
		return (a);
	if (n == 'Z' && o == 1 && (a[0] = 1) && (a[1] = 5) && (a[2] = 6) && (a[3] = 10))
		return (a);
	return (0);
}

int	*get_coord(char n, int o, int **mas)
{
	int *a;
	int	*tmp;

    a = *mas;
	if (n == 'O' && !(a[0] = 0) && (a[1] = 1) && (a[2] = 5) && (a[3] = 6))
		return (a);
	if (n == 'I' && o == 0 && !(a[0] = 0) && (a[1] = 5) && (a[2] = 10)
		&& (a[3] = 15))
		return (a);
	if (n == 'I' && o == 1 && !(a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 3))
		return (a);
	if ((tmp = get_coord_h(n, o, mas)))
		return (tmp);
	return (get_coord_v(n, o, mas));
}

char *solve(char *map, t_tr *list)
{
	while (list)
	{
		printf("name:%c\n", list->name);
	}
	return (map);
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

int	check_and_place(t_tr *list, int *c, char **m, int i)//TODO запилить проверку на out of range
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

int main(int argc, char **argv)
{
	t_tr	*list;
    int *c;
    char *m;

	list = 0;
	if (argc == 2)
	{
		if(validate(argv[1]))
			list = create_list(argv[1]);
		else
		{
			printf("error\n");
			return (0);
		}
		m = map(list, 0);
        c = (int*)ft_memalloc(sizeof(int) * 4);
		while(list && list->i < 100)
        {
			get_coord(list->name, list->o, &c);
			if (check_and_place(list, c, &m, list->i))
				list = list->next;
			else if ((size_t)((c[3] / 5 * (ft_strchr(m, '\n') - m + 1)) + (c[3] % 5)) + list->i > ft_strlen(m))
			{
				if (list->prev)
				{
					list = list->prev;
					get_coord(list->name, list->o, &c);
					replace(c, &m, list->i);
					(list->i)++;
				}
				else
				{
					free(m);
					m = map(list->head, (ft_strchr(m, '\n') - m + 2));
					list = list->head;
					while (list->next)
					{
						list->i = 0;
						list = list->next;
					}
					list = list->head;
					list->i = 0;
				}
			}
			else
				(list->i)++;
		}
		printf("%s\n\n", m);
		// while (list)
		// {
		// 	printf("name:%c\n", list->name);
		// 	printf("o:%d\n", list->o);
		// 	list = list->next;
		// }
	}
	return (0);
}
