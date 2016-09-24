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
int depth_of_odd_leaf(tree *root, int level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL && level%2!=0)
		return level;
	return max(depth_of_odd_leaf(root->left,level+1),depth_of_odd_leaf(root->right,level+1));
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL;
	int max;
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
	root->right->right->right->right->left=newnode(11);
	max=depth_of_odd_leaf(root,1);
	cout << "THE DEEPEST OF ODD LEAF IN B-TREE IS : " << max << endl;
	return 0;
}

