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

t_filler	*set_distance_on_map(t_filler *filler, int *points_p2)
{
	size_t k;
	size_t i;
	size_t j;
	int		distance;

	k = 0;
	i = 0;
	while (i < filler->map.count_y)
	{
		j = 0;
		while (j < filler->map.count_x)
		{
			distance = (i - points_p2[k]) % 500 + (j - points_p2[k + 1]) % 500;
			if ((distance < filler->map.map[i][j] || filler->map.map[i][j] == 0)
												&& filler->map.map[i][j] >= 0)
				filler->map.map[i][j] = distance;
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

int	*get_enemy_positions(int count, t_map map)
{
	int		*enemy_pos;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!(enemy_pos = (int *)malloc(sizeof(int) * count)))
		return (NULL);
	ft_bzero(enemy_pos, count);
	while (i < map.count_y)
	{
		j = 0;
		while (j < map.count_x)
		{
			if (map.map[i][j] == -2 && k < count)
			{
				enemy_pos[k] = i;
				enemy_pos[k + 1] = j;
				k += 2;
			}
			j++;
		}
		i++;
	}
	//enemy_pos[k] = -1;
	return (enemy_pos);
}

void logic(t_filler *filler)
{
	int		fd;
	int 	*p2_points;
	int	k = 0;
	//t_map	piece;

	fd = 0;
	fd = open("../test", O_RDONLY);
	ft_printf("%d\n", fd);
	if (fd != -1) {
		filler = parse_filler(filler, fd);
		p2_points = get_enemy_positions(filler->count_points_p2 * 2,
				filler->map);
		while (k + 1 < filler->count_points_p2 * 2)
		{
			ft_printf("%d %d\n", p2_points[k], p2_points[k+1]);
			k +=2;
		}
		filler = set_distance_on_map(filler, p2_points);
		get_pice(fd);
	}
	close(fd);

}