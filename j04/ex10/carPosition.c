/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:09:56 by jochang           #+#    #+#             */
/*   Updated: 2019/01/15 17:21:43 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isPowerOfTwo(unsigned int n)
{
	return (n && (!(n & (n - 1))));
}

int carPosition(unsigned int parkingRow)
{
	if (!isPowerOfTwo(parkingRow))
		return (-1);
	int count;
	for (count = -1; parkingRow; count++)
   		parkingRow >>= 1;
	return count;
}
