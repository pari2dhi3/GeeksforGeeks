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
int fxn(tree *root, int val)
{
	if(root==NULL)
		return 0;
	val=val*10+root->val;
	if(root->left==NULL && root->right==NULL)
		return val;
	return (fxn(root->left,val)+fxn(root->right,val));
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int sum;
	root=newnode(6);
	root->left=newnode(3);
	root->right=newnode(5);
	root->left->left=newnode(2);
	root->left->right=newnode(5);
	root->left->right->left=newnode(7);
	root->left->right->right=newnode(4);
	root->right->right=newnode(4);
	sum=fxn(root,0);
	cout << sum << endl;
	return 0;
}

