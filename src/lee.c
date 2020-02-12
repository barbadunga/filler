/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lee.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:14:28 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/12 21:45:44 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		g_row[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int		g_col[8] = {0, 1, 0, -1, -1, 1, 1, -1};

void	update_cost(t_map *board, int index, t_point2d *point, t_queue *queue)
{
	const int	val = board->map[point->y][point->x];
	int			**ptr;
	int			r;
	int			c;

	r = point->y + g_row[index];
	c = point->x + g_col[index];
	ptr = board->map;
	if ((r >= 0 && r < board->rows && c >= 0 && c < board->cols) &&
		ptr[r][c] == -1)
	{
		ptr[r][c] = val + 1;
		enqueue(queue, (t_point2d){c, r});
	}
}

int		lee_algorithm(t_map *map, t_queue *queue)
{
	int			i;
	int			res;
	t_point2d	cur;

	while (queue->head != queue->tail)
	{
		cur = dequeue(queue);
		i = 0;
		while (i < 8)
		{
			update_cost(map, i, &cur, queue);
			i++;
		}
	}
//	res = count_score(board, rows, cols);
	return (res);
}