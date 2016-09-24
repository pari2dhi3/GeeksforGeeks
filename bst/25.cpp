//	Floor and Ceil from a BST
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
int ceil(tree* root, int key, int *max)
{
	if(root==NULL)
		return (*max);
	else if(root->val==key)
		return root->val;
	else if(key>root->val)
		return ceil(root->right,key,max);
	else if(key<root->val)
	{
		(*max)=root->val;
		return ceil(root->left,key,max);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int key,max=INT_MAX;
	root=insert(root,8);
	insert(root,4);
	insert(root,12);
	insert(root,2);
	insert(root,6);
	insert(root,10);
	insert(root,14);
	cin >> key;
	cout << "CEIL IS : " << ceil(root,key,&max) << endl;
	return 0;
}
