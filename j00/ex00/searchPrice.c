/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:36:46 by jochang           #+#    #+#             */
/*   Updated: 2019/01/07 17:32:21 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int		searchPrice(struct s_art **arts, char *name)
{
	int		i = 0;

	while (*arts && arts[i])
	{
		if (!strcmp(arts[i]->name, name))
			return (arts[i]->price);
		i++;
	}
	return (-1);
}
