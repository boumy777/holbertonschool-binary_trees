#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree in post-order.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The value of the
 *        node is passed as a parameter to this function.
 *
 * Return: Nothing.
 *
 * If tree or func is NULL, the function does nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

