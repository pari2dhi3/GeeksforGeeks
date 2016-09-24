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
int leaf;
int deep(tree *root, int level, int *level_max)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
	{
		if((*level_max)<level)
		{
			(*level_max)=level;
			leaf=root->left->val;
			return level;
		}
	}
	return max(deep(root->right,level+1,level_max), deep(root->left,level+1,level_max));
}
int deepest_left_leaf(tree *root)
{
	int level=1, level_max=0;
	return deep(root,level,&level_max);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL;
	int level;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->left=newnode(5);
	root->right->right=newnode(6);
	root->right->left->right=newnode(7);
	root->right->right->right=newnode(8);
	root->right->left->right->left=newnode(9);
	root->right->right->right->right=newnode(10);
	level=deepest_left_leaf(root);
	cout << "THE DEEPEST LEFT LEAF IS " << leaf << " AT HEIGHT " << level+1 << endl;
	return 0;
}

