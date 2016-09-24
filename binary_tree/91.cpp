// Print nodes in top view of Binary Tree//
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
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void leftmost(tree *root)
{
	if(root==NULL)
		return;
	leftmost(root->left);
	cout << root->val << " ";
	return;
}
void rightmost(tree *root)
{
	if(root==NULL)
		return;
	cout << root->val << " ";
	rightmost(root->right);
	return;
}
void top_view(tree *root)
{
	leftmost(root);
	rightmost(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	cout << "THE TOP VIEW OF THE GIVEN TREE IS : ";
	top_view(root);
	cout << endl;
	return 0;
}
