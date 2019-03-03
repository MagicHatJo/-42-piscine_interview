/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:50:36 by jochang           #+#    #+#             */
/*   Updated: 2019/01/15 21:21:44 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int **pianoDecompress(struct s_bit *bit, int l)
{
	int **block = malloc(sizeof(int*) * bit->n);
	int tmp;
	for (int i = 0; i < bit->n; i++)
	{
		block[i] = malloc(sizeof(int) * l);
		tmp = bit[0].arr[i];
		for (int j = 0; j < l; j++)
		{
			block[i][j] = (tmp & 1) ? 1 : 0;
			tmp >>= 1;
		}
	}
	return (block);
}
