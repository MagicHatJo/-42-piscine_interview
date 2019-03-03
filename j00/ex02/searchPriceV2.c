/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 23:31:41 by jochang           #+#    #+#             */
/*   Updated: 2019/01/07 23:46:14 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "header.h"

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int	low = 0;
	int	high = n - 1;

	int	mid;
	while (low <= high)
	{
		mid = floor((low + high) / 2);
		if (strcmp(arts[mid]->name, name) < 0)
			low = mid + 1;
		else if (strcmp(arts[mid]->name, name) > 0)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}
