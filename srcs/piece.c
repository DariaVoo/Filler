#include "filler.h"

int		check_set_piece(t_map filler, t_map piece, int m_x, int m_y)
{
	int i;
	int j;
	int	count_cross;

	i = 0;
	count_cross = 0;
	j = 0;
	while (i < piece.count_y && i + m_y < filler.count_y)
	{
		j = 0;
		while (j < piece.count_x && j + m_x < filler.count_x)
		{
			if (piece.map[i][j] == 1 && filler.map[i + m_y][j + m_x] == -2)
				return (0);
			else if (piece.map[i][j] == 1 && filler.map[i + m_y][j + m_x] == -1)
			{
				if (count_cross == 1)
					return (0);
				else
					count_cross = 1;
			}
			j++;
		}
		i++;
	}
	if (i < piece.count_y || j < piece.count_x)
		count_cross = 0;
	return (count_cross);
}

int		check_square(t_map filler, t_map piece, int m_x, int m_y)
{
	int i;
	int j;
	int		square;

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
	//когда я не могу поставить фигуру -> -1 -1
	t_big_sqr	sq;
	int		buf_sqr;
	int i;
	int j;

	i = 0;
	j = 0;
	sq = new_big_sqr();
	while (i < filler->map.count_y)
	{
		j = 0;
		while (j < filler->map.count_x)
		{
			if (check_set_piece(filler->map, piece, j, i))
				if ((buf_sqr = check_square(filler->map, piece, j, i)) < sq.square)
				{
//					ft_printf("min square = %d\n", buf_sqr);
					sq.square = buf_sqr;
					sq.x = i;
					sq.y = j;
				}
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", sq.x, sq.y);
	return (sq.x);
}

void	fill_piece(t_map *map, int fd)
{

	int	i;
	int j;
	char	*line;

	i = 0;
	line = NULL;//lose
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
/*
	ft_printf("PIECE\n");
	i = 0;
	while (i < map->count_y)
	{
		j = 0;
		while (j < map->count_x)
		{
			ft_printf("%3d", map->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
*/
}

t_map 	get_piece(int fd)
{
	t_map	piece;

	piece = new_map();
	create_map(&piece, fd, "Piece");
	if (!piece.count_x || !piece.map)
		return (piece);
	fill_piece(&piece, fd);
	return (piece);
}
