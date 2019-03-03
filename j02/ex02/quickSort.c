/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 03:29:18 by jochang           #+#    #+#             */
/*   Updated: 2019/01/10 03:52:15 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int getLen(struct s_player **players)
{
	int i = 0;
	while (players[i])
		i++;
	return i;
}

void swap(struct s_player *a, struct s_player *b)
{
	int score = a->score;
	char *name = a->name;
	a->score = b->score;
	a->name = b->name;
	b->score = score;
	b->name = name;
}

int partition(struct s_player **players, int low, int high)
{
	struct s_player *pivot = players[(high - low) / 2];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (players[j]->score >= pivot->score)
		{
			i++;
			swap(players[i], players[j]);
		}
	}
	swap(players[i + 1], players[high]);
	return (i + 1);
}

void qs(struct s_player **players, int low, int high)
{
	if (low < high)
	{
		int pi = partition(players, low, high);
		qs(players, low, pi - 1);
		qs(players, pi + 1, high);
	}
}

void quickSort(struct s_player **players)
{
	int low = 0;
	int high = getLen(players) - 1;
	qs(players, low, high);
}
