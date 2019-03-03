/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:31:24 by jochang           #+#    #+#             */
/*   Updated: 2019/01/14 17:55:24 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "header.h"

char *getSum(char *a, char *b)
{
	char *result = malloc(7);
	result[6] = '\0';
	int s = 0;
	for (int i = 5; i >= 0; i--)
	{
		s += a[i] - '0' + b[i] - '0';
		result[i] = s % 2 + '0';
		s /= 2;
	}
	return (result);
}

int toInt(char *bits)
{
	return ((bits[5] - '0') +
			((bits[4] - '0') * 2) +
			((bits[3] - '0') * 4) +
			((bits[2] - '0') * 8) +
			((bits[1] - '0') * 16) +
			((bits[0] - '0') * 32));
}
