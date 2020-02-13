/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:04:01 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/13 22:54:08 by mshagga          ###   ########.fr       */
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
# define MASK_X		(int)('X' << 24)
# define MASK_O		(int)('O' << 24)
# define MASK_DOT	(int)('.' << 24)
# define MASK_CHAR	0xFF000000

# include "libft.h"

typedef union	s_point
{
	unsigned long long	val;
	int					xy[2];
}				t_point;

typedef	struct	s_point2d
{
	int		x;
	int		y;
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

typedef struct s_bot
{
	char    symbol;
	t_map	*map;
}			 	t_bot;

/*
** Init bot and map functions
*/

t_bot   *init_bot(void);
t_map	*init_map(char *plat);
void	init_all(t_map *board, t_bot *bot, t_queue *queue, t_point2d *score);
int		**init_board(int rows, int cols);

/*
** Parse functions
*/

t_map	*parse_input(t_bot *bot);

/*
** Main logic
*/

t_point	make_choice(t_bot *bot, t_map *token, t_point *pos, int total);
void	lee_algorithm(t_map *map, t_queue *queue);

/*
** Debug tools
*/

void	bot_info(t_bot *bot);
void	write_line(char *line);
void	debug_init(void);
void	print_map(t_map *ptr);
void	write_number(int n1, int n2);
void	write_vec(t_vec *pos);
void	write_array(int **array, int rows, int cols);
void	write_queue(t_queue *q);

/*
** Queue functions
*/

t_point2d	dequeue(t_queue *q);
void	enqueue(t_queue *q, t_point2d point);
void	reset_queue(t_queue *q);


void	main_loop(t_bot *bot, t_map *token, t_point2d *res);
void	*free_2d(int **arr, int rows, t_map *map);
void	copy_board(t_map *map, int **board, t_queue *queue, int flag);

#endif