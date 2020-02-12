/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:11:19 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/12 18:06:32 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	*init_map(char *plat)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	while (*plat != ' ')
		plat++;
	map->rows = ft_atoi(plat++);
	while (*plat != ' ')
		plat++;
	map->cols = ft_atoi(plat);
	if (!(map->map = (int **)malloc(sizeof(int*) * map->rows)))
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		if (!(map->map[i] = (int *)ft_memalloc(sizeof(int) * map->cols)))
			return (NULL);
		i++;
	}
	return (map);
}

t_bot   *init_bot()
{
    t_bot   *bot;
    char    *line;

    if (!(bot = (t_bot*)malloc(sizeof(t_bot))))
        return (NULL);
    if (!(get_next_line(STDIN_FILENO, &line)))
    	return (NULL);
    bot->symbol = line[10] == '1' ? 'O' : 'X';
    bot->map = NULL;
    return (bot);
}

void	init_all(t_map *board, t_bot *bot, t_queue *queue, t_point2d *score)
{
	const int	rows = bot->map->rows;
	const int	cols = bot->map->cols;

	if (!board->map)
		board->map = init_board(rows, cols);
	board->rows = rows;
	board->cols = cols;
	queue->head = 0;
	queue->tail = 0;
	score->x = -1;
	score->y = -1;
//	initial_score(board);
}