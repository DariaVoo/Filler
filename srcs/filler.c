/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:22:59 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/24 19:06:25 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_filler	filler;
	int			fd;

	filler = new_filler();
	fd = 0;
	if (fd != -1)
	{
		parse_filler(&filler, fd);
		while (1)
		{
			if (logic(&filler, fd) < 0)
			{
				free_map(filler.map.map, filler.map.count_y);
				return (0);
			}
		}
	}
	return (0);
}
