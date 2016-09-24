//convert left-right representation of a binary tree to down right//
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
typedef struct tree1
{
	tree1 *right;
	tree1 *down;
	int val;
}tree1;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
tree1 *newnode1(int data)
{
	tree1 *node;
	node=(tree1 *)malloc(sizeof(tree1));
	node->right=NULL;
	node->down=NULL;
	node->val=data;
	return node;
}
void build(tree *root, tree1* root1)
{
	if(root==NULL)
		return;

	if(root->left)
	{
		root1->down=newnode1(root->left->val);
		if(root->right)
			root1->down->right=newnode1(root->right->val);
	}
	build(root->left,root1->down);
	if(root1->down)
		build(root->right,root1->down->right);
	return;
}
tree1* modify(tree *root)
{
	tree1 *root1;
	if(root==NULL)
		return NULL;
	root1=newnode1(root->val);
	build(root,root1);
	return root1;
}
void print(tree1 *root1)
{
	if(root1==NULL)
		return;
	cout << root1->val << " ";
	print(root1->down);
	print(root1->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	tree1 *root1;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->right->left=newnode(4);
	root->right->right=newnode(5);
	root->right->left->left=newnode(6);
	root->right->right->left=newnode(7);
	root->right->right->right=newnode(8);
	cout << "THE MODIFIED DOWN RIGHT B-TREE IS : ";
	root1=modify(root);
	print(root1);
	cout << endl;
	return 0;
}

