/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:04:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/12 21:57:11 by mshagga          ###   ########.fr       */
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

void	copy_board(t_map *map, int **board, t_queue *queue, int flag)
{
	const int		rows = map->rows;
	const int		cols = map->cols;
	register int	i;
	register int	j;
	int				**ptr;

	i = 0;
	ptr = map->map;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			board[i][j] = ptr[i][j];
			if (flag && !board[i][j])
				board[i][j] = WALL;
			else if (flag && board[i][j] == WALL)
				board[i][j] = 0;
			if (!board[i][j])
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
				if (board[point->y + i][point->x + j] == -1)
					enqueue(q, (t_point2d){point->x + j, point->y + i});
				board[point->y + i][point->x + j] = 0;
			}
			j++;
		}
		i++;
	}
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
			if (!token->map[i][j] && (j + cols >= b->cols || i + rows >= b->rows || b->map[i + rows][j + cols] == WALL))
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

int			get_score(t_map *board, t_map *token, t_point2d *point, t_queue *q)
{
	static t_map	enemy = {NULL, 0, 0};
	t_queue			q_e;
	t_point2d		p[board->rows * board->cols];


	if (!enemy.map)
		enemy.map = init_board(board->rows, board->cols);
	enemy.rows = board->rows;
	enemy.cols = board->cols;
	q_e.data = p;
	copy_board(board, enemy.map, &q_e,  TRUE);
	lee_algorithm(board, q);
	write_line("Mine lee:");
	print_map(board);
	write_queue(&q_e);
	lee_algorithm(&enemy, &q_e);
	write_line("Enemy lee:");
	print_map((t_map *)&enemy);
	return (1);
}

void	main_loop(t_bot *bot, t_map *token, int rows, int cols, t_point2d *res)
{
	static t_map	board = {NULL, 0, 0};
	t_point2d		i;
	t_queue			queue;
	t_point2d		score;
	t_point2d		points[rows * cols];

	init_all(&board, bot, &queue, &score);
	queue.data = points;
	i.y = -1;
	while (++i.y < rows)
	{
		i.x = -1;
		while (++i.x < cols)
		{
			if (check_token(bot->map, token, &i, bot->symbol))
			{
				copy_board(bot->map, board.map, &queue, FALSE);
				place_token(board.map, token, &i, &queue, bot->symbol);
				score.x = get_score(&board, token, &i, &queue);
				if (score.x < score.y)
				{
					score.y = score.x;
					*res = i;
				}
			}
			reset_queue(&queue);
		}
	}
}