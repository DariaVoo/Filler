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

int			ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

t_filler	*set_distance_on_map(t_filler *filler, int *points_p2)
{
	int k;
	int i;
	int j;
	int		distance;

	i = 0;
	while (i < filler->map.count_y)
	{
		j = 0;
		while (j < filler->map.count_x)
		{
			k = 0;
			while (k < filler->count_points_p2)
			{
				distance = ft_abs(i - points_p2[k]) + ft_abs(j - points_p2[k + 1]);
				if ((distance < filler->map.map[i][j] || filler->map.map[i][j] == 0)
					&& filler->map.map[i][j] >= 0)
					filler->map.map[i][j] = distance;
				k += 2;
			}
			j++;
		}
		i++;
	}

	ft_printf("TERMOMAP\n");
	i = 0;
	while (i < filler->map.count_y)
	{
		j = 0;
		while (j < filler->map.count_x)
		{
			ft_printf("%4d ", filler->map.map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}

	return (filler);
}

int			*get_positions(int count, t_map map, int idplayer)
{
	int	*positions;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (!(positions = (int *)malloc(sizeof(int) * count)))
		return (NULL);
	ft_bzero(positions, count);
	while (i < map.count_y)
	{
		j = 0;
		while (j < map.count_x)
		{
			if (map.map[i][j] == idplayer && k < count)
				//(map.map[i][j + 1] != idplayer || map.map[i][j - 1] != idplayer ||
				//map.map[i + 1][j] != idplayer || map.map[i - 1][j] != idplayer))
			{
				positions[k] = i;
				positions[k + 1] = j;
				k += 2;
			}
			j++;
		}
		i++;
	}
	return (positions);
}

int			logic(t_filler *filler, int fd)
{
	int		*p2_points;
	t_map	piece;
	int 	ans;


	if (!fill_map_filler(&filler, fd))
		return (-1);
	p2_points = get_positions(filler->count_points_p2 * 2, filler->map, -2);
	filler = set_distance_on_map(filler, p2_points);
	piece = get_piece(fd);
	ans = set_piece(filler, piece);
	free_table((void **)piece.map, piece.count_y - 1);
	free(p2_points);
	return (ans);
}

/*
	int k =0;
	while (k + 1 < filler->count_points_p2 * 2) {
		ft_printf("p2 %d %d\n", p2_points[k], p2_points[k + 1]);
		k += 2;
	}
	k = 0;
	while (k + 1 < filler->count_points_p1_me * 2) {
		ft_printf("me %d %d\n", my_points[k], my_points[k + 1]);
		k += 2;
	}
 */


