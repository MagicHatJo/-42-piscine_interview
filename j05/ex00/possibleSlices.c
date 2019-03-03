/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 23:18:02 by jochang           #+#    #+#             */
/*   Updated: 2019/01/16 16:42:29 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	recurse(struct s_array *arr, int size) {
	struct s_array	*tmp;

	if (!size)
		arrayPrint(arr);
	for (int i = size; i > 0; i--)
	{
		tmp = arrayClone(arr);
		arrayAppend(tmp, i);
		recurse(tmp, size - i);
	}
}

void	printPossibleSlices(int pizzaSize) {
	struct s_array	*arr = arrayInit();

	recurse(arr, pizzaSize);
}
