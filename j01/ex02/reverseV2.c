/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 02:29:59 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 02:44:53 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	if (!stack->item)
		return (NULL);
	struct s_item *head = stack->item;
	stack->item = stack->item->next;
	head->next = NULL;
	return (head);
}

void	push(struct s_stack *stack, char *word)
{
	struct s_item *item = malloc(sizeof(struct s_item));
	item->word = strdup(word);
	item->next = stack->item;
	stack->item = item;
}

void	printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	struct s_item *item;
	while ((item = pop(stack)))
	{
		printf("%s", item->word);
		if (stack->item)
			printf(" ");
		free(item);
	}
	free(stack);
	printf("\n");
}
