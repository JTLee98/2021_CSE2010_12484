#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

Node* initNode()
{
	Node* newNode = (Node*)malloc(sizeof(Node*));
	newNode->count = 0;
	newNode->type = 'i';
	newNode->children = {};
	newNode->keys = {};
}

Node* insertNode(Node* top, int key)
{
	int i, pos, mid;
	Node* split;

	// top is leaf 
	if (top->type = 'l' || top->type == 'i')
	{
		for (pos = 0; pos < top->count; pos++)
			if (top->keys[pos] > key) break;

		for (i = top->count; i > pos; i--)
			top->keys[i] = top->keys[i - 1];
		top->keys[pos] = key;
		top->count++;

		if (top->count == M_WAY && top->type == 'r')
			return splitChild(top);
		return top;
	}
	// not leaf or isolated
	for (pos = 0; pos < top->count; pos++)
		if (top->keys[pos] > key) break;
	top->children[pos] = insertNode(top->children[pos], key);
	Node* child = top->children[pos];
	// node is full
	if (child->count == M_WAY)
	{
		split = splitChild(child);
		for (int i = top->count; i > pos; i--)
		{
			top->keys[i] = top->keys[i - 1];
			top->children[i + 1] = top->children[i];
		}
		top->keys[pos] = split->keys[0];
		top->count++;
		top->children[pos] = split->children[0];
		top->children[pos + 1] = split->children[1];
	}
	if (top->count == M_WAY && top->type == 'r')
		return splitChild(top);
	else return top;
}

Node* splitChild(Node* top)
{
	int i = 0, j = 0, mid = (M_WAY - 1) / 2;
	Node* parent = initNode();
	Node* sibling = initNode();
	if (top->type == 'r')
		parent->type = 'r';
	else if (top->type == 'i')
	{
		parent->type = 'r';
		top->type = 'l';
		sibling->type = 'l';
	}
	top->type = 'm';
	
	int j = 0;
	for (i = mid + 1; i < M_WAY; i++)
	{
		j = i - (mid + 1);
		sibling->children[j] = top->children[i];
		sibling->keys[j] = top->keys[i];

		top->children[i] = NULL;
		top->keys[i] = 0;
		top->count--;
	}
	sibling->children[j + 1] = top->children[i];
	top->children[i] = NULL;

	parent->keys[0] = top->keys[mid];
	parent->count++;
	top->keys[mid] = 0;
	top->count--;

	parent->children[0] = top;
	parent->children[1] = sibling;
	return parent;

}

void printTree(Node* top)
{
	if (top == NULL) return;
	if (top->type == 'r')
		printf_s("B-Tree at %p :\n", top);
	const int count = top->count;
	Node* children[count] = top->children;
	int keys[count] = top->keys;
	for (int i = 0; i < count; i++)
	{
		printTree(children[i]);
		printf_s("%d, ", keys[i]);
	}
}
