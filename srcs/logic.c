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
	int		fd;
	t_map	piece;

	fd = 0;
	fd = open("test", O_RDONLY);
	ft_printf("%d\n", fd);
	if (fd != -1) {
		filler = parse_filler(filler, fd);
		piece = get_pice(fd);
	}
	close(fd);

}