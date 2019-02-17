/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/17 03:04:43 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		m = fillit(m, list);
		ft_putstr(m);
		ft_putchar('\n');
		free(m);
		free_list(&list);
	}
	else
	{
		ft_putstr("usage: ./fillit file\n");
		return (1);
	}
	return (0);
}
