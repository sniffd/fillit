/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:17 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/06 02:18:08 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_tr
{
	char		name;
	int			h;
	int			w;
	int			o;
	struct s_tr	*next;
	struct s_tr	*prev;
}				t_tr;

int		validate(char *file);
#endif
