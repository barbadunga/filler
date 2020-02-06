/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:04:01 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/06 20:21:05 by mshagga          ###   ########.fr       */
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

typedef union	s_point
{
	unsigned long long	val;
	int					xy[2];
}				t_point;

typedef struct	s_map
{
	int	**map;
	int	rows;
	int	cols;
}				t_map;

typedef struct	s_queue
{
	t_point	data[MAX_CELLS];
	int		tail;
	int		head;
}				t_queue;

typedef struct s_bot
{
	char    symbol;
	t_map	*map;
	t_queue	queue;
}			 	t_bot;

/*
** Init bot and map functions
*/

t_bot   *init_bot();
t_map	*init_map(char *plat);

/*
** Parse functions
*/

//void	parse_input(t_bot *bot);

t_point	make_choice(t_bot *bot, t_map *token, t_point *pos, int total);
int		lee_algorithm(int **board, int rows, int cols, t_queue *queue);
/*
** Debug tools
*/

void	bot_info(t_bot *bot);
void	write_line(char *line);
void	debug_init();
void	print_map(t_map *ptr);
void	write_number(int n1, int n2);
void	write_vec(t_vec *pos);
void	write_array(int **array, int rows, int cols);
void	write_queue(t_queue *q);

void	enqueue(t_queue *q, t_point point);
t_point	dequeue(t_queue *q);

#endif