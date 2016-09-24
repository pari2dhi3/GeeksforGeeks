//Find multiplication of sums of data of leaves at same levels//
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
int height(tree *root, int level, int *max_level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
	{
		if(level>(*max_level))
		{
			(*max_level)=level;
			return (*max_level);
		}
		return level;
	}
	return max(height(root->right,level+1,max_level),height(root->left,level+1,max_level));
}
int level_order(tree *root, int level)
{
	if(root==NULL)
		return 0;
	if(level==1 && root->left==NULL && root->right==NULL)
		return root->val;
	if(level==1)
		return 0;
	if(level>1)
		return level_order(root->left,level-1)+level_order(root->right,level-1);
}
int fxn1(tree *root)
{
	int max_level=0,i,sum=0,ans=1,h;
	h=height(root,1,&max_level);
	for(i=1;i<=h;i++)
	{
		sum=level_order(root,i);
		if(sum)
			ans=ans*sum;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(2);
	root->left=newnode(7);
	root->right=newnode(5);
	root->left->left=newnode(8);
	root->left->right=newnode(6);
	root->left->right->left=newnode(1);
	root->left->right->right=newnode(11);
	root->right->right=newnode(9);
	root->right->right->left=newnode(4);
	root->right->right->right=newnode(10);
	cout << "ANSWER IS : " << fxn1(root) << endl;
	return 0;
}

