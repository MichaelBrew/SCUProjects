/*
 *  deque.c is the implementation for the deque.h abstract. There are functions to
 *  create a deque, destroy it, get the number of items, add to the beginning, add
 *  to the end, remove the first node, remove the last node, get the first node, and 
 *  get the last node.
 *
 *  Created by michael brew on 5/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <assert.h>
#include "deque.h"
#include <stdlib.h>
#include <string.h>

typedef struct node NODE;

//Defines deque to have a count and a node pointer to the head
struct deque {
	int count;
	NODE *head;
};

//Defines a node to have data and pointers to previous and next nodes
struct node {
	int data;
	NODE *prev, *next;
};

/*
 * createDeque() creates a deque, setting its count to 0, allocating memory
 * for the head, and setting its head pointers to itself to make the circular.
 * Returns the deque. 
 */
DEQUE *createDeque(void)
{
	DEQUE *dp;
	dp = malloc(sizeof(DEQUE));
	assert(dp != NULL);
	dp->count = 0;
	dp->head = malloc(sizeof(NODE));
	assert(dp->head != NULL);
	dp->head->next = dp->head;
	dp->head->prev = dp->head;
	return dp;
}

//Takes in a deque pointer, frees each node in the deque, then frees itself
void destroyDeque(DEQUE *dp)
{
	assert(dp != NULL);
	int i;
	for(i = 0; i < dp->count; i++) {
		NODE *np = dp->head->next;
		dp->head->next = np->next;
		free(np);
	}
	
	free(dp->head);
	free(dp);
}

//Takes in a deque then returns the number of items in it
int numItems(DEQUE *dp)
{
	return dp->count;
}

/* 
 * Takes in a deque and data to add to it. Creates a new node and assigns
 * the data to it. Then puts it at the beginning of the deque and increments 
 * the deque's count.
 */
void addFirst(DEQUE *dp, int x)
{
	assert(dp!=NULL);
	NODE *np;	
	np = malloc(sizeof(NODE));
	np->data = x;
	
	//Assigns its pointers and head's pointers to make it the first node
	np->prev = dp->head; 
	np->next = dp->head->next;
	np->next->prev = np;
	dp->head->next = np;		
	dp->count++;
}

/*
 * Takes in a deque and data x, creates a node and assigns x to it, then sets
 * its pointers to make it the last node in the deque.
 */
void addLast(DEQUE *dp, int x)
{
	assert(dp!=NULL);
	NODE *np;
	np = malloc(sizeof(NODE));
	np->data = x;
	
	
	//Assigns its pointers and head's pointers to make it the last node
	np->next = dp->head;
	np->prev = dp->head->prev;
	dp->head->prev = np;
	np->prev->next = np;
	dp->count++;
}

/*
 * Takes in a deque, deletes its first node, decrements the deque's count
 * then returns the data that was removed.
 */
int removeFirst(DEQUE *dp)
{
	assert(dp!= NULL && dp->count > 0);
	NODE *np;
	np = dp->head->next;
	
	dp->head->next = np->next;
	np->next->prev = dp->head;
	
	int npData = np->data;
	free(np);
	dp->count--;
	return npData;
}

//Removes the last node of the deque in the parameter, decrements the count and returns the data
int removeLast(DEQUE *dp)
{
	assert(dp != NULL && dp->count > 0);
	NODE *np;
	np = dp->head->prev;
	
	dp->head->prev = np->prev;
	np->prev->next = dp->head;
	
	int npData = np->data;
	free(np);
	dp->count--;
	return npData;
}

//Returns the data in the first node of the deque passed in
int getFirst(DEQUE *dp)
{
	assert(dp->head->next != NULL);
	return dp->head->next->data;
}

//Returns the data in the last node of the deque passed in
int getLast(DEQUE *dp)
{
	assert(dp->head->next != NULL);
	return dp->head->prev->data;
}
