/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 03:52:31 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/08 03:52:32 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void logic(t_filler *filler)
{
	int i, j;

	i =0;
	j =0;
	filler = parse_filler(filler);
	while (i< filler->count_y)
	{
		while (j < filler->count_x)
		{
			ft_printf("%s\n", filler->map[i][j]);
			j++;
		}
		i++;
	}
}