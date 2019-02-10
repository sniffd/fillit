#include "fillit.h"

// int put_in(t_tr list)
// {
// 	if (map[x])
// }



int	*get_coord_h(char n, int o)
{
	int a[4];

	if (n == 'L' && o == 3 && (a[0] = 2) && (a[1] = 5) && (a[2] = 6) && (a[3] = 7))
		return (a);
	if (n == 'J' && o == 3 && (a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 7))
		return (a);
	if (n == 'L' && o == 1 && (a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 7))
		return (a);
	if (n == 'J' && o == 1 && (a[0] = 0) && (a[1] = 5) && (a[2] = 6) && (a[3] = 7))
		return (a);
	if (n == 'T' && o == 0 && (a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 6))
		return (a);
	if (n == 'T' && o == 2 && (a[0] = 1) && (a[1] = 5) && (a[2] = 6) && (a[3] = 7))
		return (a);
	if (n == 'S' && o == 0 && (a[0] = 1) && (a[1] = 2) && (a[2] = 5) && (a[3] = 6))
		return (a);
	if (n == 'Z' && o == 0 && (a[0] = 0) && (a[1] = 1) && (a[2] = 6) && (a[3] = 7))
		return (a);
	return (0);
}

int	*get_coord_v(char n, int o)
{
	int a[4];

	if (n == 'L' && o == 0 && (a[0] = 0) && (a[1] = 5) && (a[2] = 10)
		&& (a[3] = 11))
		return (a);
	if (n == 'J' && o == 0 && (a[0] = 1) && (a[1] = 6) && (a[2] = 10)
		&& (a[3] = 11))
		return (a);
	if (n == 'L' && o == 2 && (a[0] = 0) && (a[1] = 1) && (a[2] = 6) && (a[3] = 11))
		return (a);
	if (n == 'J' && o == 2 && (a[0] = 0) && (a[1] = 1) && (a[2] = 5) && (a[3] = 10))
		return (a);
	if (n == 'T' && o == 1 && (a[0] = 1) && (a[1] = 5) && (a[2] = 6) && (a[3] = 11))
		return (a);
	if (n == 'T' && o == 3 && (a[0] = 0) && (a[1] = 5) && (a[2] = 6) && (a[3] = 10))
		return (a);
	if (n == 'S' && o == 1 && (a[0] = 0) && (a[1] = 5) && (a[2] = 6) && (a[3] = 11))
		return (a);
	if (n == 'Z' && o == 1 && (a[0] = 1) && (a[1] = 5) && (a[2] = 6) && (a[3] = 10))
		return (a);
	return (0);
}

int	*get_coord(char n, int o)
{
	int a[4];
	int	*tmp;

	if (n == 'O' && (a[0] = 0) && (a[1] = 1) && (a[2] = 5) && (a[3] = 6))
		return (a);
	if (n == 'I' && o == 0 && (a[0] = 0) && (a[1] = 5) && (a[2] = 10)
		&& (a[3] = 15))
		return (a);
	if (n == 'I' && o == 0 && (a[0] = 0) && (a[1] = 1) && (a[2] = 2) && (a[3] = 3))
		return (a);
	if ((tmp = get_coord_h(n, o)))
		return (tmp);
	return (get_coord_v(n, o));
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
	int		i;
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

char	*map(t_tr *list)
{
	char	*map;
	int		map_size;
	int		size;

	map_size = 2;
	size = (count_tetr(list)) * 4;
	while (map_size * map_size < size)
		map_size++;
	map = create_map(map_size);
	//map = solve(map, list);
	return (map);
}

int main(int argc, char **argv)
{
	t_tr	*list;

	list = 0;
	if (argc == 2)
	{
		if(validate(argv[1]))
		{
			printf("GOOD\n");
			list = create_list(argv[1]);
		}
		//else
		//	printf("error\n");
		printf("map:\n%s\n", map(list));
		// while (list)
		// {
		// 	printf("name:%c\n", list->name);
		// 	printf("o:%d\n", list->o);
		// 	list = list->next;
		// }
	}
	return (0);
}