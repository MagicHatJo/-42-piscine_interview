/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:11:22 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 21:13:23 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *cur = node;
	struct s_node *tmp;

	while (cur)
	{
		tmp = cur->next;
		cur->next = malloc(sizeof(struct s_node));
		cur->next->value = cur->value;
		cur->next->next = tmp;
		cur = tmp;
	}

	cur = node;
	while (cur)
	{
		if (cur->next)
			cur->next->random = cur->random ? cur->random->next : cur->random;
		cur = cur->next ? cur->next->next : cur->next;
	}	

	struct s_node *original = node;
	struct s_node *clone = node->next;
	tmp = clone;
	while (original && tmp)
	{
		original->next = original->next ? original->next->next : original->next;
		original = original->next;
		tmp->next = tmp->next ? tmp->next->next : tmp->next;
		tmp = tmp->next;
	}
	return (clone);
}
