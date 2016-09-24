//Check whether a binary tree is a complete tree or not | Set 2 (Recursive Solution)
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
int height(tree *root, int level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return level;
	return height(root->left,level+1);
}
bool fxn(tree *root, int level)
{
	if(level==1)
	{
		if(root!=NULL)
			return true;
		else 
			return false;
	}
	else if(level>1)
		return (fxn(root->left,level-1) && fxn(root->right,level-1));
}
bool fxn1(tree *root, int level, int *flag)
{
	if(level==1)
	{
		if(root==NULL)
		{
			if((*flag)==0)
				(*flag)=1;
			return true;
		}
		else if(root->left==NULL && root->right==NULL && (*flag)==0)
				return true;
		return false;
	}
	else if(level>1)
		return (fxn1(root->left,level-1,flag)&&fxn1(root->right,level-1,flag));
}
bool is_complete_bt(tree *root)
{
	int h,level=1,flag=0,i;
	h=height(root,level);
	for(i=1;i<h;i++)
	{
		if(!fxn(root,i))
			return false;
	}
	return fxn1(root,h,&flag);
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
	root->left->right->right=newnode(6);
	if(is_complete_bt(root))
		cout << "THE BINARY TREE IS A COMPLETE BT\n";
	else
		cout << "THE BINARY TREE IS NOT COMLETE BT\n";
	return 0;
}

