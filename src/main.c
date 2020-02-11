/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:05:22 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/11 21:09:58 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		write_move(t_point2d	move)
{
	ft_putnbr(move.y);
	ft_putchar(' ');
	ft_putnbr(move.x);
	ft_putchar('\n');
	return (move.x < 0 && move.y < 0);
}

int		main(void)
{
	t_bot		*bot;
	t_map		*token;
	t_vec		*pos;
	t_point2d	res;
	int			i; // delete

	if (!(bot = init_bot()))
		return (0);
	debug_init();
	bot_info(bot);
	i = 0;
	while (TRUE)
	{
		token = parse_input(bot);
		res = main_loop(bot, token, bot->map->rows, bot->map->cols);
		if (write_move(res))
			break;
		i++;
	}
	return (0);
}

