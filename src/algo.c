/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:04:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/06 22:59:24 by mshagga          ###   ########.fr       */
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

void	enqueue(t_queue *q, t_point point)
{
	if (q->tail >= MAX_CELLS)
		return ;
	q->data[q->tail++] = point;
}

t_point	dequeue(t_queue *q)
{
	return (q->data[q->head++]);
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

int		get_score(int **board, int rows, int cols)
{
	return (0);
}

void	reset_queue(t_queue *q)
{
	q->head = 0;
	q->tail = 0;
}

t_point	make_choice(t_bot *bot, t_map *token, t_point *pos, int total)
{
	t_queue			queue;
	static int		**board;
	int				i;
	int				score;
	int				tmp;
	int				res;

	i = 0;
	if (!board)
		board = init_board(bot->map->rows, bot->map->cols);
	score = INT32_MAX;
	queue.head = 0;
	queue.tail = 0;
	res = 0;
	while (i < total)
	{
		copy_board(bot->map, board, &queue);
		place_token(board, token, pos[i], &queue);
//		write_queue(&queue);
//		write_array(board, bot->map->rows, bot->map->cols);
		tmp = lee_algorithm(board, bot->map->rows, bot->map->cols, &queue);
//		write_number(tmp, 1);
		if (tmp < score)
		{
			score = tmp;
			res = i;
		}
		i++;
		reset_queue(&queue);
	}
	return (pos[res]);
}