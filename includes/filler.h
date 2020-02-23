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

# define USERNAME "snorcros"

typedef struct	s_map
{
	int 	count_x;
	int 	count_y;
	int		**map;
}				t_map;

typedef struct	s_filler
{
	t_map	map;
	char 	player1_me;//always -1 on map
	char 	player2;
	int 	count_points_p2;
	int 	count_points_p1_me;
}				t_filler;


typedef struct	s_big_sqr
{
	int 	x;
	int 	y;
	int		square;
}				t_big_sqr;


t_filler	new_filler(void);
t_map		new_map(void);
int			logic(t_filler *filler, int fd);
t_filler	*parse_filler(t_filler *filler, int fd);
int			**create_table(int n, int m);
int 		fill_map_filler(t_filler **filler, int fd);
t_map		*create_map(t_map *mmap, int fd, const char *word);

//logic
int			*get_positions(int count, t_map map, int idplayer);
t_filler	*set_distance_on_map(t_filler *filler, int *points_p2);
t_map 		get_piece(int fd);

int			skip_map(int fd);
int			set_piece(t_filler *filler, t_map piece);
int 		check_set_piece(t_map filler, t_map piece, int m_x, int m_y);
int 		check_square(t_map filler, t_map piece, int m_x, int m_y);

# endif