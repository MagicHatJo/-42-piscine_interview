/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:24:04 by jochang           #+#    #+#             */
/*   Updated: 2019/01/17 23:46:56 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "header.h"

#define PIECE(x) masterpiece[x]->name

void swap(struct s_art *a, struct s_art *b)
{
	char *tn = a->name;
	int tp = a->price;
	a->name = b->name;
	a->price = b->price;
	b->name = tn;
	b->price = tp;
}

void buildMaxHeap(struct s_art **masterpiece, int n)
{
	int j;

	for (int i = 1; i < n; i++)
	{
		if (strcmp(PIECE(i), PIECE((i - 1) / 2)) > 0)
		{
			j = i;
			while (strcmp(PIECE(j), PIECE((j - 1) / 2)) > 0)
			{
				swap(masterpiece[j], masterpiece[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
		}
	}
}

void heapSort(struct s_art **masterpiece, int n)
{
	int j;
	int index;

	buildMaxHeap(masterpiece, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(masterpiece[0], masterpiece[i]);
		j = 0;
		do
		{
			index = 2 * j + 1;
			if (strcmp(PIECE(index), PIECE(index + 1)) < 0 && index < i - 1)
				index++;
			if (strcmp(PIECE(j), PIECE(index)) < 0 && index < i)
				swap(masterpiece[j], masterpiece[index]);
			j = index;
		} while (index < i);
	}
}

/* Recursive
void heapify(struct s_art **arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && strcmp(arr[left]->name, arr[largest]->name) > 0)
		largest = left;
	if (right < n && strcmp(arr[right]->name, arr[largest]->name) > 0)
		largest = right;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(struct s_art **masterpiece, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(masterpiece[0], masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}
*/
