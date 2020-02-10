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
	return (f);
}

int main(void)
{
	t_filler filler;

	filler = new_filler();
	ft_printf("Heeee\n");
	logic(&filler);
	ft_printf("Hi!!");
	return (0);
}
//gcc -Wall -Wextra -Werror srcs/*.c -I ./includes  -I ft_printf/includes -L./ft_printf -lftprintf
