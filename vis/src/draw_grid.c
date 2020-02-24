/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:27:06 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 17:27:10 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

SDL_Color	get_color(char c)
{
	if (c == 'X')
		return (g_pink);
	if (c == 'O')
		return (g_mint);
	if (c == 'x' || c == 'o')
		return (g_yellow);
	return ((SDL_Color){0, 0, 0});
}

void		draw_grid(SDL_Surface *sur, t_board *board, SDL_Rect cell, int gap)
{
	const int	start_x = cell.x;
	const int	rows = board->row;
	const int	cols = board->col;
	int			i;
	int			j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		cell.x = start_x;
		while (j < cols)
		{
			draw_rect(sur, &cell, get_color(board->tab[i][j]));
			cell.x += gap + cell.w;
			j++;
		}
		cell.y += gap + cell.h;
		i++;
	}
}
