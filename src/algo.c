/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:04:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/13 22:59:01 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void inline	place_token(int **board, t_map *token, t_point2d *point,
								t_queue *q)
{
	const int		rows = token->rows;
	const int		cols = token->cols;
	register int	i;
	register int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (!token->map[i][j])
			{
				if (board[point->y + i][point->x + j] == -1)
					enqueue(q, (t_point2d){point->x + j, point->y + i});
				board[point->y + i][point->x + j] = 0;
			}
			j++;
		}
		i++;
	}
}

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

static int inline	count_score(int **mine, int **enemy, int rows, int cols)
{
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

static int inline	get_score(t_map *board, t_map *token, t_point2d *point,
								t_queue *q)
{
	static t_map	enemy = {NULL, 0, 0};
	static t_queue	q_e = {NULL, 0, 0};
	t_point2d		p[board->rows * board->cols];

	if (!enemy.map)
		if (!(enemy.map = init_board(board->rows, board->cols)))
			return (INT32_MIN);
	enemy.rows = board->rows;
	enemy.cols = board->cols;
	q_e.data = p;
	q_e.head = 0;
	q_e.tail = 0;
	copy_board(board, enemy.map, &q_e, TRUE);
	lee_algorithm(board, q);
	lee_algorithm(&enemy, &q_e);
	return (count_score(board->map, enemy.map, board->rows, board->cols));
}

void				main_loop(t_bot *bot, t_map *token, t_point2d *res)
{
	static t_map	board = {NULL, 0, 0};
	static t_queue	queue = {NULL, 0, 0};
	t_point2d		i;
	t_point2d		score;
	t_point2d		points[bot->map->rows * bot->map->cols];

	init_all(&board, bot, &queue, &score);
	queue.data = points;
	i.y = -1;
	while (++i.y < bot->map->rows)
	{
		i.x = -1;
		while (++i.x < bot->map->cols)
		{
			if (check_token(bot->map, token, &i))
			{
				copy_board(bot->map, board.map, &queue, FALSE);
				place_token(board.map, token, &i, &queue);
				score.x = get_score(&board, token, &i, &queue);
				if (score.x > score.y)
				{
					score.y = score.x;
					*res = i;
				}
			}
			reset_queue(&queue);
		}
	}
}
