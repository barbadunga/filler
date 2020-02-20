/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:47:56 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/20 22:59:27 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	parse_map(int **ptr, int rows, char symbol)
{
	register int	i;
	register int	j;
	char			*line;

	i = -1;
	while (++i < rows)
	{
		if (get_next_line(STDIN_FILENO, &line) != 1)
			return (1);
		line += 4;
		j = -1;
		while (line[++j])
		{
			if (line[j] == '.')
				ptr[i][j] = -1;
			else
				ptr[i][j] = ft_toupper(line[j]) == symbol ? 0 : WALL;
		}
		free(line - 4);
	}
	return (0);
}

static int	parse_token(int **ptr, int rows)
{
	register int	i;
	register int	j;
	char			*line;

	i = 0;
	while (i < rows)
	{
		if (get_next_line(STDIN_FILENO, &line) != 1)
		{
			free_2d(ptr, rows, NULL);
			return (1);
		}
		j = 0;
		while (line[j])
		{
			if (line[j] == '*')
				ptr[i][j] = 0;
			else
				ptr[i][j] = -1;
			j++;
		}
		free(line);
		i++;
	}
	return (0);
}

static int	skip_line()
{
	char	*line;

	if (get_next_line(STDIN_FILENO, &line) != 1)
		return (1);
	free(line);
	return (0);
}

t_map		*parse_input(t_bot *bot)
{
	char	*line;
	t_map	*token;

	if (get_next_line(STDIN_FILENO, &line) != 1)
		return (NULL);
	if (!bot->map && !(bot->map = init_map(line)))
		return (NULL);
	free(line);
	if (skip_line())
		return (NULL);
	if (parse_map(bot->map->map, bot->map->rows, bot->symbol))
		return (NULL);
	if (get_next_line(STDIN_FILENO, &line) != 1)
		return (NULL);
	if (!(token = init_map(line)))
		return (NULL);
	free(line);
	if (parse_token(token->map, token->rows))
		return (NULL);
	return (token);
}
