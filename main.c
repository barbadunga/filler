/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:05:22 by mshagga           #+#    #+#             */
/*   Updated: 2020/01/29 22:47:55 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <SDL.h>
t_bot	*init_bot()
{
	t_bot	*bot;
	char	*line;
	int		i;

	if (!(bot = (t_bot*)malloc(sizeof(t_bot))))
		return (NULL);
	get_next_line(0, &line);
	i = 0;
	while (line[i] && line[i] != 'p')
		i++;
	bot->num = line[++i] == '1' ? '1' : '2';
	ft_putstr_fd(line, 2);
	return (bot);
}

int main(void)
{
	char	*line;
	t_bot	*bot;


	if (!(bot = init_bot()))
		return (0);
	return (0);
}