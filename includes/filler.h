/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 02:13:04 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/08 02:13:05 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
# include "libftprintf.h"

# define USERNAME "abanlin"

typedef struct	s_map
{
	int 	count_x;
	int 	count_y;
	int		**map;
}				t_map;

typedef struct	s_filler
{
	t_map	map;
	char 	player1_me;
	char 	player2;
}				t_filler;


t_filler	new_filler(void);
t_map		new_map(void);
void		logic(t_filler *filler);
t_filler	*parse_filler(t_filler *filler, int fd);
int			**create_table(int n, int m);
void 		fill_map_filler(t_filler **filler, int fd);
t_map		*create_map(t_map *mmap, int fd);
int			ft_username_cmp(const char *s1, const char *s2);

# endif