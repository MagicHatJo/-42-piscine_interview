/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:31:49 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 19:55:35 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *NthLastCity(struct s_city *city, int n)
{
	struct s_city *node = city;
	struct s_city *ptr = city;

	for (int i = 0; i < n;i++)
	{
		ptr = ptr->next;
		if (!ptr->next)
			return (city->name);
	}
	while (ptr->next)
	{
		ptr = ptr->next;
		node = node->next;
	}
	return (node->name);
}
