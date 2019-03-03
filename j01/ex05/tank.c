/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:37 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 19:18:01 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_tank *initTank(void)
{
	struct s_tank *tank = malloc(sizeof(struct s_tank));
	tank->stacks = NULL;
	tank->n = 0;
	return (tank);
}

void addStack(struct s_tank *tank)
{
	(tank->n)++;
	tank->stacks = realloc(tank->stacks, sizeof(struct s_stack*) * tank->n);
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->elem = NULL;
	stack->sum = 0;
	tank->stacks[tank->n - 1] = stack;
}

void removeStack(struct s_tank *tank)
{
	if (!tank)
		return;
	(tank->n)--;
	if (!tank->n)
		free(tank->stacks);
	else
		tank->stacks = realloc(tank->stacks, sizeof(struct s_stack*) * tank->n);
}

void tankPush(struct s_tank *tank, int energy)
{
	if (!tank->stacks || tank->stacks[tank->n - 1]->sum + energy > 1000)
		addStack(tank);
	struct s_elem *elem = malloc(sizeof(struct s_elem));
	elem->energy = energy;
	elem->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = elem;
	tank->stacks[tank->n - 1]->sum += energy;
}

int tankPop(struct s_tank *tank)
{
	struct s_elem *elem = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = tank->stacks[tank->n - 1]->elem->next;
	int energy = elem->energy;
	elem->next = NULL;
	tank->stacks[tank->n - 1]->sum -= energy;
	if (!tank->stacks[tank->n - 1]->sum)
		removeStack(tank);
	free(elem);
	return energy;
}

void printTanks(struct s_tank *tank)
{
	printf("normal ");
	for (int i = 1; i < tank->n; i++)
		printf(" nitro%d ", i);
	printf("\n");
	for (int i = 0; i < tank->n; i++)
		printf("______  ");
	printf("\n");
	for (int i = 0; i < tank->n; i++)
		printf("|%-4d|  ", tank->stacks[i]->sum);
	printf("\n");
	for (int i = 0; i < tank->n; i++)
		printf("|    |  ");
	printf("\n");
}
