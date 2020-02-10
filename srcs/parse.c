/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 03:56:49 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/08 03:56:50 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			**create_table(int n, int m)
{
	int **ans;
	int i;

	i = -1;
	if (!(ans = (int **)malloc(sizeof(int *) * (n))))
		return (NULL);
	while (++i < n)
		if (!(ans[i] = (int *)malloc(sizeof(int) * (m))))
		{
			free_table((void **)ans, i);
			return (NULL);
		}
		else
			ft_memset(ans[i], 0, n);
	return (ans);
}

void	fill_map_filler(t_filler **filler, int fd)
{
	int	i;
	int j;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) && i < (*filler)->map.count_y && line[0] != 'P')
	{
		j = 4;
		while (j < (*filler)->map.count_x + 4)
		{
			if (line[j] == (*filler)->player1_me || line[j] == (*filler)->player1_me + 32)
			 	(*filler)->map.map[i][j - 4] = -1;
			else if (line[j] == (*filler)->player2 || line[j] == (*filler)->player2 + 32)
				(*filler)->map.map[i][j - 4] = -2;
			else
				(*filler)->map.map[i][j - 4] = 0;
			j++;
		}
		free(line);
		i++;
	}

	ft_printf("MAP\n");
	i = 0;
	while (i < (*filler)->map.count_y)
	{
		j = 0;
		while (j < (*filler)->map.count_x)
		{
			ft_printf("%3d", (*filler)->map.map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

t_map	*create_map(t_map *mmap, int fd, const char *word)
{
	char	**buf;
	char	*line;

	while (get_next_line(fd, &line) && !ft_strstr(line, word))
		free(line);
	buf = ft_strsplit(line, ' ');
	free(line);
	mmap->count_x = ft_atoi(buf[2]);
	mmap->count_y = ft_atoi(buf[1]);
	mmap->map = create_table(mmap->count_x, mmap->count_y);
	free_table((void**)buf, 2);
	return (mmap);
}

void	fill_pice(t_map *map, int fd)
{

	int	i;
	int j;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) && i < map->count_y)
	{
		j = 0;
		ft_printf("LINE %s\n", line);
		while (j < map->count_x)
		{
			ft_printf("i %d j %d\n", i, j);
			if (line[j] == '*') {
				map->map[i][j] = 1;
				ft_printf("map is *\n");
				ft_printf("%d ", map->map[i][j]);
			}
			else {
				map->map[i][j] = 0;
				ft_printf("map is .\n");
			}
			j++;
		}
		free(line);
		i++;
	}

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
}

t_map 	get_pice(int fd)
{
	t_map	piece;

	piece = new_map();
	create_map(&piece, fd, "Piece");
	ft_printf("count_x %d\tcount_y %d\n", piece.count_x, piece.count_y);
	fill_pice(&piece, fd);
	return (piece);
}

t_filler	*parse_filler(t_filler *filler, int fd)
{
	char		*line;

	get_next_line(fd, &line);
	free(line);
	while (get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
		if (*line == '$')
		{
			if (ft_strstr(line, USERNAME) && ft_strstr(line, "p1"))
			{
				filler->player1_me = 'O';
				filler->player2 = 'X';
			}
			else
			{
				filler->player1_me = 'X';
				filler->player2 = 'O';
			}
			break ;
		}
		free(line);
	}
	create_map(&filler->map, fd, "Plateau");
	printf("me = %c , enemy = %c \n", filler->player1_me, filler->player2);
	fill_map_filler(&filler, fd);
	return (filler);
}
