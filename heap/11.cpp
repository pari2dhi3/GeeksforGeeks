//Check if a given Binary Tree is Heap
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
int height(tree* root, int level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return level;
	return height(root->left,level+1);
}
bool inorder(tree* &root, int level, int h, int *flag)
{
	if(root==NULL)
		return true;
	if(root->left==NULL && root->right==NULL && level==h && (*flag)==0)
		return true;
	else if(root->left==NULL && root->right==NULL && level==(h-1))
	{
		if(*flag==0)
		{
			(*flag)=1;
			return true;
		}
	}
	else if(root->left==NULL && root->right==NULL)
		return false;
	return inorder(root->left,level+1,h,flag) && inorder(root->right,level+1,h,flag);
}
bool iscomplete(tree* &root)
{
	int h,level=1,flag=0;
	h=height(root,level);
	return inorder(root,level,h,&flag);
}
bool isgreater(tree* &root)
{
	if(root==NULL)
		return true;
	else if(root->left==NULL && root->right==NULL)
		return true;
	else if(root->left && root->right==NULL && root->left->val<root->val)
		return true;
	else if(root->val>=root->left->val && root->val>=root->right->val)
		return isgreater(root->left)&&isgreater(root->right);
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int key;
	root=newnode(97);
	root->left=newnode(46);
	root->right=newnode(37);
	root->left->left=newnode(12);
	root->left->right=newnode(3);
	root->right->left=newnode(7);
	root->right->right=newnode(31);
	root->left->left->left=newnode(2);
	root->left->left->right=newnode(4);
	if(iscomplete(root))
	{
		if(isgreater(root))
			cout << "It is a heap also!\n";
		else
			cout << "It is not a heap\n";
	}
	else
		cout << "It is not a heap!!\n";
	return 0;
}
