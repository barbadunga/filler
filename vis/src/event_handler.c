/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:05:59 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/16 18:48:16 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	keyboard_handle(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		vis->is_close = 1;
	else if (event->key.keysym.scancode == SDL_SCANCODE_LEFT)
	{
		if (vis->board->prev)
			vis->board = vis->board->prev;
	}
	else if (event->key.keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		if (vis->board->next)
			vis->board = vis->board->next;
	}
	else if (event->key.keysym.scancode == SDL_SCANCODE_S)
	{
		while (vis->board->prev)
			vis->board = vis->board->prev;
	}
	else if (event->key.keysym.scancode == SDL_SCANCODE_E)
	{
		while (vis->board->next)
			vis->board = vis->board->next;
	}
}

void	event_loop(t_vis *vis)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.scancode != SDL_SCANCODE_SPACE)
			{
				vis->is_pause = 1;
				keyboard_handle(vis, &event);
			}
			else
				vis->is_pause ^= 1;
		}
		if( event.type == SDL_QUIT )
			vis->is_close = 1;
	}
	if (!vis->is_pause)
	{
		if (!vis->board->next)
			parse_board(vis);
		else
			vis->board = vis->board->next ? vis->board->next : vis->board;
	}
}