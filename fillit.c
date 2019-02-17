/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:04:29 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/16 00:06:37 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char	*fillit(char *m, t_tr *list)
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
	free(c);
	return (m);
}
