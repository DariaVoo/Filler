/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:06:09 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/24 19:06:18 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map		new_map(void)
{
	t_map p;

	p.count_y = 0;
	p.count_x = 0;
	p.map = NULL;
	return (p);
}

t_filler	new_filler(void)
{
	t_filler f;

	f.map = new_map();
	f.player1_me = '\0';
	f.player2 = '\0';
	f.count_points_p2 = 0;
	return (f);
}

t_big_sqr	new_big_sqr(void)
{
	t_big_sqr b;

	b.square = INT32_MAX;
	b.x = -1;
	b.y = -1;
	return (b);
}

void		print_ans(int x, int y)
{
	if (x == -1)
		ft_printf("%d %d\n", 0, 0);
	else
		ft_printf("%d %d\n", x, y);
}
