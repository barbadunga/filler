/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:05:22 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/05 21:44:46 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill_map(int **ptr, int rows, char symbol)
{
	char		*line;
	int			i;
	int 		j;

	i = -1;
	while (++i < rows)
	{
		if (get_next_line(STDIN_FILENO, &line) == -1)
			return (1);
		line += symbol == '*' ? 0 : 4;
		j = 0;
		while (line[j])
		{
			if (line[j] == '.')
				ptr[i][j] = -1;
			else
				ptr[i][j] = ft_toupper(line[j]) == symbol ? 0 : WALL;
			j++;
		}
		free(line - (symbol == '*' ? 0 : 4));
	}
	return (0);
}

t_map	*parse_input(t_bot *bot)
{
	char	*line;
	t_map	*token;

	if (get_next_line(STDIN_FILENO, &line) == -1)
		return (NULL);
	if (!bot->map && !(bot->map = init_map(line)))
		return (NULL);
//	free(line);
	if (get_next_line(STDIN_FILENO, &line) == -1)
		return (NULL);
//	free(line);
	if (fill_map(bot->map->map, bot->map->rows, bot->symbol))
		return (NULL);
	print_map(bot->map);
	get_next_line(STDIN_FILENO, &line);
	token = init_map(line);
	fill_map(token->map, token->rows, '*');
//	free(line);
	write_line(line);
	print_map(token);
	return (token);
}

int		check_place(t_map *map, t_map *token, int r, int c)
{
	const int	rows = token->rows;
	const int	cols = token->cols;
	int			i;
	int			j;
	int			inter;

	i = 0;
	inter = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (!token->map[i][j] && map->map[r + i][c + j] == WALL)
				return (0);
			if (!token->map[i][j] && !map->map[r + i][c + j])
				inter++;
			if (inter > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (inter);
}

int64_t	find_place(t_map *map, t_map *token, int rows, int cols)
{
	const int	size_w = token->rows;
	const int	size_h = token->cols;
	int			i;
	int			j;

	i = 0;
	while (i + size_w <= rows)
	{
		j = 0;
		while (j + size_h <= cols)
		{
			if (check_place(map, token, i, j))
				return (((uint64_t)i << 32u) | (unsigned int)j);
			j++;
		}
		i++;
	}
	return (-1);
}

t_vec	*get_all_pos(t_map *map, t_map *token, int rows, int cols)
{
	const int	size_w = token->rows;
	const int	size_h = token->cols;
	int			i;
	int			j;
	t_vec		*pos;
	t_point		conv;

	i = 0;
	pos = ft_vec_init(1, sizeof(t_point));
	while (i + size_w <= rows)
	{
		j = 0;
		while (j + size_h <= cols)
		{
			if (check_place(map, token, i, j))
			{
				conv.xy[0] = i;
				conv.xy[1] = j;
				ft_vec_add(&pos, &conv.val);
			}
			j++;
		}
		i++;
	}
	if (!pos->total)
	{
		free(pos);
		pos = NULL;
	}
	return (pos);
}

void	write_move(t_point	move)
{
	ft_putnbr(move.xy[0]);
	ft_putchar(' ');
	ft_putnbr(move.xy[1]);
	ft_putchar('\n');
}

int		main(void)
{
	t_bot		*bot;
	t_map		*token;
	t_vec		*pos;
	t_point		res;
	int			i;

	if (!(bot = init_bot()))
		return (0);
	debug_init();
	bot_info(bot);
	i = 0;
	while (TRUE)
	{
		token = parse_input(bot);
		if (!(pos = get_all_pos(bot->map, token, bot->map->rows, bot->map->cols)))
//			return (0);
			break;
		else
		{
			write_vec(pos);
			res = make_choice(bot, token, pos->data, pos->total);
			write_move(((t_point*)pos->data)[pos->total - 1]);
		}
		i++;
	}
	return (0);
}