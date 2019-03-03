/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 00:37:30 by jochang           #+#    #+#             */
/*   Updated: 2019/01/10 03:05:32 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_compressed *makeCompressed(struct s_stone *stone)
{
	struct s_compressed *cmp = malloc(sizeof(struct s_compressed));
	cmp->size = stone->size;
	cmp->head = stone;
	cmp->tail = stone;
	cmp->next = NULL;

	struct s_compressed *tmp = cmp;
	while (stone)
	{
		if (!stone->next)
			tmp->tail = stone;
		else if (stone->size != stone->next->size)
		{
			tmp->tail = stone;
			tmp->next = malloc(sizeof(struct s_compressed));
			tmp = tmp->next;
			tmp->size = stone->next->size;
			tmp->head = stone->next;
			tmp->tail = stone->next;
			tmp->next = NULL;
		}
		stone = stone->next;
	}
	return (cmp);
}

void swap(struct s_compressed *a, struct s_compressed *b)
{
	struct s_stone *ahead = a->head;
	struct s_stone *atail = a->tail;
	int asize = a->size;
	a->head = b->head;
	a->tail = b->tail;
	a->size = b->size;
	b->head = ahead;
	b->tail = atail;
	b->size = asize;
}

struct s_stone *linkCompressed(struct s_compressed *comp)
{
	struct s_stone *stone = comp->head;

	while (comp)
	{
		comp->tail->next = comp->next ? comp->next->head : NULL;
		comp = comp->next;
	}
	return (stone);
}

void freeCompressed(struct s_compressed *comp)
{
	struct s_compressed *tmp;
	while (comp)
	{
		tmp = comp->next;
		free(comp);
		comp = tmp;
	}
}

void sortStones(struct s_stone **stone)
{
	struct s_compressed *comp = makeCompressed(*stone);

	if (!comp)
		return;

	int swapped = 1;
	struct s_compressed *ptr = comp;
	struct s_compressed *tmp = NULL;
	while (swapped)
	{
		swapped = 0;
		ptr = comp;
		while (ptr->next != tmp)
		{
			if (ptr->size > ptr->next->size)
			{
				swap(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		tmp = ptr;
	}

	*stone = linkCompressed(comp);
	freeCompressed(comp);
}
