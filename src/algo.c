/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:04:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/11 21:14:48 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**init_board(int rows, int cols)
{
	int		**res;
	int		i;

	if (!(res = (int**)malloc(sizeof(int*) * rows)))
		return (NULL);
	i = 0;
	while (i < rows)
	{
		if (!(res[i] = (int*)malloc(sizeof(int) * cols)))
			return (NULL);
		i++;
	}
	return (res);
}

void	copy_board(t_map *map, int **board, t_queue *queue, char symbol)
{
	const int		rows = map->rows;
	const int		cols = map->cols;
	register int	i;
	register int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			board[i][j] = map->map[i][j];
			if ((board[i][j] >> 24u) == symbol)
				enqueue(queue, (t_point2d){j, i});
			j++;
		}
		i++;
	}
}

void	place_token(int **board, t_map *token, t_point2d *point, t_queue *q, char symbol)
{
	const int	rows = token->rows;
	const int	cols = token->cols;
	int			i;
	int			j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (!token->map[i][j])
			{
				if ((board[point->y + i][point->x + j] >> 24u) == '.')
					enqueue(q, (t_point2d){point->x + j, point->y + i});
				board[point->y + i][point->x + j] = (int)symbol << 24u;
			}
			j++;
		}
		i++;
	}
}

void	init_all(t_map *board, t_bot *bot, t_queue *queue)
{
	const int	rows = bot->map->rows;
	const int	cols = bot->map->cols;
	t_point2d	points[rows * cols];

	if (!board->map)
		board->map = init_board(rows, cols);
	board->rows = rows;
	board->cols = cols;
	queue->data = points;
	queue->head = 0;
	queue->tail = 0;
//	initial_score(board);
}

int		check_token(t_map *b, t_map *token, t_point2d *point, char symbol)
{
	const int	rows = point->y;
	const int	cols = point->x;
	int			i;
	int			j;
	int			inter;

	i = 0;
	inter = 0;
	while (i < token->rows)
	{
		j = 0;
		while (j < token->cols)
		{
			if (!token->map[i][j] && (j + cols >= b->cols || i + rows >= b->rows))
				return (0);
			if (!token->map[i][j] && (b->map[i + rows][j + cols] >> 24u) == symbol)
				inter++;
			if (inter > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (inter);
}

int			get_score(t_map *board, t_map *token, t_point2d *point, t_queue *q)
{
	return (1);
}

t_point2d	main_loop(t_bot *bot, t_map *token, int rows, int cols)
{
	static t_map	board = {NULL, 0, 0};
	t_point2d		i;
	t_queue			queue;
	t_point2d		score;

	init_all(&board, bot, &queue);
	i.y = 0;
	score.y = 0;
	score.x = 0;
	print_map(bot->map);
	while (i.y < rows)
	{
		i.x = 0;
		while (i.x < cols)
		{
			if (check_token(bot->map, token, &i, bot->symbol))
			{
				copy_board(bot->map, board.map, &queue, bot->symbol);
				place_token(board.map, token, &i, &queue, bot->symbol);
				print_map(&board);
				write_queue(&queue);
//				score.x = get_score(&board, token, &i, &queue);
				score = queue.data[0];
			}
			reset_queue(&queue);
			i.x++;
		}
		i.y++;
	}
	return (score);
}