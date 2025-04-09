#include "binary_trees.h"

/**
 * depth - Helper function to calculate the depth of a tree
 * @tree: Pointer to the root node of the tree
 * Return: Depth of the tree
 */
static int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_helper - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * @d: Depth of the tree
 * @level: Current level of the tree
 * Return: 1 if the tree is perfect, otherwise 0
 */
static int is_perfect_helper(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (1);
	if (!tree->left && !tree->right)
		return (d == level + 1);
	if (!tree->left || !tree->right)
		return (0);
	return (is_perfect_helper(tree->left, d, level + 1) &&
		is_perfect_helper(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (!tree)
		return (0);
	d = depth(tree);
	return (is_perfect_helper(tree, d, 0));
}

