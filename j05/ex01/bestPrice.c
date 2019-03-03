/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:19:52 by jochang           #+#    #+#             */
/*   Updated: 2019/01/16 21:20:31 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	recurse(int size, double *prices, double *max, double cur) {
	if (size <= 0)
		if (cur > *max)
			*max = cur;
	for (int i = 1; i <= size;i++)
		recurse(size - i, prices, max, cur + prices[i]);
}

double	bestPrice(int pizzaSize, double *prices) {
	double	max = 0.0;

	for (int i = 0; i < pizzaSize; i++) {
		recurse(pizzaSize, prices, &max, 0);
	}
	return (max);
}
