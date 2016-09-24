#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
bool check_completeBT(tree *, int *);
tree * newnode(int data)
{
	tree *node=(tree *)malloc(sizeof(node));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
bool check_completeBT1(tree *node, int fl)
{
	return check_completeBT(node, &fl);
}
bool check_completeBT(tree *node, int *flag)
{
	if(node==NULL)
		return true;
	if(node->left!=NULL&&node->right!=NULL)
		return (check_completeBT(node->left, flag) && check_completeBT(node->right, flag));
	if(node->left==NULL&&node->right==NULL)
		return true;
	if(node->left!=NULL&&node->right==NULL)
	{
		if(*flag==0)
		{
			if((node->left->left==NULL)&&(node->left->right==NULL))
			{
				*flag=1;
				return true;
			}
			else
				return false;
		}
		if(*flag==1)
			return false;
	}
	if(node->left==NULL && node->right!=NULL)
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	bool ans;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	ans=check_completeBT1(root,0);
	if(ans==true)
		cout << "The B-Tree is completed\n";
	else
		cout << "The B-Tree is incomplete\n";
	return 0;
}

