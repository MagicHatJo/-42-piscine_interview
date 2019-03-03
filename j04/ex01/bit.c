/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:46:39 by jochang           #+#    #+#             */
/*   Updated: 2019/01/14 21:46:33 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

char *checkNot(char *a)
{
	if (a[0] != '~')
		return (a);
	char *result = malloc(5);
	result[4] = '\0';
	for (int i = 0; i < 4; i++)
		result[i] = a[i + 1] == '1' ? '0' : '1';
	return (result);
}

char *getAnd(char *a, char *b)
{
	char *result = malloc(5);
	result[4] = '\0';
	a = checkNot(a);
	b = checkNot(b);

	for (int i = 0; i < 4; i++)
		result[i] = (a[i] == '1' && b[i] == '1') ? '1' : '0';
	return (result);
}

char *getOr(char *a, char *b)
{
	char *result = malloc(5);
	result[4] = '\0';
	a = checkNot(a);
	b = checkNot(b);

	for (int i = 0; i < 4; i++)
		result[i] = (a[i] == '1' || b[i] == '1') ? '1' : '0';
	return (result);
}

int toInt(char *bits)
{
	return ((bits[3] - '0') +
			(bits[2] - '0') * 2 +
			(bits[1] - '0') * 4 +
			(bits[0] - '0') * 8);
}
