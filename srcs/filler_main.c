/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:22:59 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/08 01:23:00 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main(void)
{
	t_filler filler;

	ft_printf("Heeee\n");
	logic(&filler);
	ft_printf("Hi!!");
	return (0);
}
//gcc -Wall -Wextra -Werror srcs/*.c -I ./includes  -I ft_printf/includes -L./ft_printf -lftprintf
