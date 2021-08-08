#include "binary_tree.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

node_t *allocnode()
{
	node_t *node;
	node = malloc(sizeof(node_t));
	node->key = NULL;
	node->data = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

node_t *insert(node_t *root, char *key, void *data)
{
	node_t *node = allocnode();
	node_t *this_node = root;
	node->key = key;
	node->data = data;
	bool stop = false;
	while (stop == false)
	{
		if(root != NULL)
		{
			int diff = strcmp(this_node->key, node->key);
			if (diff == 0)
			{
				free(node);
				stop = true;
			}
			else if (diff < 0)
			{
				if (this_node->left == NULL)
				{
					this_node->left = node;
					stop = true;
				}
				else
				{
					this_node = this_node->left;
				}
			}
			else
			{
				if (this_node->right == NULL)
				{
					this_node->right = node;
					stop = true;
				}
				else
				{
					this_node = this_node->right;
				}
			}
		}
	}
	return this_node;
}
