/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 01:21:47 by jochang           #+#    #+#             */
/*   Updated: 2019/01/11 02:02:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

struct s_node *newNode(int value)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
/*
struct s_node *createBST(int *arr, int n)
{
	if (n <= 0)
		return (NULL);

	int mid = n / 2;
	struct s_node *node = newNode(arr[mid]);
	node->left = createBST(arr, mid - 1);
	node->right = createBST(&arr[mid + 1], mid);
	return (node);
}
*/

struct s_node *cbst(int *arr, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;
	struct s_node *node = newNode(arr[mid]);
	node->left = cbst(arr, start, mid - 1);
	node->right = cbst(arr, mid + 1, end);
	return (node);
}

struct s_node *createBST(int *arr, int n)
{
	return (cbst(arr, 0, --n));
}
