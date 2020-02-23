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

int	main(void)
{
	t_filler filler;
	int fd;

	filler = new_filler();
	fd = 0;
	fd = open("../lel", O_RDONLY);
	if (fd != -1)
	{
		parse_filler(&filler, fd);
		while (1)
		{
			if (logic(&filler, fd) < 0)
			{
				free_table((void **)filler.map.map, filler.map.count_y - 1);
				return (0);
			}
		}
	}
	close(fd);
	return (0);
}
//gcc -Wall -Wextra -Werror srcs/*.c -I ./includes  -I ft_printf/includes -L./ft_printf -lftprintf
//./filler_vm -p1 players/abanlin.filler  -p2 players/champely.filler -v -f maps/map03