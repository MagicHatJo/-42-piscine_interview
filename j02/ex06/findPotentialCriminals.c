/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:44:11 by jochang           #+#    #+#             */
/*   Updated: 2019/01/10 23:40:09 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "header.h"

int getLen(struct s_criminal **criminals)
{
	int i = 0;
	while (criminals[i])
		i++;
	return (i);
}

void countSort(struct s_criminal **criminals, int n, int exp)
{
	int count[10] = {0};

	for (int i = 0; i < n; i++)
		count[(criminals[i]->description/exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	struct s_criminal *output[n + 1];
	output[n] = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(criminals[i]->description/exp) % 10] - 1] = criminals[i];
		count[(criminals[i]->description/exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		criminals[i] = output[i];
}

int getDescription(struct s_info *info)
{
	int id = 0;
	id = info->piercing;
	printf("id = %d\n", id);
	id += info->tattoo * 10;
	printf("id = %d\n", id);
	id += info->glasses * 100;
	printf("id = %d\n", id);
	id += info->eyeColor * 1000;
	printf("id = %d\n", id);
	id += info->hairColor * 10000;
	printf("id = %d\n", id);
	id += info->height * 100000;
	printf("id = %d\n", id);
	id += info->gender * 1000000;
	printf("id = %d\n", id);
	return (id);
}

void sortCriminals(struct s_criminal **criminals)
{
	int n = getLen(criminals);

	for (int i = 1; 1000000 / i > 0; i *= 10)
		countSort(criminals, n, i);
}

int binarySearch(struct s_criminal **criminals, int n, int value)
{
	int low = 0;
	int high = n - 1;
	int mid;
	
	while (low < high)
	{
		mid = floor((low + high) / 2);
		printf("description: %7d %d\n", criminals[mid]->description, value);
		if (criminals[mid]->description > value)
			low = mid + 1;
		else if (criminals[mid]->description < value)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

int chunkHead(struct s_criminal **criminals, int index)
{
	printf("index: %d\n", index);
	for (int i = index; i > 0; i--)
		if (criminals[i - 1]->description != criminals[index]->description)
			return (i);
	return (0);
}

int potentialCount(struct s_criminal **criminals, int index)
{
	int n = 1;
	while (criminals[index + n])
	{
		if (criminals[index]->description != criminals[index + n]->description)
			break;
		n++;
	}
	return (n);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int toFind = getDescription(info);
	printf("to find: %d\n", toFind);
	int index = binarySearch(criminals, getLen(criminals), toFind);
	printf("after binary index: %d\n", index);
	if (index == -1)
		return (NULL);
	printf("after null\n");
	index = chunkHead(criminals, index);
	int num = potentialCount(criminals, index);
	struct s_criminal **found = malloc(sizeof(struct s_criminals*) * (num + 1));
	found[num] = NULL;
	for (int i = 0; i < num; i++)
		found[i] = criminals[index + i];
	return found;
}
