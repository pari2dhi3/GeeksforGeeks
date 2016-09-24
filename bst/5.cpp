//Min value in a BST//
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
int mini(tree* &root)
{
	if(root==NULL)
		return INT_MIN;
	if(root->left==NULL)
		return root->val;
	if(root->left)
		return mini(root->left);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int key;
	root=insert(root,50);
	insert(root,30);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	cout << "THE MINIMUM OF BST IS : " << mini(root) << endl;
	return 0;
}
