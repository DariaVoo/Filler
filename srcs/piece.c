/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:07:56 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/24 19:08:29 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_set_piece(t_map filler, t_map piece, int m_x, int m_y)
{
	int i;
	int j;
	int	count_cross;

	i = -1;
	count_cross = 0;
	j = -1;
	while (++i < piece.count_y && i + m_y < filler.count_y)
	{
		j = -1;
		while (++j < piece.count_x && j + m_x < filler.count_x)
			if (piece.map[i][j] == 1 && filler.map[i + m_y][j + m_x] == -2)
				return (0);
			else if (piece.map[i][j] == 1 && filler.map[i + m_y][j + m_x] == -1)
			{
				if (count_cross == 1)
					return (0);
				else
					count_cross = 1;
			}
	}
	if (i < piece.count_y || j < piece.count_x)
		count_cross = 0;
	return (count_cross);
}

int		check_square(t_map filler, t_map piece, int m_x, int m_y)
{
	int i;
	int j;
	int	square;

	i = 0;
	square = 0;
	while (i < piece.count_y && i + m_y < filler.count_y)
	{
		j = 0;
		while (j < piece.count_x && j + m_x < filler.count_x)
		{
			if (piece.map[i][j] == 1 && filler.map[i + m_y][j + m_x] != -1
				&& filler.map[i + m_y][j + m_x] != -2)
				square += filler.map[i + m_y][j + m_x];
			j++;
		}
		i++;
	}
	if (square == 0)
		return (INT32_MAX);
	return (square);
}

int		set_piece(t_filler *filler, t_map piece)
{
	t_big_sqr	sq;
	int			buf_sqr;
	int			i;
	int			j;

	i = -1;
	sq = new_big_sqr();
	while (++i < filler->map.count_y)
	{
		j = -1;
		while (++j < filler->map.count_x)
		{
			if (check_set_piece(filler->map, piece, j, i))
				if ((buf_sqr = check_square(filler->map, piece, j, i))
							< sq.square)
				{
					sq.square = buf_sqr;
					sq.x = i;
					sq.y = j;
				}
		}
	}
	print_ans(sq.x, sq.y);
	return (sq.x);
}

void	fill_piece(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = NULL;
	while (i < map->count_y && get_next_line(fd, &line))
	{
		j = 0;
		while (j < map->count_x)
		{
			if (line[j] == '*')
				map->map[i][j] = 1;
			else
				map->map[i][j] = 0;
			j++;
		}
		i++;
		free(line);
	}
}

t_map	get_piece(int fd)
{
	t_map	piece;

	piece = new_map();
	create_map(&piece, fd, "Piece");
	if (!piece.count_x || !piece.map)
		return (piece);
	fill_piece(&piece, fd);
	return (piece);
}
