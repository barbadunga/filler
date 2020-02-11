/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:56:43 by mshagga           #+#    #+#             */
/*   Updated: 2020/02/10 16:57:16 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void	enqueue(t_queue *q, t_point2d point)
{
	if (q->tail >= MAX_CELLS)
		return ;
	q->data[q->tail++] = point;
}

t_point2d	dequeue(t_queue *q)
{
	return (q->data[q->head++]);
}

void	reset_queue(t_queue *q)
{
	q->head = 0;
	q->tail = 0;
}
