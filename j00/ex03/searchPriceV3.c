/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 00:13:54 by jochang           #+#    #+#             */
/*   Updated: 2019/01/08 17:05:10 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

size_t			hash(char *input)
{
	return(input ? ((unsigned char)input[0] % 126) - 32 : 0);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*dict = malloc(sizeof(struct s_dict));
	if (!dict)
		return (NULL);
	if (capacity <= 0)
		return (dict);
	dict->items = malloc(sizeof(struct s_item *) * capacity);
	if (!dict->items)
	{
		free(dict);
		return (NULL);
	}
	for (int i = 0; i < capacity; i++)
		dict->items[i] = NULL;
	dict->capacity = capacity;
	return (dict);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item	*new = malloc(sizeof(struct s_item));
	if (!new)
		return (0);
	new->key = key;
	new->value = value;
	new->next = NULL;
	size_t		h = hash(key);
	if (dict->items[h] == NULL)
		dict->items[h] = new;
	else
	{
		struct s_item	*ptr = dict->items[h];
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	size_t		h = hash(key);
	struct s_item	*ptr = dict->items[h];

	while (ptr)
	{
		if (!strcmp(ptr->key, key))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*found;

	if ((found = dictSearch(dict, name)))
		return (found->price);
	return (-1);
}
