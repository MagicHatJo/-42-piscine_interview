/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 22:46:50 by jochang           #+#    #+#             */
/*   Updated: 2019/01/14 22:57:50 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

char *getXor(char *a, char *b)
{
	char *result = malloc(7);
	result[6] = '\0';

	for (int i = 0; i < 6; i++)
		result[i] = a[i] ^ b[i] ? '1' : '0';
	return (result);
}

int toInt(char *bits)
{
	return ((bits[5] - '0') +
			((bits[4] - '0') << 1) +
			((bits[3] - '0') << 2) +
			((bits[2] - '0') << 3) +
			((bits[1] - '0') << 4) +
			((bits[0] - '0') << 5));
}
