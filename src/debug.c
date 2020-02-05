/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:18:17 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/05 21:30:28 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	bot_info(t_bot *bot)
{
	FILE	*file;

	file = fopen(DEBUG_FILE, "a");
	fprintf(file, "/* ************** *\\\nBot info:\nPlayer %d\t%c\n", (bot->symbol == 'X') + 1, bot->symbol);
	if (bot->map)
		fprintf(file, "rows: %d\tcols: %d\n", bot->map->rows, bot->map->cols);
	fprintf(file, "\\* ************** */\n");
	fclose(file);
}

void	print_map(t_map *ptr)
{
	FILE	*fd;
	int		i;
	int		j;

	fd = fopen(DEBUG_FILE, "a");
	i = 0;
	fprintf(fd, "\t");
	for (int k = 0; k < ptr->cols; k++)
		fprintf(fd, "%4d", k);
	fprintf(fd, "\n");
	while (i < ptr->rows)
	{
		j = 0;
		fprintf(fd, "%d\t", i);
		while (j < ptr->cols)
		{
			fprintf(fd, "%4d", ptr->map[i][j]);
			j++;
		}
		i++;
		fprintf(fd, "\n");
	}
	fclose(fd);
}

void	write_array(int **array, int rows, int cols)
{
	FILE	*fd;

	fd = fopen(DEBUG_FILE, "a");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			fprintf(fd, "%4d", array[i][j]);
		fprintf(fd, "\n");
	}
	fprintf(fd, "\n");
	fclose(fd);
}

void	write_line(char	*line)
{
	FILE	*fd;

	fd = fopen(DEBUG_FILE, "a");
	fprintf(fd, "%s\n", line);
	fclose(fd);
}

void	debug_init()
{
	FILE	*fd;

	fd = fopen(DEBUG_FILE,"w+");
	fclose(fd);
}

void	write_number(int n1, int n2)
{
	FILE	*fd;
	char	*line = ft_itoa(n1);

	fd = fopen(DEBUG_FILE, "a");
	fprintf(fd, "%s\t", line);
	free(line);
	line = ft_itoa(n2);
	fprintf(fd, "%s\n", line);
	free(line);
	fclose(fd);

}

void	write_vec(t_vec *pos)
{
	FILE		*fd;
	uint64_t	*ptr;

	ptr = pos->data;
	fd = fopen(DEBUG_FILE, "a");
	for (int i = 0; i < pos->total; i++)
		fprintf(fd, " (%d, %d) ", (int)(ptr[i] >> 32u), (int)(ptr[i] & MASK));
	fprintf(fd, "\n");
	fclose(fd);
}

