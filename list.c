/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 02:29:07 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/17 02:59:13 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tr	*malloc_tetr(t_tr **prev)
{
	t_tr	*list;

	list = (t_tr *)ft_memalloc(sizeof(t_tr));
	list->prev = *prev;
	*prev = list;
	return (list);
}

t_tr	*create_list(char *file)
{
	int		fd;
	char	l;
	char	buf[22];
	t_tr	*list;
	t_tr	*prev;

	fd = open(file, O_RDONLY);
	list = 0;
	prev = 0;
	l = 'A';
	while (read(fd, buf, 21))
		get_tetro(&list, &prev, buf, &l);
	return (list->head);
}
