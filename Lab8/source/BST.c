#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


void insertTreeNode(Node** p, int value);
void printTreePreorder(Node* pNode);
void printTreeInorder(Node* pNode);
void printTreePostorder(Node* pNode);


Node* searchTreeNode(Node* p, int value);
Node* searchTreeParentNode(Node* p, int value);
void deleteTreeNode(Node** p, int value);
void copyTreeNode(Node* src, Node** dst);
int compareTwoTree(Node* t1, Node* t2);

int main()
{
	Node* pParentNode = NULL;
	Node* cParentNode = NULL;

	///Insert Data into Tree(pParentNode)
	insertTreeNode(&pParentNode, 4);
	insertTreeNode(&pParentNode, 2);
	insertTreeNode(&pParentNode, 6);
	insertTreeNode(&pParentNode, 1);
	insertTreeNode(&pParentNode, 3);
	insertTreeNode(&pParentNode, 5);
	insertTreeNode(&pParentNode, 7);

	///Print Data in Tree(pParentNode)
	printf("Tree(pParentNode)\n");
	printf("Preorder\t:");
	printTreePreorder(pParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(pParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(pParentNode);
	printf("\n\n");

	///Search Data in Tree(pParentNode) 
	printf("Search Data 3\n");
	if (searchTreeNode(pParentNode, 3) != NULL)
		printf("3 is existed\n\n");
	else
		printf("3 is not existed\n\n");

	///Delete Data in Tree(pParentNode)
	//printf("Delete data 3\n");
	//deleteTreeNode(&pParentNode, 3);
	//printf("Delete data 2\n");
	//deleteTreeNode(&pParentNode, 2);
	printf("Delete data 6\n");
	deleteTreeNode(&pParentNode, 6);

	///Search Data in Tree(pParentNode) 
	printf("Search Data 4\n");
	if (searchTreeNode(pParentNode, 6) != NULL)
		printf("6 is existed\n\n");
	else
		printf("6 is not existed\n\n");

	///Print Data in Tree(pParentNode)
	printf("Tree(pParentNode)\n");
	printf("Preorder\t:");
	printTreePreorder(pParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(pParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(pParentNode);
	printf("\n\n");

	///Copy Tree(pParentNode) into Tree(cParentNode)
	copyTreeNode(pParentNode, &cParentNode);

	///Print Data in Tree(cParentNode)
	printf("Preorder\t:");
	printTreePreorder(cParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(cParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(cParentNode);
	printf("\n\n");

	///Compare Data between two Trees
	if (compareTwoTree(pParentNode, cParentNode))
		printf("Two trees are equal\n");
	else
		printf("Two trees are different\n");


	return 0;
}


void insertTreeNode(Node** p, int value)
{
	if ((*p) == NULL)
	{
		// Create TreeNode with value
		(*p) = (Node*)malloc(sizeof(Node));
		(*p)->data = value;
		(*p)->leftChild = NULL;
		(*p)->rightChild = NULL;
	}
	else if ((*p)->data > value)
	{
		// Recursive call to leftChild
		insertTreeNode(&((*p)->leftChild), value);
	}
	else
	{
		// Recursive call to rightChild
		insertTreeNode(&((*p)->rightChild), value);
	}
}


void printTreePreorder(Node* pNode)
{
	if (pNode == NULL)
		return;

	printf("%3d", pNode->data);
	printTreePreorder(pNode->leftChild);
	printTreePreorder(pNode->rightChild);
}

void printTreeInorder(Node* pNode)
{
	if (pNode == NULL)
		return;

	printTreeInorder(pNode->leftChild);
	printf("%3d", pNode->data);
	printTreeInorder(pNode->rightChild);
}

void printTreePostorder(Node* pNode)
{
	if (pNode == NULL)
		return;

	printTreePostorder(pNode->leftChild);
	printTreePostorder(pNode->rightChild);
	printf("%3d", pNode->data);
}

Node* searchTreeNode(Node* p, int value)
{
	//p ?????? ???????? value?? ???? ?????? ????
	Node* iter = p;
	while (iter->data != value)
	{
		//???? p ?????? ???????? ???? ???? ????
		//BST?? ?????? ???? ????
		if (iter->data > value)
			iter = iter->leftChild;
		else iter = iter->rightChild;

		if (iter == NULL)
			return NULL;
	}
	//???????? ???? ?????? ?????? ????
	//?????????? NULL?? ????
	return iter;
}

Node* searchTreeParentNode(Node* p, int value)
{
	//p ?????? ???? ?????? ???? ???? ????
	Node* parentNode = p;
	//p ?????? ???????? value?? ???? ?????? ????
	Node* iter = p;
	while (iter->data != value)
	{
		//???? ?????? p ?????? ????????
		//p ?????? ???? ???? ?????? ????
		parentNode = iter;
		if (iter->data > value)
			iter = iter->leftChild;
		else iter = iter->rightChild;

		if (iter == NULL)
			return NULL;
	}
	// if searched node is root 
	// (i.e. while loop is bypassed)
	// return unchanged p ( = parentNode)
	return parentNode;
}


void deleteTreeNode(Node** p, int value)
{
	Node* parentNode; //???? ?????? ???? ????
	Node* delNode;	  //value ???? ???? ???? ???? ????
	Node* childNode;  //???? ?????? ???? ????
	Node* succNode;   //Degree 2 ?????? ???? ?? ?????? successor ????
	
	parentNode = searchTreeParentNode(*p, value);
	if (parentNode == NULL)
	{
		printf("There is no %d\n", value);
		return;
	}
	else delNode = searchTreeNode(*p, value);
	//Case 1. ???? ?????? ?????? ???? ????
	if (delNode->leftChild == NULL && delNode->rightChild == NULL)
	{
		//???? ?????? root ?????? ????
		if (parentNode == *p) 
		{
			free(*p);
			return;
		}
		else
		{
			//???? ?????? ???? ?????? ???? ???? ?????? ???????? NULL?? ????
			if (delNode == parentNode->leftChild)
				parentNode->leftChild = NULL;
			else parentNode->rightChild = NULL;
		}
	}
	//Case 2. ???? ?????? ???? ???? ????
	else if (delNode->leftChild == NULL || delNode->rightChild == NULL)
	{
		//???? ?????? ???? ?????? childNode ?????? ?????? ?????????? ??
		childNode = delNode->leftChild || delNode->rightChild;
		//???? ?????? root ?????? ????
		if (parentNode == *p)
			*p = childNode;
		else
		{
			//???? ?????? ???? ?????? ???? ???? ?????? ???????? ???? ?????? ????
			if (delNode == parentNode->leftChild)
				parentNode->leftChild = childNode;
			else parentNode->rightChild = childNode;
		}
	}
	//Case 3. ???? ?????? ?? ?? ???? ????
	else
	{
		// delNode?? parent ???? ???? ?????? ???????? right child ????
		if (delNode == parentNode->leftChild)
			parentNode->leftChild = delNode->rightChild;
		else parentNode->rightChild = delNode->rightChild;
		// left child?? right subtree?? bottom left leaf?? ????
		Node* iter = delNode->rightChild;
		while (iter->leftChild != NULL)
			iter = iter->leftChild;
		iter->leftChild = delNode->leftChild;
	}
	free(delNode);
}


void copyTreeNode(Node* src, Node** dst)
{
	if (src == NULL) return;
	if (*dst == NULL)
		*dst = (Node*)malloc(sizeof(Node));
	(*dst)->data = src->data;
	(*dst)->leftChild = NULL;
	(*dst)->rightChild = NULL;
	copyTreeNode(src->leftChild, &((*dst)->leftChild));
	copyTreeNode(src->rightChild, &((*dst)->rightChild));
}

int compareTwoTree(Node* t1, Node* t2)
{
	if (t1 == NULL && t2 == NULL)
		return 1;
	else if (t1 == NULL || t2 == NULL)
		return 0;
	else if (t1->data != t2->data)
		return 0;
	else
		return
		compareTwoTree(t1->leftChild, t2->leftChild) *
		compareTwoTree(t1->rightChild, t2->rightChild);
	
}