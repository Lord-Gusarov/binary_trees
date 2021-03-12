#include "binary_trees.h"
/* BST -> BINARY SEARCH TREE */

/**
 * bst_insert - inserts a value in a BINARY SEARCH Tree
 * @tree: double pointer to root of BST
 * @value: data for the new node
 *
 * Return: pointer to created node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *trv, *new, *last = NULL;

	if (!tree)
		return (NULL);

	new = malloc(sizeof(bst_t));
	if (!new)
		return (NULL);
	new->n = value, new->left = NULL, new->right = NULL;

	trv = *tree;
	while (trv)
	{
		last = trv;
		if (value == trv->n)
		{
			free(new);
			return (NULL);
		}
		if (value < trv->n)
			trv = trv->left;
		else
			trv = trv->right;
	}

	new->parent = last;
	if (!last)
	{
		last = new;
		*tree = new;
	}
	else if (value < last->n)
		last->left = new;
	else
		last->right = new;

	return (new);
}
