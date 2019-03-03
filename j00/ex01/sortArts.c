/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 23:09:51 by jochang           #+#    #+#             */
/*   Updated: 2019/01/07 23:25:34 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

static int	artlen(struct s_art **arts)
{
	int	i = 0;

	while (arts[i])
		i++;
	return (i);
}

static int comp(const void *a, const void *b)
{
	struct s_art *x = *(struct s_art **)a;
	struct s_art *y = *(struct s_art **)b;

	return (strcmp(x->name, y->name));
}

void		sortArts(struct s_art **arts)
{
	qsort(arts, artlen(arts), sizeof(struct s_art*), &comp);
}
