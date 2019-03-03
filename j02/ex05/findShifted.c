/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:51:23 by jochang           #+#    #+#             */
/*   Updated: 2019/01/10 19:39:57 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "header.h"

int findPivot(int *rocks, int length)
{
	for (int i = 1; i < length; i++)
		if (rocks[i] < rocks[i - 1])
			return (i);
	return (-1);
}

int binarySearch(int *rocks, int low, int high, int value)
{
	int mid;
	while (low <= high)
	{
		mid = floor((low + high) / 2);
		if (rocks[mid] < value)
			low = mid + 1;
		else if (rocks[mid] > value)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

int chunkHead(int *rocks, int index)
{
	for (int i = index; i > 0; i--)
		if (rocks[i - 1] != rocks[index])
			return (i);
	return (-1);
}

int searchShifted(int *rocks, int length, int value)
{
	if (rocks[0] == value)
		return (0);
	int pivot = findPivot(rocks, length);
	int init;
	if (pivot == -1)
		init = binarySearch(rocks, 0, length - 1, value);
	else if (rocks[pivot] == value)
		init = pivot;
	else if (rocks[0] < value)
		init = binarySearch(rocks, 0, pivot - 1, value);
	else
		init = binarySearch(rocks, pivot + 1, length - 1, value);
	if (init >= 0)
	{
		init = chunkHead(rocks, init);
		return (init);
	}
	return (-1);
}
