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
# include "libftprintf.h"

# define USERNAME "abanlin"

typedef struct	s_filler
{
	int 	count_y;
	int 	count_x;
	int		**map;
	char 	player1_me;
	char 	player2;
}				t_filler;


void		logic(t_filler *filler);
t_filler	*parse_filler(t_filler *filler);
int			**create_table(int n, int m);
void		fill_map(t_filler *map, char *line);
t_filler 	*create_map(t_filler *mmap);
int			ft_username_cmp(const char *s1, const char *s2);

# endif