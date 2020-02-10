/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lee.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:14:28 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/10 18:30:06 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		g_row[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int		g_col[8] = {0, 1, 0, -1, -1, 1, 1, -1};

void	update_cost(t_map board, int index, t_point point, t_queue *queue)
{
	const int	val = board.map[point.xy[0]][point.xy[1]];
	int			**ptr;
	int			r;
	int			c;

	r = point.xy[0] + g_row[index];
	c = point.xy[1] + g_col[index];
	ptr = board.map;
	if ((r >= 0 && r < board.rows && c >= 0 && c < board.cols) &&
		ptr[r][c] == -1)
	{
		ptr[r][c] = val + 1;
		enqueue(queue, (t_point){(uint64_t)c << 32u | (unsigned int)r});
	}
}

int		count_score(int **board, int rows, int cols)
{
	int	i;
	int	j;
	int	res;
	int c;

	i = 0;
	res = 0;
	c = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (board[i][j] == -1)
			{
				c++;
				res += WALL * c;
			}
			else
				res += board[i][j];
//			res += board[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

int		lee_algorithm(int **board, int rows, int cols, t_queue *queue)
{
	int		i;
	int		res;
	t_point	cur;

	while (queue->head != queue->tail)
	{
		cur = dequeue(queue);
		i = 0;
		while (i < 8)
		{
			update_cost((t_map){board, rows, cols}, i, cur, queue);
			i++;
		}
//		write_number(cur.xy[0], cur.xy[1]);
//		write_array(board, rows, cols);
	}
//	write_array(board, rows, cols);
	res = count_score(board, rows, cols);
	return (res);
}