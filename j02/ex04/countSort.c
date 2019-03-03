/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:08:10 by jochang           #+#    #+#             */
/*   Updated: 2019/01/10 16:48:59 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

#define RANGE 15

void countSort(unsigned char *utensils, int n)
{
	unsigned char count[RANGE + 1] = {0};

	for (int i = 0; i < n; i++)
		count[utensils[i]]++;
	
	int k = 0;
	for (int i = 0; i <= RANGE; i++)
		for (int j = 1; j <= count[i]; j++)
			utensils[k++] = i;
}
