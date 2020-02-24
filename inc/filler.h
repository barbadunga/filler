/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:04:01 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/24 21:50:04 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define TRUE		1
# define FALSE		0
# define WALL		999
# define DEBUG_FILE	"debug.info"
# define MASK		0xFFFFFFFFu
# define MAX_CELLS	9900

# include "libft.h"

typedef	struct	s_point2d
{
	int	x;
	int	y;
}				t_point2d;

typedef struct	s_map
{
	int	**map;
	int	rows;
	int	cols;
}				t_map;

typedef struct	s_queue
{
	t_point2d	*data;
	int			tail;
	int			head;
}				t_queue;

typedef struct	s_bot
{
	t_map	*map;
	t_map	*mine;
	t_map	*enemy;
	char	symbol;
}				t_bot;

/*
** Init bot and map functions
*/

t_bot			*init_bot(void);
t_map			*init_map(char *plat);
int				init_all(t_map *board, t_bot *bot, t_queue *queue,
						t_point2d *score);
int				**init_board(int rows, int cols);

/*
** Parse functions
*/

t_map			*parse_input(t_bot *bot);

/*
** Main logic
*/

int				get_score(t_bot *bot, t_map *token, t_point2d *point,
							t_queue *q);
int				main_loop(t_bot *bot, t_map *token, t_point2d *res);

/*
** Queue functions
*/

t_point2d		dequeue(t_queue *q);
void			enqueue(t_queue *q, t_point2d point);
void			reset_queue(t_queue *q);

/*
** Utils function
*/

void			*free_2d(int **arr, int rows, t_map *map);
void			copy_board(t_map *map, int **board, t_queue *queue, int flag);
void			place_token(int **board, t_map *token, t_point2d *point,
						t_queue *q);

#endif
