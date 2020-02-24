/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:24:18 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 16:17:20 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	*free_2d(int **arr, int rows, t_map *map)
{
	register int	i;

	i = 0;
	if (arr)
	{
		while (i < rows)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	if (map)
		free(map);
	return (NULL);
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

void	place_token(int **board, t_map *token, t_point2d *point, t_queue *q)
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
					enqueue(q, (t_point2d){point->x + j,
							point->y + i});
				board[point->y + i][point->x + j] = 0;
			}
			j++;
		}
		i++;
	}
}
