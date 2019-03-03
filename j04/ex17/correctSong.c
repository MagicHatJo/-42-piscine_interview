/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:48:15 by jochang           #+#    #+#             */
/*   Updated: 2019/01/15 21:57:47 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int i = 0;
	while (i < row)
		i++;
	int val = 1 << col;
	for (int k = 0; k + i < l && k < dist; k++)
		bit[0].arr[i + k] = val;
}
