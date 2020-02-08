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

int	**create_table(int N, int M)
{
	int **ans;
	int i;

	i = 0;
	if (!(ans = (int **)malloc(sizeof(int *) * (N))))
		return (NULL);
	while (++i < N)
		if (!(ans[i] = (int *)malloc(sizeof(int) * (M))))
		{
			free_table(ans, i);
			return (NULL);
		}
	else
		ft_memset(ans[i], 0, )

	ans[N] = NULL;
	return (ans);
}

 char fill_map(t_map map, char *line)
{

}

t_map create_map(int argc, char **chmap)
{
	t_map	mmap;
	int		**map;
	char	**buf;
	char 	*line;

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
