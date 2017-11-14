#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"//���翡�� �߰� �϶�� ���� ���µ� �߰� ��Ű��
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
	void levelorder() {
		printf("\n levelorder: ");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf("[%c]  ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
			printf("\n");
		}
	}
	//����Ʈ���� �߰�����
	int getCount() {
		return isEmpty() ? 0 : getCount(root);	}
	int getCount(BinaryNode* node) {
		if (node == NULL)return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	int getLeafCount() {
		return isEmpty() ? 0 : getLeafCount(root);
	}
	int getLeafCount(BinaryNode* node) {
		if (node == NULL)return 0;
		if (node->isLeaf())return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	int getHeight() {
		return isEmpty() ? 0 : getHeight(root);
	}
	int getHeight(BinaryNode* node) {
		if (node == NULL)return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return(hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode *node) {
		if (node == NULL)return 0;
		if (node->isLeaf())return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch (node->getData()) {
			case'+':return op1 + op2;
			case'-':return op1 - op2;
			case'*':return op1 * op2;
			case'/':return op1 / op2;

			}
			return 0;

		}
	}
};