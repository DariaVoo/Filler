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
	int fd;

	i = 0;
	fd = 0;
	fd = open("test", O_RDONLY);
	ft_printf("%d\n", fd);
	if (fd != -1)
		filler = parse_filler(filler, fd);
	close(fd);
	// while (i< filler->map.count_y)
	// {
	// 	j = 0;
	// 	while (j < filler->map.count_x)
	// 	{
	// 		printf("i = %d, j = %d\n", i, j);
	// 		printf("%d\n", filler->map.map[0][0]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// 		printf("%s\n", "SEGA");
}