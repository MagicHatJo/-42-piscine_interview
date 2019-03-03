/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPricev2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 22:10:30 by jochang           #+#    #+#             */
/*   Updated: 2019/01/16 22:59:12 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

double	recurse(int size, double *prices, double *table) {
	double	tmp;

	if (!table[size])
	{
		table[size] = prices[size];
		for (int i = 1; i < size; i++)
		{
			tmp = recurse(i, prices, table) +
				recurse(size - i, prices, table);
			table[size] = tmp > table[size] ? tmp : table[size];
		}
	}
	return (table[size]);
}

double	optimizedBestPrice(int pizzaSize, double *prices) {
	double	*table = calloc(pizzaSize, sizeof(double));

	return (recurse(pizzaSize, prices, table));
}
