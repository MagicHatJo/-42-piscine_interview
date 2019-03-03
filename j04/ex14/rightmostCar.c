/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:41:15 by jochang           #+#    #+#             */
/*   Updated: 2019/01/15 17:51:18 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	int count = -1;
	while (parkingRow)
	{
		count++;
		if (parkingRow & 1)
			return (count);
		parkingRow >>= 1;
	}
	return (count);
}
