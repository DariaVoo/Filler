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

#include "../includes/filler.h"

int			**create_table(int n, int m)
{
	int **ans;
	int i;

	i = 0;
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
			{
			 	(*filler)->map.map[i][j - 4] = -1;
			}
			if (line[j] == (*filler)->player2 || line[j] == (*filler)->player2 + 32)
			{
				(*filler)->map.map[i][j - 4] = -2;
			}
			if (!(line[j] == (*filler)->player2 || line[j] == (*filler)->player2 + 32) && !(line[j] == (*filler)->player1_me || line[j] == (*filler)->player1_me + 32))
			{
				// (*filler)->map.map[i][j - 4] = 0;
				ft_putnbr(i);
				ft_putchar(' ');
				ft_putnbr(j);
				ft_putchar('\n');
				// ft_putnbr((*filler)->map.map[i][j - 4]);
			}
			j++;
		}
		free(line);
		i++;
	}
	// i = 0;
	// while (i < filler->map.count_y)
	// {
	// 	j = 0;
	// 	while (j < filler->map.count_x)
	// 	{
	// 		printf("%3d", filler->map.map[i][j]);
	// 		j++;
	// 	}
	// 	ft_putchar('\n');
	// 	i++;
	// }

}

t_map	*create_map(t_map *mmap, int fd)
{
	char	**buf;
	char	*line;

	while (get_next_line(fd, &line) && !ft_strstr(line, "Plateau"))
		free(line);
	buf = ft_strsplit(line, ' ');
	free(line);
	mmap->count_x = ft_atoi(buf[2]);
	mmap->count_y = ft_atoi(buf[1]);
	mmap->map = create_table(mmap->count_x, mmap->count_y);

	free_table((void**)buf, 2);
	get_next_line(fd, &line);
	free(line);

	return (mmap);
}

t_filler	*parse_filler(t_filler *filler, int fd)
{
	char		*line;

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
	create_map(&filler->map, fd);
	printf(" me = %c , enemy = %c \n", filler->player1_me, filler->player2);
	fill_map_filler(&filler, fd);
	return (filler);
}
/*
t_map 	get_pice(int fd)
{
	t_map	piece;


	return ()
}*/