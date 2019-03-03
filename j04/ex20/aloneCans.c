/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:10:50 by jochang           #+#    #+#             */
/*   Updated: 2019/01/15 22:24:51 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void aloneCans(int *arr, int n)
{
	int num = arr[0];
	int x = 0;
	int y = 0;
	
	for (int i = 1; i < n; i++)
		num ^= arr[i];
	int split = num & ~(num - 1);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] & split)
			x ^= arr[i];
		else
			y ^= arr[i];
	}
	printf("%d\n%d\n", y, x);
}
