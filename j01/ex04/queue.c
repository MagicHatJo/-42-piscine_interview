/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:06:16 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 15:02:13 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

char *dequeue(struct s_queue *queue)
{
	if (!queue->first)
		return NULL;
	char *message = queue->first->message;
	struct s_node *node = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	free(node);
	return message;
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->message = strdup(message);
	node->next = NULL;
	if (!queue->first)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = queue->last->next;
	}
}

char *peek(struct s_queue *queue)
{
	return (queue && queue->first ? queue->first->message : NULL);
}

int isEmpty(struct s_queue *queue)
{
	return (queue->first ? 0 : 1);
}
