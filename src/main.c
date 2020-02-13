/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:05:22 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/13 22:59:52 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		write_move(t_point2d move)
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
	t_point2d	res;

	if (!(bot = init_bot()))
		return (0);
	debug_init();
	bot_info(bot);
	while (TRUE)
	{
		if (!(token = parse_input(bot)))
		{
			free(bot);
			return (0);
		}
		res.x = -1;
		res.y = -1;
		main_loop(bot, token, &res);
		if (write_move(res))
			break ;
	}
	return (0);
}
