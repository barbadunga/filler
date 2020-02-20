/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:11:19 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/20 22:51:26 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	parse_plateau(t_map *map, char *plat)
{
//	const char	*cmp = "Plateau ";
//
//	while (*cmp)
//	{
//		if (*cmp != *plat)
//		{
//			free(plat);
//			free(map);
//			return (1);
//		}
//		cmp++;
//		plat++;
//	}
	while (*plat != ' ')
		plat++;
	map->rows = ft_atoi(plat++);
	while (*plat != ' ')
		plat++;
	map->cols = ft_atoi(plat);
	return (0);
}

t_map	*init_map(char *plat)
{
	register int	i;
	t_map			*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
	{
		free(plat);
		return (NULL);
	}
	if (parse_plateau(map, plat))
		return (NULL);
	if (!(map->map = (int **)malloc(sizeof(int*) * map->rows)))
	{
		free(plat);
		free(map);
		return (NULL);
	}
	i = -1;
	while (++i < map->rows)
		if (!(map->map[i] = (int *)ft_memalloc(sizeof(int) * map->cols)))
		{
			free(plat);
			return (free_2d(map->map, map->rows, map));
		}
	return (map);
}

t_bot	*init_bot(void)
{
	t_bot	*bot;
	char	*line;

	if (!(bot = (t_bot*)malloc(sizeof(t_bot))))
		return (NULL);
	if (get_next_line(STDIN_FILENO, &line) != 1)
	{
		free(bot);
		return (NULL);
	}
	bot->symbol = line[10] == '1' ? 'O' : 'X';
	bot->map = NULL;
	bot->mine = NULL;
	bot->enemy = NULL;
	free(line);
	return (bot);
}

int		init_all(t_map *board, t_bot *bot, t_queue *queue, t_point2d *score)
{
	const int	rows = bot->map->rows;
	const int	cols = bot->map->cols;

	if (!board->map && !(board->map = init_board(rows, cols)))
		return (1);
	if (!bot->mine)
		bot->mine = board;
	board->rows = rows;
	board->cols = cols;
	score->y = INT32_MIN;
	queue->head = 0;
	queue->tail = 0;
	score->x = -1;
	score->y = INT32_MIN;
	return (0);
}

int		**init_board(int rows, int cols)
{
	register int	i;
	int				**res;

	if (!(res = (int**)malloc(sizeof(int*) * rows)))
		return (NULL);
	i = 0;
	while (i < rows)
	{
		if (!(res[i] = (int*)malloc(sizeof(int) * cols)))
		{
			free_2d(res, rows, NULL);
			return (NULL);
		}
		i++;
	}
	return (res);
}
