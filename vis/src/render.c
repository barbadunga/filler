/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:55:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/16 00:27:00 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

//const SDL_Color g_mint = {96, 148, 137};
const SDL_Color g_mint = {80, 147, 151};
const SDL_Color g_white = {255, 255, 255};
//const SDL_Color g_purple = {231, 79, 244};
const SDL_Color g_purple = {150, 50, 150};
const SDL_Color g_violet = {154, 48, 105};
const SDL_Color g_dark_purple = {73, 19, 76};
const SDL_Color g_peach = {233, 113, 64};
const SDL_Color g_black = {0, 0, 0};
const SDL_Color g_pink = {216, 56, 80};
const SDL_Color g_orange = {232, 145, 61};
const SDL_Color g_yellow = {242, 219, 122};
const SDL_Color g_blue = {38, 93, 218};
const SDL_Color g_bg = {65, 51, 51};

void	draw_rect(SDL_Surface *sur, SDL_Rect *rect, SDL_Color col)
{
	Uint32 pixel_value;

	pixel_value = SDL_MapRGB(sur->format, col.r, col.g, col.b);
	SDL_FillRect(sur, rect, pixel_value);
}

void	draw_ui(t_vis *vis)
{
	static int i;

	i++;
	print_text(vis, "filler", (t_point){WIDTH / 2, 25}, g_white);
	print_text(vis, vis->p1, (t_point){200, vis->ui->frame.y - 50}, g_mint);
	print_text(vis, vis->p2, (t_point){WIDTH - 100, vis->ui->frame.y - 50}, g_pink);
}

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
//			if (board->tab[i][j] != '.')
				draw_rect(sur, &cell, get_color(board->tab[i][j]));
			cell.x += gap + cell.w;
			j++;
		}
		cell.y += gap + cell.h;
		i++;
	}
}

void	render(t_vis *vis, t_board *board, t_ui *ui)
{
//	draw_rect(vis->sur, NULL, g_bg);
//	draw_ui(vis);
	draw_rect(vis->sur, &ui->frame, g_purple);
	draw_rect(vis->sur, &ui->plat, g_dark_purple);
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