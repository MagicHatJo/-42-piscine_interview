/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 02:12:10 by jochang           #+#    #+#             */
/*   Updated: 2019/01/11 03:16:02 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "header.h"

int find(struct s_node *root, struct s_node **found, char *first, char *second)
{
	if (!root)
		return (0);
	int count = 0;
	if (!strcmp(root->name, first) || !strcmp(root->name, second))
		count++;

	for (int i = 0; root->children[i]; i++)
		count += find(root->children[i], found, first, second);
	if (count == 2 && !(*found))
		*found = root;
	return (count);
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *found = NULL;

	find(root, &found, firstSpecies, secondSpecies);
	return (found);
}
