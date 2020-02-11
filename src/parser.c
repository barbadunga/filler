/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:47:56 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/11 21:23:15 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int		parse_map(int **ptr, int rows, char symbol)
{
	char		*line;
	int			i;
	int 		j;

	i = -1;
	while (++i < rows)
	{
		if (get_next_line(STDIN_FILENO, &line) == -1)
			return (1);
		line += 4;
		j = -1;
		while (line[++j])
			ptr[i][j] = ft_toupper(line[j]) << 24u;
		free(line - 4);
	}
	return (0);
}

int		parse_token(int **ptr, int rows)
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
//	free(line);
	if (get_next_line(STDIN_FILENO, &line) == -1)
		return (NULL);
//	free(line);
	if (parse_map(bot->map->map, bot->map->rows, bot->symbol))
		return (NULL);
	write_line("Input");
	if (get_next_line(STDIN_FILENO, &line) == -1)
		return (NULL);
	token = init_map(line);
	if (parse_token(token->map, token->rows))
		return (NULL);
//	free(line);
	return (token);
}