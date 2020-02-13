/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lee.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:14:28 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/13 23:00:08 by mshagga          ###   ########.fr       */
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

void				lee_algorithm(t_map *map, t_queue *queue)
{
	t_point2d		cur;

	while (queue->head != queue->tail)
	{
		cur = dequeue(queue);
		update_cost(map, &cur, queue);
	}
}
