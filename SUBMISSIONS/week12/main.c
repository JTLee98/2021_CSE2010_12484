#include <stdio.h>
#include "BTree.h"

int main()
{
	Node* root = initNode();
	root->type = 'r';
	int i, n, k;

	printf_s("enter number of keys to insert: ");
	scanf_s("%d", n);
	for (i = 0; i < n; i++)
	{
		printf_s("enter key #%d: ", i);
		scanf_s("%d", k);
		root = insertNode(root, k);
	}



}