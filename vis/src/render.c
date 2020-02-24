/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:55:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 17:16:09 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_rect(SDL_Surface *sur, SDL_Rect *rect, SDL_Color col)
{
	Uint32 pixel_value;

	pixel_value = SDL_MapRGB(sur->format, col.r, col.g, col.b);
	SDL_FillRect(sur, rect, pixel_value);
}

void	draw_ui(t_vis *vis)
{
	const int	center_x = WIDTH / 2;

	draw_rect(vis->sur, NULL, g_black);
	draw_rect(vis->sur, &vis->ui->frame, g_purple);
	draw_rect(vis->sur, &vis->ui->plat, g_dark_purple);
	print_text(vis, vis->p1, (t_point){center_x / 2,
									vis->ui->frame.y - 75}, g_mint);
	print_text(vis, vis->p2, (t_point){center_x + center_x / 2,
									vis->ui->frame.y - 75}, g_pink);
}

void	update_info(t_vis *vis, t_board *board)
{
	char		*score;
	const int	ctr = WIDTH / 2;

	if (!(score = ft_itoa(board->score1)))
		free_vis(vis);
	print_text(vis, score, (t_point){ctr / 2, vis->ui->frame.y - 25},
			board->score1 > board->score2 ? g_yellow : g_white);
	free(score);
	if (!(score = ft_itoa(board->score2)))
		free_vis(vis);
	print_text(vis, score, (t_point){ctr + ctr / 2, vis->ui->frame.y - 25},
			board->score2 > board->score1 ? g_yellow : g_white);
	free(score);
}

void	render(t_vis *vis, t_board *board, t_ui *ui)
{
	draw_ui(vis);
	update_info(vis, board);
	draw_grid(vis->sur, board, ui->cell, ui->gap);
}

void	print_text(t_vis *vis, const char *text, t_point point, SDL_Color col)
{
	SDL_Surface	*tmp_sur;
	SDL_Rect	position;
	int			w;
	int			h;

	if (TTF_SizeText(vis->title, text, &w, &h) == -1)
		free_vis(vis);
	if (!(tmp_sur = TTF_RenderText_Blended(vis->title, text, col)))
		free_vis(vis);
	position.x = point.x - w / 2;
	position.y = point.y - h / 2;
	SDL_BlitSurface(tmp_sur, NULL, vis->sur, &position);
	SDL_FreeSurface(tmp_sur);
}
