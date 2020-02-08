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

# include <stdio.h>
# include "libftprintf.h"

# define USERNAME "snorcros"

typedef struct	s_filler
{
	int 	count_y;
	int 	count_x;
	int		**map;
	char 	player1_me;
	char 	player2;
}				t_filler;
