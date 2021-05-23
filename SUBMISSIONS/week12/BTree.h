#pragma once
#define M_WAY 3

typedef struct Node
{
	int count;
	char type; // leaf | middle | root | isolated
	int keys[M_WAY];
	struct Node* children[M_WAY + 1];
}Node;

Node* initNode();
Node* insertNode(Node* top, int key);
Node* splitChild(Node* top);
void printTree(Node* top);
