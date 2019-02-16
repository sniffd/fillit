/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:17 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/17 02:40:52 by ldonnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_tr
{
	char		name;
	char		l;
	int			h;
	int			w;
	int			o;
	int			i;
	struct s_tr	*next;
	struct s_tr	*prev;
	struct s_tr	*head;

}				t_tr;

int				validate(char *file);
t_tr			*create_list(char *file);
int				get_w(const char *str);
int				get_h(const char *str);
char			get_name_h(char *str, int *o);
char			get_name_v(char *str, int *o);
void			get_tetro(t_tr **list, t_tr **prev, char *buf, char *l);
t_tr			*malloc_tetr(t_tr **prev);
t_tr			*create_list(char *file);
int				check_and_place(t_tr *list, int *c, char **m, int i);
void			replace(int *c, char **m, int i);
void			out_of_range(t_tr **list, int **c, char **m);
char			*solve(char *m, t_tr *list);
void			fill(char *str, int **c);
void			get_coord_h(char n, int o, int **mas);
void			get_coord_v(char n, int o, int **mas);
void			get_coord(char n, int o, int **mas);
char			*map(t_tr *list, int s);

#endif
