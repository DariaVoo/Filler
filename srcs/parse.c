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

	i = 0;
	if (!(ans = (int **)malloc(sizeof(int *) * (n))))
		return (NULL);
	while (++i < n)
		if (!(ans[i] = (int *)malloc(sizeof(int) * (m))))
		{
			free_table(ans, i);
			return (NULL);
		}
		else
			ft_memset(ans[i], 0, n);
	return (ans);
}

char		fill_map(t_filler map, char *line)
{
	int	i;
	int j;

	i = 0;
	j = 4;
	while (get_next_line(0, &line) && i < map.count_y && line[0] != 'P')
	{
		while (line[j] != '\0' && j < map.count_x)
		{
			if (line[j] == map.player1 || line[j] == map.player1 + 32)
				map.map[i][j] = -1;
			else if (line[j] == map.player2 || line[j] == map.player2 + 32)
				map.map[i][j] = -2;
			j++;
		}
		i++;
	}
}

t_map		create_map(t_filler mmap)
{
	int		**map;
	char	**buf;
	char	*line;

	buf = ft_strsplit(get_next_line(0, &line), ' ');
	free(line);
	mmap.count_x = ft_atoi(buf[2]);
	mmap.count_y = ft_atoi(buf[1]);
	mmap.map = create_table(mmap.count_x, mmap.count_y);
	free_table(buf, 2);
	get_next_line(0, &line);
	free(line);
	fill_map(mmap, line);
	return (mmap);
}

int			ft_username_cmp(const char *s1, const char *s2)
{
	while (*s1 != '.' && *s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

t_filler	parse_first(void)
{
	char		*line;
	t_filler	filler;

	while (get_next_line(0, &line))
		if (*line == '$' && !ft_username_cmp(line[21], USERNAME))
		{
			if (line[10] == '1')
			{
				filler.player1_me = 'X';
				filler.player2 = 'O';
			}
			else
			{
				filler.player1_me = 'O';
				filler.player2 = 'X';
			}
			break ;
		}
	return (create_map(filler));
}
