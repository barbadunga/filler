/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:52:53 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/15 22:20:46 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VISUALIZER_H
# define VISUALIZER_H

# include <SDL2/SDL.h>
# include "libft.h"
# include <SDL2/SDL_ttf.h>

# define TITLE		"filler"
# define HEADER		100
# define WIDTH		900
# define HEIGHT		WIDTH + HEADER
# define FRAME		2

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_board
{
	struct s_board	*prev;
	struct s_board	*next;
	char			**tab;
	int				row;
	int				col;
	int				score1;
	int				score2;
}				t_board;

typedef struct	s_ui
{
	SDL_Rect	frame;
	SDL_Rect	plat;
	SDL_Rect	cell;
	TTF_Font	*font;
	int			gap;
}				t_ui;

typedef struct	s_vis
{
	SDL_Window	*win;
	SDL_Surface	*sur;
	t_board		*board;
	t_ui		*ui;
	char		*p1;
	char		*p2;
	TTF_Font	*title;
	int			is_close;
	int			is_pause;
}				t_vis;

void	draw_rect(SDL_Surface *sur, SDL_Rect *rect, SDL_Color col);
void	render(t_vis *vis, t_board *board, t_ui *ui);
void	*free_vis(t_vis	*vis);
void	print_text(t_vis *vis, const char *text, t_point point, SDL_Color col);
void	event_loop(t_vis *vis);
void	parse_board(t_vis *vis);
void	draw_ui(t_vis *vis);

#endif