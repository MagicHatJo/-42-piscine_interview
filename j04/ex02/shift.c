/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:58:00 by jochang           #+#    #+#             */
/*   Updated: 2019/01/14 23:55:14 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "header.h"

char *leftShift(char *bin, int k)
{
	char *result = malloc(7);
	memset(result, '0', 6);
	result[6] = '\0';

	for (int i = 5; i - k >= 0; i--)
		result[i - k] = bin[i];

	return (result);
}

char *rightShift(char *bin, int k)
{
	char *result = malloc(7);
	memset(result, '1', 6);
	result[6] = '\0';

	for (int i = 5; i >= k; i--)
		result[i] = bin[i - k];
	return (result);
}

int toInt(char *bits)
{
	int sign = (bits[0] == '0' ? 1 : -1);
	int offset = (bits[0] == '0' ? 0 : 1);
	char *tmp = strdup(bits);
	if (bits[0] == '1')
		for (int i = 1; i < 6; i++)
			tmp[i] = (bits[i] == '1' ? '0' : '1');

	return (((tmp[5] - '0') +
			((tmp[4] - '0') << 1) +
			((tmp[3] - '0') << 2) +
			((tmp[2] - '0') << 3) +
			((tmp[1] - '0') << 4)) * sign - offset);
}
