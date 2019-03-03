/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:00:16 by jochang           #+#    #+#             */
/*   Updated: 2019/01/09 00:00:30 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

struct s_node	*makeNode(char c)
{
	struct s_node	*new = malloc(sizeof(struct s_node));
	new->c = c;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

struct s_node	*makeWheel(void)
{
	char	*list = CS;
	int		len = strlen(CS);

	struct s_node	*head = makeNode(list[0]);
	struct s_node	*tmp = head;
	struct s_node	*tail = NULL;
	for (int i = 1; i < len;i++)
	{
		tmp->next = makeNode(list[i]);
		tail = tmp;
		tmp = tmp->next;
		tmp->prev = tail;
	}
	tmp->next = head;
	head->prev = tmp;
	return (head);
}

void	spinWheel(struct s_node **wheel, int times)
{
	if (times > 0)
		while (times--)
			*wheel = (*wheel)->next;
	else if (times < 0)
		while (times++)
			*wheel = (*wheel)->prev;
}

void	freeWheel(struct s_node *wheel)
{
	struct s_node	*tmp;

	wheel->prev->next = NULL;
	while (wheel)
	{
		tmp = wheel;
		wheel = wheel->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
	}
}

char	*precious(int *text, int size)
{
	struct s_node *wheel;

	setbuf(stdout, NULL);
	wheel = makeWheel();
	char *msg = malloc(size + 1);
	for (int i = 0; i < size; i++)
	{
		spinWheel(&wheel, text[i]);
		msg[i] = wheel->c;
	}
	freeWheel(wheel);
	return (msg);
}
