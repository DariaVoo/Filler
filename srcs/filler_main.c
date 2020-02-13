/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:22:59 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/08 01:23:00 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	new_map(void)
{
	t_map p;

	p.count_y = 0;
	p.count_x = 0;
	p.map = NULL;
	return (p);
}

t_filler new_filler(void)
{
	t_filler f;

	f.map = new_map();
	f.player1_me = '\0';
	f.player2 = '\0';
	f.count_points_p2 = 0;
	f.count_points_p1_me = 0;
	return (f);
}

int main(void)
{
	t_filler filler;
	int fd;
	int k;

	k = 0;
	filler = new_filler();
	fd = logic_first(&filler);
	//ft_printf("log first\n");
	if (fd != -1)
		while (k > -1) {
			k = logic(&filler, 0);
		//	ft_printf("log \n");
		}
	//ft_printf("log ");
	//close(fd);
	return (0);
}
//gcc -Wall -Wextra -Werror srcs/*.c -I ./includes  -I ft_printf/includes -L./ft_printf -lftprintf
//./filler_vm -p1 players/abanlin.filler  -p2 players/champely.filler -v -f maps/map03