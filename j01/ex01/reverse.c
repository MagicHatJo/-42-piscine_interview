/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 00:02:12 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 00:13:44 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	printReverse(struct s_node *lst)
{
	if (!lst)
		return;
	printReverse(lst->next);
	printf(lst->next ? " %s" : "%s", lst->word);
}
