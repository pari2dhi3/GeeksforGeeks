//Two nodes of a BST are swapped, correct the BST
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree* newnode(int data)
{
	tree* node;
	node=(tree* )malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
tree* insert(tree* &root, int data)
{
	if(root==NULL)
	{
		root=newnode(data);
		return root;
	}
	else if(data>root->val)
		return insert(root->right,data);
	else if(data<root->val)
		return insert(root->left,data);
}
void check(tree* root, tree** m1, tree** m2, int* flag, int min, int max)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		return;
	if(root->left)
	{
		if(root->left->val<root->val && root->left->val>min)
			check(root->left,m1,m2,flag,min,root->val);
		else
		{
			if((*flag)==0)
			{
				(*m1)=root->left;
				(*flag)=1;
			}
			else if((*flag)==1)
			{
				(*m2)=root->left;
				return;
			}
		}
	}
	if(root->right)
	{
		if(root->right->val>root->val && root->right->val<max)
			check(root->right,m1,m2,flag,root->val,max);
		else
		{
			if((*flag)==0)
			{
				(*m1)=root->right;
				(*flag)=1;
			}
			else if((*flag)==1)
			{
				(*m2)=root->right;
				return;
			}
		}
	}
	return;
}
void inorder(tree *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	tree* m1=NULL, *m2=NULL;
	int min=INT_MIN,max=INT_MAX, flag=0;
	root=newnode(10);
	root->left=newnode(5);
	root->right=newnode(8);
	root->left->left=newnode(2);
	root->left->right=newnode(20);
	check(root,&m1,&m2,&flag,min,max);
	int temp;
	temp=m1->val;
	m1->val=m2->val;
	m2->val=temp;
	inorder(root);
	cout << endl;
	return 0;
}
