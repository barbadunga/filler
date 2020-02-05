/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:04:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/05 21:44:46 by mshagga          ###   ########.fr       */
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

void	copy_board(int **map, int **board, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			board[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

void	place_token(int **board, t_map *token, int r, int c)
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
				board[r + i][c + j] = 0;
			j++;
		}
		i++;
	}
}

int		get_score(int **board, int rows, int cols)
{

}

t_point	make_choice(t_bot *bot, t_map *token, t_point *pos, int total)
{
	static int		**board;
	t_point			res;
	int				i;
	int				score;
	int				tmp;

	i = 0;
	if (!board)
		board = init_board(bot->map->rows, bot->map->cols);
	score = INT16_MAX;
	while (i < total)
	{
		copy_board(bot->map->map, board, bot->map->rows, bot->map->cols);
		place_token(board, token, pos[i].xy[0], pos[i].xy[1]);
//		write_array(board, bot->map->rows, bot->map->cols);
		lee_algotihm(board, ) // TODO implement
		get_score() // TODO implement
		if (tmp < score)
			score = tmp;
		i++;
	}
	return (res);
}