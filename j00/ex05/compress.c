/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:08:32 by jochang           #+#    #+#             */
/*   Updated: 2019/01/08 22:55:16 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

size_t	hash(char *input)
{
	return ((unsigned char)input[0] % 255);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*dict = malloc(sizeof(struct s_dict));
	if (!dict)
		return (NULL);
	if (capacity <= 0)
		return (dict);
	dict->items = malloc(sizeof(struct s_item*) * capacity);
	if (!dict->items)
	{
		free(dict);
		return (NULL);
	}
	for (int i = 0;i < capacity;i++)
		dict->items[i] = NULL;
	dict->capacity = capacity;
	return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, int value)
{
	struct s_item	*new = malloc(sizeof(struct s_item));
	if (!new)
		return (0);
	new->key = key;
	new->value = value;
	new->next = NULL;
	size_t	h = hash(key) - 1;
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

int	dictSearch(struct s_dict *dict, char *key)
{
	size_t	h = hash(key) - 1;
	struct s_item	*ptr = dict->items[h];

	for (int i = 0; ptr[i] != NULL; i++)
		if (!strcmp(ptr->key, key))
			return (i);
	return (-1);
}

char	*makeHeader(struct s_dict *dict)
{
	char	*header = malloc(2);
	char	*tmp;
	header[0] = '<';
	header[1] = '\0';
	for (int i = 0; dict->items[i];i++)
	{
		tmp = malloc(strlen(header) + 3 + strlen(dict->items[i]->key));
		strcpy(tmp, header);
		strcat(tmp, dict->items[i]->key);
		strcat(tmp, ',');
		free(header);
		header = tmp;
	}
	header[strlen(header) - 1] = '>';
	printf("%s\n", header);
	return (header);
}

//take dict, make header
//take book, split by whitespace
//go through the split, replace 1 - 1 if found in dict
//move evertything back to 1 string
//return new string
char	*compress(char *book, struct s_dict *dict)
{
	//make header from dict
	char	*header = makeHeader(dict);
}
