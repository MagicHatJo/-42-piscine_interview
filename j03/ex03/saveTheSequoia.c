/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:21:42 by jochang           #+#    #+#             */
/*   Updated: 2019/01/11 23:49:30 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int bubbleHeap(struct s_node **root)
{
	if (!root)
		return 0;

}

void saveTheSequoia(struct s_node **root)
{
	if (!root)
		return;
	//recur to null

	//if children exists and children are larger
		//swap larger child with parent
	//
	int swapped = 1;
	while (swapped)
		swapped = bubbleHeap(root);
}
