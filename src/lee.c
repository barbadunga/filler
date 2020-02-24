/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lee.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:14:28 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 21:46:28 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					g_row[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int					g_col[8] = {0, 1, 0, -1, -1, 1, 1, -1};

static void inline	update_cost(t_map *board, t_point2d *point, t_queue *queue)
{
	register int	i;
	int				r;
	int				c;
	int				**ptr;

	ptr = board->map;
	i = 0;
	while (i < 8)
	{
		r = point->y + g_row[i];
		c = point->x + g_col[i];
		if ((r >= 0 && r < board->rows && c >= 0 && c < board->cols)
				&& ptr[r][c] == -1)
		{
			ptr[r][c] = ptr[point->y][point->x] + 1;
			enqueue(queue, (t_point2d){c, r});
		}
		i++;
	}
}

static void			lee_algorithm(t_map *map, t_queue *queue)
{
	t_point2d		cur;

	while (queue->head != queue->tail)
	{
		cur = dequeue(queue);
		update_cost(map, &cur, queue);
	}
}

int					get_score(t_bot *bot, t_map *token, t_point2d *point,
								t_queue *q)
{
	const t_map		*board = bot->mine;
	static t_map	enemy = {NULL, 0, 0};
	static t_queue	q_e = {NULL, 0, 0};
	t_point2d		p[board->rows * board->cols];

	if (!enemy.map && !(enemy.map = init_board(board->rows, board->cols)))
		return (1);
	if (!bot->enemy)
		bot->enemy = &enemy;
	copy_board(bot->map, bot->mine->map, q, FALSE);
	place_token(bot->mine->map, token, point, q);
	enemy.rows = board->rows;
	enemy.cols = board->cols;
	q_e = (t_queue){p, 0, 0};
	copy_board((t_map *)board, enemy.map, &q_e, TRUE);
	lee_algorithm((t_map *)board, q);
	lee_algorithm(&enemy, &q_e);
	return (0);
}
