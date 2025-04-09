#include "binary_trees.h"

/**
 * depth - Calculates the depth of the leftmost node in a binary tree.
 * @tree: Pointer to the root node of the tree to measure the depth.
 *
 * Return: Depth of the leftmost node.
 */
static size_t depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * is_perfect_helper - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * @d: Depth of the leftmost leaf.
 * @level: Level of the current node.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
static int is_perfect_helper(const binary_tree_t *tree, size_t d, size_t level)
{
	if (tree == NULL)
		return (1);

	/* If it's a leaf, check if it's at the correct depth */
	if (tree->left == NULL && tree->right == NULL)
		return (level == d);

	/* If it's not a leaf and has one child, it's not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Check recursively for left and right children */
	return (is_perfect_helper(tree->left, d, level + 1) &&
		is_perfect_helper(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t d;  /* Declare variable at the top */

	if (tree == NULL)
		return (0);

	/* Get the depth of the leftmost node */
	d = depth(tree);

	/* Call the helper function to check if the tree is perfect */
	return (is_perfect_helper(tree, d, 0));
}

