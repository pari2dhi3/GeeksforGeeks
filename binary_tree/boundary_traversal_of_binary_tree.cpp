#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(node));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void left_boundary(tree *node)
{
	if(node->left!=NULL)
	{
		cout << node->val << " ";
		left_boundary(node->left);
	}
	else if(node->left==NULL && node->right!=NULL)
	{
		cout << node->val << " ";
		left_boundary(node->right);
	}
	else
		return;
}
void leaves(tree *node)
{
	if(node==NULL)
		return;
	leaves(node->left);
	if(node->left==NULL && node->right==NULL)
	{
		cout << node->val << " ";
		return;
	}
	leaves(node->right);
	return;
}
void right_boundary(tree *node)
{
	if(node->right!=NULL)
	{
		right_boundary(node->right);
		cout << node->val << " ";
	}
	else if(node->right==NULL && node->left!=NULL)
	{
		right_boundary(node->left);
		cout << node->val << " ";
	}
	else 
		return;
}
void print_boundary(tree *node)
{
	left_boundary(node);
	leaves(node);
	right_boundary(node);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(20);
	root->left=newnode(8);
	root->right=newnode(22);
	root->left->left=newnode(4);
	root->left->left->right=newnode(5);
	root->left->right=newnode(12);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);
	root->right->left=newnode(25);
	root->right->left->left=newnode(26);
	root->right->left->right=newnode(27);
	print_boundary(root);
	cout << endl;
	return 0;
}

