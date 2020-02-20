/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:38:31 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/16 18:24:50 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	get_size(t_board *board, char *line)
{
	while (*line != ' ')
		line++;
	board->row = ft_atoi(line++);
	while (*line != ' ')
		line++;
	board->col = ft_atoi(line);
}

void	get_board(t_vis *vis, t_board *board)
{
	const int		rows = board->row;
	const int		cols = board->col;
	register int	i;
	char			*line;

	i = 0;
	if (get_next_line(STDIN_FILENO, &line) != 1)
		free_vis(vis);
	free(line);
	if (!(board->tab = (char **)malloc(sizeof(char *) * rows)))
		free_vis(vis);
	while (i < rows)
	{
		if (!(board->tab[i] = (char *)malloc(sizeof(char) * cols)) ||
			get_next_line(STDIN_FILENO, &line) != 1)
			free_vis(vis);
		if (!(board->tab[i] = ft_strdup(line + 4)))
			free_vis(vis);
		free(line);
		i++;
	}
}

static void	push_board(t_vis *vis, t_board *board)
{
	t_board *prev;

	if (vis->board == NULL)
		vis->board = board;
	else
	{
		prev = vis->board;
		while (prev->next)
			prev = prev->next;
		prev->next = board;
		board->prev = prev;
	}
}

static void	parse_score(t_board *board)
{
	char			**ptr;
	const int		rows = board->row;
	const int		cols = board->col;
	register int	i;
	register int	j;

	i = 0;
	ptr = board->tab;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (ptr[i][j] == 'X' || ptr[i][j] == 'x')
				board->score2++;
			else if (ptr[i][j] == 'O' || ptr[i][j] == 'o')
				board->score1++;
			j++;
		}
		i++;
	}
	board->score1--;
	board->score2--;
}

void	parse_board(t_vis *vis)
{
	t_board	*board;
	char	*line;

	board = NULL;
	while (!board && get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
		{
			if (!(board = (t_board *)ft_memalloc(sizeof(t_board))))
				free_vis(vis);
			get_size(board, line);
			free(line);
			get_board(vis, board);
			parse_score(board);
			push_board(vis, board);
		}
		else
			free(line);
	}
}