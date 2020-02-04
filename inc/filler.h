/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:04:01 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/04 23:20:51 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define TRUE		1
# define FALSE		0
# define WALL		999
# define DEBUG_FILE	"debug.info"
# include "libft.h"

typedef struct	s_map
{
	int	**map;
	int	rows;
	int	cols;
}				t_map;

typedef struct s_bot
{
	char    symbol;
	t_map	*map;
}			 	t_bot;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

/*
** Init bot and map functions
*/

t_bot   *init_bot();
t_map	*init_map(char *plat);

/*
** Parse functions
*/

//void	parse_input(t_bot *bot);

/*
** Debug tools
*/

void	bot_info(t_bot *bot);
void	write_line(char *line);
void	debug_init();
void	print_map(t_map *ptr);
void	write_number(int n1, int n2);

#endif