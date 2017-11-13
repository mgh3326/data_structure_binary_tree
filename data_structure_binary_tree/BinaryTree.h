#pragma once
#include "BinaryNode.h"
class BinaryTree
{
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	//이진트리의 inoder 순회 연산
	void inorder() { printf("\n   inorder: "); inorder(root); }
	void inorder(BinaryNode *node) {//순환적인 트리의 순회함수
		if (node != NULL) {
			if (node->getLeft() != NULL)inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != NULL)inorder(node->getRight());
		}
	}
	//이진 트리의 preorder 순회 연산
	void preorder() { printf("\n  preorder: "); preorder(root); }
	void preorder(BinaryNode *node) {//순환적인 트리의 순회함수
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			if (node->getLeft() != NULL)preorder(node->getLeft());
			if (node->getRight() != NULL)preorder(node->getRight());
		}
	}
	//이진 트리의 postorder 순회 연산
	void postorder() { printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode *node) {//순환적인 트리의 순회함수
		if (node != NULL) {
			if (node->getLeft() != NULL)postorder(node->getLeft());
			if (node->getRight() != NULL)postorder(node->getRight());
			printf(" [%c] ", node->getData());

		}
	}
	void levelorder() {}
	//이진트리의 추가연산
	int getCount() {}
	int getHeight() {}
	int getLeafCount() {}
};