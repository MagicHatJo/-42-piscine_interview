/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 03:09:29 by jochang           #+#    #+#             */
/*   Updated: 2019/01/10 03:26:24 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void insertionSort(struct s_player **players)
{
	int j;
	struct s_player *player;
	for (int i = 1; players[i];i++)
	{
		j = i - 1;
		player = players[i];
		while (j >= 0 && players[j]->score < player->score)
		{
			players[j + 1] = players[j];
			j--;
		}
		players[j + 1] = player;
	}
}
