//Find sum of all left leaves in a given binary tree//
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
void sum1(tree *root,int *sum)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		return;
	if(root->left)
	{
		if(root->left->left==NULL && root->left->right==NULL)
			(*sum)+=root->left->val;
	}
	sum1(root->left,sum);
	sum1(root->right,sum);
	return;
}
int sum(tree *root)
{
	int sum=0;
	sum1(root,&sum);
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(20);
	root->left=newnode(9);
	root->right=newnode(49);
	root->left->left=newnode(5);
	root->left->right=newnode(12);
	root->left->right->right=newnode(15);
	root->right->left=newnode(23);
	root->right->right=newnode(52);
	root->right->right->left=newnode(50);
	
	cout << "THE SUM OF ALL LEFT LEAVES IS : " << sum(root) << endl;
	return 0;
}

