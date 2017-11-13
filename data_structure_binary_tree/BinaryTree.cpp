#include "BinaryTree.h"
void main()
{
	BinaryTree tree;
	BinaryNode *d = new BinaryNode('D', NULL, NULL);
	BinaryNode *e = new BinaryNode('E', NULL, NULL);
	BinaryNode *b = new BinaryNode('B', d, e);
	BinaryNode *f = new BinaryNode('F', NULL, NULL);
	BinaryNode *c = new BinaryNode('C', f, NULL);
	BinaryNode *a = new BinaryNode('A', b, c);
	tree.setRoot(a);
	tree.setRoot(a);
	tree.inorder();
	tree.preorder();
	tree.postorder();
	printf("\n");

}