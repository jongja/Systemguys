/* Red Black Tree
 *
 * Author : Jongja & JaeHyuk
 * Created by Systemguys 2020
 * Copyright © 2020 Systemguys All rights reserved.
 *
 */

#include "rbtree.h"

void RedBlackTree::rbtree_clear(rbnode* cur)
{
	if (cur->left) rbtree_clear(cur->left);
	if (cur->right) rbtree_clear(cur->right);
	delete cur;
}

RedBlackTree::RedBlackTree()
{
	this->root = NULL;
	this->size = 0;
}

RedBlackTree::~RedBlackTree()
{
	rbnode* walker = this->root;
	if (walker->left) rbtree_clear(walker->left);
	if (walker->right) rbtree_clear(walker->right);
	delete walker;
}
