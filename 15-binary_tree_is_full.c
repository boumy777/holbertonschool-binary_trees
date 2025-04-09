#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Si c'est une feuille (pas d'enfants), c'est full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Si les deux enfants existent, on vérifie récursivement les sous-arbres */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* Si un seul enfant existe, ce n'est pas full */
	return (0);
}

