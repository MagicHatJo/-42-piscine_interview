/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 03:56:03 by jochang           #+#    #+#             */
/*   Updated: 2019/01/10 16:05:24 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int getLen(struct s_player **players)
{
	int i = 0;
	while (players[i])
		i++;
	return i;
}

void merge(struct s_player **players, struct s_player **left, struct s_player **right)
{
	while (*left && *right)
	{
		if ((*left)->score >= (*right)->score)
			*players++ = *left++;
		else
			*players++ = *right++;
	}
	while (*left)
		*players++ = *left++;
	while (*right)
		*players++ = *right++;
}

struct s_player **mergeSort(struct s_player **players)
{
	int len = getLen(players);
	if (len > 1)
	{
		int mid = len / 2;
		struct s_player *left[mid + 1];
		struct s_player *right[len - mid + 1];
		int i;
		for (i = 0; i < mid; i++)
			left[i] = players[i];
		left[i] = NULL;
		for (i = 0; i + mid < len; i++)
			right[i] = players[i + mid];
		right[i] = NULL;
		mergeSort(left);
		mergeSort(right);
		merge(players, left, right);
	}
	return (players);
}
