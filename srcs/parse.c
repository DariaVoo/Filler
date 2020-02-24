/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 03:56:49 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/24 19:07:43 by snorcros         ###   ########.fr       */
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
			ft_memset(ans[i], 0, m);
	return (ans);
}

void		set_point_filler(t_filler **filler, int i, int j, char *line)
{
	if (line[j] == (*filler)->player1_me ||
		line[j] == (*filler)->player1_me + 32)
		(*filler)->map.map[i][j - 4] = -1;
	else if (line[j] == (*filler)->player2 ||
			line[j] == (*filler)->player2 + 32)
	{
		(*filler)->map.map[i][j - 4] = -2;
		(*filler)->count_points_p2++;
	}
	else
		(*filler)->map.map[i][j - 4] = 0;
}

int			fill_map_filler(t_filler **filler, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	(*filler)->count_points_p2 = 0;
	while (get_next_line(fd, &line) && line[0] != '0')
		free(line);
	if (!line || line[0] != '0')
		return (0);
	while (i < (*filler)->map.count_y && line)
	{
		j = 3;
		while (++j < (*filler)->map.count_x + 4 && line)
			set_point_filler(filler, i, j, line);
		i++;
		free(line);
		if (i < (*filler)->map.count_y)
			get_next_line(fd, &line);
	}
	return (1);
}

t_map		*create_map(t_map *mmap, int fd, const char *word)
{
	char	**buf;
	char	*line;

	while (get_next_line(fd, &line) && !ft_strstr(line, word))
		free(line);
	if (!line)
		return (mmap);
	buf = ft_strsplit(line, ' ');
	mmap->count_x = ft_atoi(buf[2]);
	mmap->count_y = ft_atoi(buf[1]);
	mmap->map = create_table(mmap->count_y, mmap->count_x);
	free_table((void**)buf, 2);
	free(line);
	return (mmap);
}

t_filler	*parse_filler(t_filler *filler, int fd)
{
	char		*line;

	while (get_next_line(fd, &line))
	{
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
			free(line);
			break ;
		}
		free(line);
	}
	create_map(&filler->map, fd, "Plateau");
	return (filler);
}
