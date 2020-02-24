/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:38:56 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 21:47:53 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

SDL_Color g_mint = (SDL_Color){80, 147, 151};
SDL_Color g_white = (SDL_Color){255, 255, 255};
SDL_Color g_purple = {150, 50, 150};
SDL_Color g_dark_purple = {73, 19, 76};
SDL_Color g_black = {0, 0, 0};
SDL_Color g_pink = {216, 56, 80};
SDL_Color g_yellow = {242, 219, 122};

void	free_boards(t_board *ptr)
{
	int		i;
	t_board *tmp;

	while (ptr->prev)
		ptr = ptr->prev;
	while (ptr)
	{
		tmp = ptr->next;
		i = 0;
		while (i < ptr->row)
			free(ptr->tab[i++]);
		free(ptr->tab);
		free(ptr);
		ptr = tmp;
	}
}

void	*free_vis(t_vis *vis)
{
	if (vis->sur)
		SDL_FreeSurface(vis->sur);
	if (vis->win)
		SDL_DestroyWindow(vis->win);
	if (vis->board)
		free_boards(vis->board);
	if (vis->p1)
		free(vis->p1);
	if (vis->p2)
		free(vis->p2);
	if (vis->ui)
		free(vis->ui);
	free(vis);
	if (vis->title)
		TTF_CloseFont(vis->title);
	TTF_Quit();
	SDL_Quit();
	exit(1);
}

int		main(void)
{
	t_vis	*vis;

	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
		return (0);
	if (!(vis = init_visualizer()))
		return (0);
	vis->p1 = parse_player(vis);
	vis->p2 = parse_player(vis);
	parse_board(vis);
	if (!(vis->ui = init_ui(vis)))
		free_vis(vis);
	while (!vis->is_close)
	{
		event_loop(vis);
		render(vis, vis->board, vis->ui);
		parse_board(vis);
		SDL_UpdateWindowSurface(vis->win);
	}
	free_vis(vis);
	return (0);
}
