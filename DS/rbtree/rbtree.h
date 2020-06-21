/* Red Black Tree
 *
 * Author : Jongja & JaeHyuk
 * Created by Systemguys 2020
 * Copyright © 2020 Systemguys All rights reserved.
 *
 */
#pragma once
#include <iostream>

typedef struct RedBlackTreeNode
{
	int color;
	int data; // this variable "data" can be changed for any purpose.
	struct RedBlackTreeNode* left;
	struct RedBlackTreeNode* right;
}rbnode;

typedef class RedBlackTree {
public:
	int size;
	rbnode* root;
	RedBlackTree();
	~RedBlackTree();
	void rbtree_clear(rbnode* cur);
	void rbtree_insert(int data);
	void rbtree_delete(int data);
}rbtree;