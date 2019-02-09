#include "fillit.h"

// int put_in(t_tr list)
// {
// 	if (map[x])
// }

char *solve(char *map, t_tr *list)
{
	while (list)
	{
		list = list->next;
		printf("name:%c\n", list->name);
	}
	return (map);
}

int count_tetr(t_tr *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	j = i;
	while (j != 0)
		list = list->prev;
	return (i);
}

char *create_map(int map_size)
{
	int i;
	int w;
	int eol;
	char *map;

	eol = map_size;
	w = (map_size + 1) * map_size;
	i = 0;
	map = (char*)ft_memalloc(w + 1);
	map[i] = '.';
	i++;
	while (i < w - 1)
	{
		if (i % eol == 0)
		{
			eol = eol + map_size + 1;
			map[i] = '\n';
		}
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

char *map(t_tr *list)
{
	char *map;
	int map_size;
	int size;

	map_size = 2;
	size = (count_tetr(list) - 1) * 4;
	while (map_size * map_size < size)
		map_size++;
	map = create_map(map_size);
	map = solve(map, list);
	return (map);
}

int main(int argc, char **argv)
{
	t_tr *list;

	list = 0;
	if (argc == 2)
	{
		if(validate(argv[1]))
		{
			printf("GOOD\n");
			list = get_tetros(argv[1]);
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