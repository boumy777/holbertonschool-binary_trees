#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node, or NULL if no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the node or its parent is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* If the parent is the left child, the uncle will be the right child */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* If the parent is the right child, the uncle will be the left child */
	if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);

	/* If no uncle exists, return NULL */
	return (NULL);
}

