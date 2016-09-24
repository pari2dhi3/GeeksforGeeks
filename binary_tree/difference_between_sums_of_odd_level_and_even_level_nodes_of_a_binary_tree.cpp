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
int distance(tree *root)
{
	if(!root)
		return 0;
	return (root->val-distance(root->left)-distance(root->right));
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int diff=0;
	root=newnode(5);
	root->left=newnode(2);
	root->right=newnode(6);
	root->left->left=newnode(1);
	root->left->right=newnode(4);
	root->left->right->left=newnode(3);
	root->right->right=newnode(8);
	root->right->right->left=newnode(7);
	root->right->right->right=newnode(9);
	diff=distance(root);
	cout << diff << endl;
	return 0;
}
