//Given a binary tree how do you remove all the half nodes//
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *right;
	tree *left;
	int val;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
tree *remove(tree *root)
{
	if(root==NULL)
		return NULL;
	root->left=remove(root->left);
	root->right=remove(root->right);
	if(root->left==NULL && root->right==NULL)
		return root;
	if(root->left==NULL)
	{
		tree *new_node;
		new_node=root->right;
		free(root);
		return new_node;
	}
	if(root->right==NULL)
	{
		tree *new_node;
		new_node=root->left;
		free(root);
		return new_node;
	}
	return root;
}
void print(tree *root)
{
	if(root==NULL)
		return;
	print(root->left);
	cout << root->val << " ";
	print(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(2);
	root->left=newnode(7);
	root->right=newnode(5);
	root->left->right=newnode(6);
	root->left->right->left=newnode(1);
	root->left->right->right=newnode(11);
	root->right->right=newnode(9);
	root->right->right->left=newnode(4);

	remove(root);
	cout << "THE INORDER TRAVERSAL OF MODIFIED BINARY TREE IS : ";
	print(root);
	cout << endl;
	return 0;
}
