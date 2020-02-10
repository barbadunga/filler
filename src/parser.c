/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:47:56 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/10 17:19:42 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int		parse_map(int **ptr, int rows, char symbol, int **enemy)
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
		j = -1;
		while (line[++j])
		{
			if (line[j] == '.')
			{
				ptr[i][j] = -1;
//				enemy[i][j] = -1;
			}
			else
			{
				ptr[i][j] = ft_toupper(line[j]) == symbol ? 0 : WALL;
//				enemy[i][j] = ft_toupper(line[j]) == symbol ? WALL : 0;
			}
		}
		free(line - (symbol == '*' ? 0 : 4));
	}
	return (0);
}

int		parse_token(int **ptr, int rows, int cols)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		if (get_next_line(STDIN_FILENO, &line) == -1)
			return (1);
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

t_map	*parse_input(t_bot *bot)
{
	char	*line;
	t_map	*token;

	if (get_next_line(STDIN_FILENO, &line) == -1)
		return (NULL);
	if (!bot->map && !(bot->map = init_map(line)))
		return (NULL);
	if (!bot->enemy && !(bot->enemy = init_map(line)))
		return (NULL);
//	free(line);
	if (get_next_line(STDIN_FILENO, &line) == -1)
		return (NULL);
//	free(line);
	if (parse_map(bot->map->map, bot->map->rows, bot->symbol, bot->enemy->map))
		return (NULL);
//	print_map(bot->map);
	if (get_next_line(STDIN_FILENO, &line) == -1)
		return (NULL);
	token = init_map(line);
	if (parse_token(token->map, token->rows, token->cols))
		return (NULL);
	//	free(line);
//	write_line(line);
//	print_map(token);
	return (token);
}