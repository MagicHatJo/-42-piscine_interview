/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:48:09 by jochang           #+#    #+#             */
/*   Updated: 2019/01/11 01:18:10 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "header.h"

#define MAX(x, y) (x > y ? x : y)

struct s_info initInfo(void)
{
	struct s_info info;

	info.min = INT_MAX;
	info.max = INT_MIN;
	info.elements = 0;
	info.height = 0;
	info.isBST = 0;
	info.isBalanced = 0;
	return (info);
}

void findBasic(struct s_info *info, struct s_node *root)
{
	if (!root)
		return ;
	findBasic(info, root->left);
	findBasic(info, root->right);
	if (info->max < root->value)
		info->max = root->value;
	if (info->min > root->value)
		info->min = root->value;
	info->elements++;
}

int getHeight(struct s_node *root)
{
	if (!root)
		return (0);

	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return (MAX(left, right) + 1);
}

int isBST(struct s_node *root, int min, int max)
{
	if (!root)
		return (1);
	if (root->value < min || root->value > max)
		return (0);
	return (isBST(root->left, min, root->value - 1) &&
			isBST(root->right, root->value + 1, max));
}

int isBalanced(struct s_node *root)
{
	if (!root)
		return (1);
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return (abs(left - right) < 2 && isBalanced(root->left) && isBalanced(root->right));
}

struct s_info getInfo(struct s_node *root)
{
	struct s_info info;

	info = initInfo();
	findBasic(&info, root);
	info.height = getHeight(root);
	info.isBST = isBST(root, INT_MIN, INT_MAX);
	info.isBalanced = isBalanced(root);
	return (info);
}
