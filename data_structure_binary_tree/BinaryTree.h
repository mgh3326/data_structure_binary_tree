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

	//����Ʈ���� inoder ��ȸ ����
	void inorder() { printf("\n   inorder: "); inorder(root); }
	void inorder(BinaryNode *node) {//��ȯ���� Ʈ���� ��ȸ�Լ�
		if (node != NULL) {
			if (node->getLeft() != NULL)inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != NULL)inorder(node->getRight());
		}
	}
	//���� Ʈ���� preorder ��ȸ ����
	void preorder() { printf("\n  preorder: "); preorder(root); }
	void preorder(BinaryNode *node) {//��ȯ���� Ʈ���� ��ȸ�Լ�
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			if (node->getLeft() != NULL)preorder(node->getLeft());
			if (node->getRight() != NULL)preorder(node->getRight());
		}
	}
	//���� Ʈ���� postorder ��ȸ ����
	void postorder() { printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode *node) {//��ȯ���� Ʈ���� ��ȸ�Լ�
		if (node != NULL) {
			if (node->getLeft() != NULL)postorder(node->getLeft());
			if (node->getRight() != NULL)postorder(node->getRight());
			printf(" [%c] ", node->getData());

		}
	}
	void levelorder() {}
	//����Ʈ���� �߰�����
	int getCount() {}
	int getHeight() {}
	int getLeafCount() {}
};