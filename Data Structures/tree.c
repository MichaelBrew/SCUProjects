/*
 *  tree.c is the implementation for the tree.h file. It has functions to create a tree
 *  destroy it, get its data, get its left and right children, get its parent, and set 
 *  its left and right children.
 *  
 *
 *  Created by michael brew on 5/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#include <assert.h>
#include "tree.h"
#include <stdlib.h>
#include <string.h>

typedef struct tree TREE;

/*
 * createTree takes in an int for data, then two TREE pointers for the left
 * and right children. It allocates memory for itself then sets it's data
 * to the int passed in and its left and right pointers to the ones passed in.
 * It sets its parent to NULL then returns itself.
 */
TREE *createTree(int data, TREE *left, TREE *right)
{
	TREE *tp;
	tp = malloc(sizeof(TREE));
	assert(tp != NULL);
	
	tp->data = data;
	tp->left = left;
	tp->right = right;
	
	tp->parent = NULL;
	return tp;
}

/*
 * If the root passed in isn't null, it recursively calls itself on the left
 * and right children, then frees the root.
 */
void destroyTree(TREE *root)
{
	if(root == NULL) {
		return;
	}
	
	destroyTree(root->left);
	destroyTree(root->right);
	
	free(root);
}

//If the root isn't null, it returns its data
int getData(TREE *root)
{
	assert(root != NULL);
	return root->data;
}

//If the root isn't null, it returns its left child
TREE *getLeft(TREE *root)
{
	assert(root != NULL);
	return root->left;
}

//If the root isn't null, it returns its right child
TREE *getRight(TREE *root)
{
	assert(root != NULL);
	return root->right;
}

//It returns the root's parent
TREE *getParent(TREE *root)
{	
	return root->parent;
}

/*
 * Auxiliary function that checks to see if the passed in Tree is a left child 
 * or right child. It then set's its parent's respective pointer to null.
 */
void checkingParent(TREE *tp)
{
	if(tp != NULL && tp->parent != NULL) { //if new tree being passed in is not null
		if(tp->parent->left == tp) //if "left's" parent left pointer pointed to "left" then make that pointer null
			tp->parent->left = NULL;
		else if(tp->parent->right == tp)//if "left's" parent right pointer pointed to "left" then make that pointer null
			tp->parent->right = NULL;
	}
}

/*
 * It takes in a root and a new tree to make as the left child. It sets all the pointers
 * in the right places and makes left the left subchild of root.
 */
void setLeft(TREE *root, TREE *left)
{
	assert(root != NULL);
	
	if(root->left != NULL) //if the root's left child is not null
	   root->left->parent = NULL; //make the old left subtree's parent pointer null
	
	checkingParent(left);
	
	root->left = left; //root's left pointer now points to "left"
	if(left != NULL) //if "left" isnt null
		left->parent = root; //"left's" parent pointer now points to root
}

/*
 * It takes in a root and a new tree to make as the right child. It sets all the pointers
 * in the right places and makes right the right subchild of root.
 */
void setRight(TREE *root, TREE *right)
{
	assert(root != NULL);
	
	if(root->right != NULL) //if the root's right child is not null
		root->right->parent = NULL; //make the old right subtree's parent pointer null
	
	checkingParent(right);
	
	root->right = right; //root's right pointer now points to "right"
	if(right != NULL) //if "right" isnt null
		right->parent = root; //"right's" parent pointer now points to root
}
