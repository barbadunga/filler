/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:04:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/10 18:43:16 by mshagga          ###   ########.fr       */
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

void	copy_board(t_map *map, int **board, t_queue *queue)
{
	const int	rows = map->rows;
	const int	cols = map->cols;
	t_point		conv;
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			board[i][j] = map->map[i][j];
			if (!board[i][j])
			{
				conv.xy[0] = i;
				conv.xy[1] = j;
				enqueue(queue, conv);
			}
			j++;
		}
		i++;
	}
}

void	place_token(int **board, t_map *token, t_point point, t_queue *q)
{
	const int	rows = token->rows;
	const int	cols = token->cols;
	int			i;
	int			j;
	t_point		p;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (!token->map[i][j])
			{
				if (board[point.xy[0] + i][point.xy[1] + j])
				{
					p.xy[0] = point.xy[0] + i;
					p.xy[1] = point.xy[1] + j;
					enqueue(q, p);
				}
				board[point.xy[0] + i][point.xy[1] + j] = 0;
			}
			j++;
		}
		i++;
	}
}

void	enemy_mode(int **board, int rows, int cols, t_queue *queue)
{
	t_point		conv;
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (board[i][j] == WALL)
			{
				conv.xy[0] = i;
				conv.xy[1] = j;
				board[i][j] = 0;
				enqueue(queue, conv);
			}
			else if (!board[i][j])
				board[i][j] = WALL;
			j++;
		}
		i++;
	}
}

t_point	make_choice(t_bot *bot, t_map *token, t_point *pos, int total)
{
	t_queue			queue;
	static int		**board;
	int				i;
	int				score1, score2;
	int				tmp1, tmp2;
	int				res;
	int				flag;

	i = 0;
	if (!board)
		board = init_board(bot->map->rows, bot->map->cols);
	score1 = INT32_MAX;
	score2 = INT32_MIN;
	queue.head = 0;
	queue.tail = 0;
	res = 0;
	while (i < total)
	{
		flag = 0;
		copy_board(bot->map, board, &queue);
		place_token(board, token, pos[i], &queue);

		reset_queue(&queue);
		enemy_mode(board, bot->map->rows, bot->map->cols, &queue);
		tmp1 = lee_algorithm(board, bot->map->rows, bot->map->cols, &queue);
		if (tmp1 > score2)
		{
			score2 = tmp1;
			res = i;
		}
		i++;
		reset_queue(&queue);
	}
	return (pos[res]);
}

//t_point	make_choice(t_bot *bot, t_map *token, t_point *pos, int total)
//{
//	t_queue			queue;
//	static int		**board;
//	int				i;
//	int				score;
//	int				tmp;
//	int				res;
//
//	i = 0;
//	if (!board)
//		board = init_board(bot->map->rows, bot->map->cols);
//	score = INT32_MAX;
//	queue.head = 0;
//	queue.tail = 0;
//	res = 0;
//	while (i < total)
//	{
//		copy_board(bot->map, board, &queue);
//		place_token(board, token, pos[i], &queue);
//		tmp = lee_algorithm(board, bot->map->rows, bot->map->cols, &queue);
//		if (tmp < score)
//		{
//			score = tmp;
//			res = i;
//		}
//		i++;
//		reset_queue(&queue);
//	}
//	return (pos[res]);
//}