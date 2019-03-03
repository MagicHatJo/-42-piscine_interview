/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:14:45 by jochang           #+#    #+#             */
/*   Updated: 2019/01/08 18:53:37 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "header.h"

#define PRIME 101
#define NUM_CHARS 256

int howManyJesus(char *bible, char *jesus)
{
	int		blen = strlen(bible);
	int		jlen = strlen(jesus);
	int		bhash = 0;
	int		jhash = 0;
	int		i, j;
	int		count = 0;

	int		h = 1;
	for(i = 0; i < jlen - 1; i++)
		h = (h * NUM_CHARS) % PRIME;

	for (i = 0; i < jlen; i++)
	{
		jhash = (NUM_CHARS * jhash + jesus[i]) % PRIME;
		bhash = (NUM_CHARS * bhash + bible[i]) % PRIME;
	}

	for (i = 0; i <= blen - jlen;i++)
	{
		if (jhash == bhash)
		{
			for (j = 0; j < jlen;j++)
				if (bible[i + j] != jesus[j])
					break;
			if (j == jlen)
				count++;
		}
		if (i < blen - jlen)
		{
			bhash = (NUM_CHARS * (bhash - bible[i] * h) + bible[i + jlen]) % PRIME;
			if (bhash < 0)
				bhash += PRIME;
		}
	}
	return (count);
}
