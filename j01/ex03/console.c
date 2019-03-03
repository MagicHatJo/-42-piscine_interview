/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 02:59:54 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 04:08:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_stack *initStack(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *item = malloc(sizeof(struct s_item));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

int pop(struct s_stack *stack)
{
	if (!stack->item)
		return (0);
	struct s_item *head = stack->item;
	stack->item = stack->item->next;
	head->next = NULL;
	int idx = head->idx;
	free(head);
	return (idx);
}

char *console(void)
{
	char output[255];
	size_t len;
	char *cmd;

	struct s_stack *stack = initStack();
	while (1)
	{
		printf("?: ");
		if (getline(&cmd, &len, stdin) < 0)
			break;
		*(strchr(cmd, '\n')) = '\0';
		if (!(strcmp(cmd, "SEND")))
			break;
		if (!(strcmp(cmd, "UNDO")))
			output[pop(stack)] = '\0';
		else
		{
			push(stack, strlen(output));
			strcat(output, cmd);
		}
		printf("%s\n", output);
	}
	free(stack);
	return (strdup(output));
}
