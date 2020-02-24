/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:04:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 16:14:43 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int inline	check_token(t_map *b, t_map *token, t_point2d *point)
{
	const int		rows = point->y;
	const int		cols = point->x;
	register int	i;
	register int	j;
	int				inter;

	i = 0;
	inter = 0;
	while (i < token->rows)
	{
		j = 0;
		while (j < token->cols)
		{
			if (!token->map[i][j] && (j + cols >= b->cols || i + rows >= b->rows
				|| b->map[i + rows][j + cols] == WALL))
				return (0);
			if (!token->map[i][j] && !b->map[i + rows][j + cols])
				inter++;
			if (inter > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (inter);
}

static int inline	count_score(t_bot *bot, int rows, int cols)
{
	const int		**mine = (const int **)bot->mine->map;
	const int		**enemy = (const int **)bot->enemy->map;
	register int	i;
	register int	j;
	int				score;

	i = -1;
	score = 0;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (mine[i][j] == -1)
				score--;
			else if (enemy[i][j] == -1)
				score++;
			else if (mine[i][j] >= enemy[i][j])
				score--;
			else if (enemy[i][j] > mine[i][j])
				score++;
		}
	}
	return (score);
}

static inline void	update_score(t_bot *bot, t_point2d *score, t_point2d *res,
									t_point2d *current)
{
	score->x = count_score(bot, bot->map->rows, bot->map->cols);
	if (score->x > score->y)
	{
		score->y = score->x;
		*res = *current;
	}
}

int					main_loop(t_bot *bot, t_map *token, t_point2d *res)
{
	static t_map	board = {NULL, 0, 0};
	static t_queue	queue = {NULL, 0, 0};
	t_point2d		i;
	t_point2d		score;
	t_point2d		points[bot->map->rows * bot->map->cols];

	if (init_all(&board, bot, &queue, &score))
		return (1);
	queue.data = points;
	i.y = -1;
	while (++i.y < bot->map->rows)
	{
		i.x = -1;
		while (++i.x < bot->map->cols)
			if (check_token(bot->map, token, &i))
			{
				if (get_score(bot, token, &i, &queue))
					return (1);
				update_score(bot, &score, res, &i);
				reset_queue(&queue);
			}
	}
	return (0);
}
