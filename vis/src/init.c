/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:29:24 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 17:31:46 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_vis	*init_visualizer(void)
{
	t_vis	*vis;

	if (!(vis = (t_vis *)ft_memalloc(sizeof(t_vis))))
		return (NULL);
	if (!(vis->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (free_vis(vis));
	if (!(vis->sur = SDL_GetWindowSurface(vis->win)))
		return (free_vis(vis));
	if (!(vis->title = TTF_OpenFont("./res/title.ttf", 60)))
		free_vis(vis);
	vis->is_pause = 1;
	return (vis);
}

t_ui	*init_ui(t_vis *vis)
{
	t_ui	*ui;
	int		w;
	int		h;
	int		tmp;
	int		size_cell;

	if (!(ui = (t_ui *)malloc(sizeof(t_ui))))
		return (NULL);
	w = (int)(0.95 * WIDTH);
	h = w * vis->board->row / vis->board->col;
	ui->frame = (SDL_Rect){ (WIDTH - w) / 2, HEADER + (w - h) / 2,
							w, h + FRAME};
	ui->plat = (SDL_Rect){ui->frame.x + FRAME, ui->frame.y + FRAME,
							ui->frame.w - 2 * FRAME, ui->frame.h - 2 * FRAME};
	w = ui->plat.w;
	tmp = (int)(0.95 * w);
	ui->gap = (w - tmp) / (vis->board->col + 1);
	ui->gap += ui->gap ? 0 : 1;
	size_cell = (w - ui->gap * (vis->board->col + 1)) / vis->board->col;
	tmp = (w - (size_cell * vis->board->col + ui->gap *
			(vis->board->col + 1))) / 2;
	ui->cell = (SDL_Rect){ui->plat.x + ui->gap + tmp, ui->plat.y +
			ui->gap + tmp, size_cell, size_cell};
	return (ui);
}

char	*parse_player(t_vis *vis)
{
	char	*line;
	char	*name;
	char	*end;
	char	*ptr;

	name = NULL;
	while (!name && get_next_line(STDIN_FILENO, &line) == 1)
	{
		if ((end = ft_strstr(line, ".filler]")))
		{
			ptr = end;
			*end = 0;
			while (*ptr != '/')
				ptr--;
			if (!(name = ft_memdup(ptr + 1, end - ptr + 1)))
				free_vis(vis);
		}
		free(line);
	}
	return (name);
}
