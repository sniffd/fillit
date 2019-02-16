/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 02:32:25 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/17 02:32:43 by ldonnis          ###   ########.fr       */
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
