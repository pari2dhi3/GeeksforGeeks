#include<bits/stdc++.h>
#include<stdio.h>
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
void fxn1(tree *root, int k, int *sumptr)
{
	if(root==NULL)
		return;
	(*sumptr)+=root->val;
	if(root->left==NULL && root->right==NULL)
	{
		if((*sumptr)>=k)
		{
			(*sumptr)-=root->val;
			return;
		}
		(*sumptr)-=root->val;
		free(root);
		return;
	}
	fxn1(root->left,k,sumptr);
	fxn1(root->right,k,sumptr);
	return;
}
void fxn(tree *root, int k)
{
	int sum=0;
	fxn1(root, k, &sum);
	return;
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
	tree *root=NULL;
	int k=0;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->left->left->left=newnode(8);
	root->left->left->right=newnode(9);
	root->left->right->left=newnode(12);
	root->right->right->left=newnode(10);
	root->left->left->right->left=newnode(13);
	root->left->left->right->right=newnode(14);
	root->right->right->left->right=newnode(11);
	root->left->left->right->right->left=newnode(15);
	cout << "ENTER THE VALUE OF K" << endl;
	cin >> k;
	fxn(root,k);
	print(root);
	cout << endl;
	return 0;
}
