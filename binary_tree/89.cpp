// find the closest leaf in a binary tree//
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree *newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
int flag=0;
tree * find(tree *root, int k)
{
	if(root==NULL)
		return NULL;
	if(root->val==key)
	{
		flag=1;
		return root;
	}
	if(flag==0)
	{
		return find(root->left,k);
		return find(root->right,k);
	}
	if(flag==1)
		return root;
}
int down_leaves(tree *p, int level)
{
	if(p==NULL)
		return NULL;
	if(p->left==NULL && p->right==NULL)
		return level;
	return min(down_leaves(p->left,level+1),down_leaves(p->right,level+1));
}
int fxn2(tree *root, tree *p)
{
	int min_down=0;
	min_down=down_leaves(p,0);
	min_up=up_leaves(p,

int fxn1(tree *root, int k)
{
	tree *p;
	p=find(root,k);
	return fxn2(p,root);

int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int k;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->right->left=newnode(4);
	root->right->right=newnode(5);
	root->right->left->left=newnode(6);
	root->right->right->right=newnode(7);
	root->right->left->left->left=newnode(8);
	root->right->left->left->right=newnode(9);
	root->right->right->right->left=newnode(10);
	cout << "ENTER THE KEY\n";
	cin >> k;
	fxn1(root,k);
