/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:05:22 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 21:44:22 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	destroy_bot(t_bot *bot, t_map *token)
{
	if (bot->enemy)
		free_2d(bot->enemy->map, bot->enemy->rows, NULL);
	if (bot->mine)
		free_2d(bot->mine->map, bot->mine->rows, NULL);
	free_2d(bot->map->map, bot->map->rows, bot->map);
	if (token)
		free_2d(token->map, token->rows, token);
	free(bot);
}

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
		return (1);
	while (TRUE)
	{
		if (!(token = parse_input(bot)))
		{
			destroy_bot(bot, NULL);
			return (1);
		}
		res = (t_point2d){-1, -1};
		if (main_loop(bot, token, &res))
		{
			destroy_bot(bot, token);
			return (1);
		}
		free_2d(token->map, token->rows, token);
		if (write_move(res))
			break ;
	}
	destroy_bot(bot, NULL);
	return (0);
}
