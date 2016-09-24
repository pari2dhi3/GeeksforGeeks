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
	node=(tree *)malloc(sizeof(tree));
	node->val=data;
	node->left=NULL;
	node->right=NULL;
}
int convert(tree *node)
{
	int old_val;
	if(!node)
		return 0;
	old_val=node->val;
	node->val=convert(node->left)+convert(node->right);
	return old_val+node->val;
}
void print(tree *node)
{
	if(!node)
		return;
	print(node->left);
	cout << node->val << " ";
	print(node->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL;
	root=newnode(10);
	root->left=newnode(-2);
	root->right=newnode(6);
	root->left->left=newnode(8);
	root->left->right=newnode(-4);
	root->right->left=newnode(7);
	root->right->right=newnode(5);
	convert(root);
	print(root);
	cout << endl;
	return 0;
}



