//Bottom view of a binary tree//
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
void bottom_view(tree *root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		cout << root->val << " ";
		return;
	}
	bottom_view(root->left);
	bottom_view(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(20);
	root->left=newnode(8);
	root->right=newnode(22);
	root->left->left=newnode(5);
	root->left->right=newnode(3);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);
	root->right->right=newnode(25);
	cout << "THE BOTTOM VIEW OF THE BINARY TREE IS : ";
	bottom_view(root);
	cout << endl;
	return 0;
}
