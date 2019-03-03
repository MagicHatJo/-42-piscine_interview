/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:24:02 by jochang           #+#    #+#             */
/*   Updated: 2019/01/15 17:28:07 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "header.h"

int isPowerOfTwo(unsigned int n)
{
	return ( n && (!(n & (n - 1))));
}

int carPosition(unsigned int parkingRow)
{
	return (isPowerOfTwo(parkingRow) ? log2(parkingRow) : -1);
}
