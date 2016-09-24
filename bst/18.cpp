//Remove BST keys outside the given range
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
tree* remove(tree* &root, int min, int max)
{
	if(root==NULL)
		return NULL;
	root->left=remove(root->left,min,max);
	root->right=remove(root->right,min,max);
	if(root->val>max)
	{
		tree* temp;
		temp=root->left;
		delete(root);
		return temp;
	}
	else if(root->val<min)
	{
		tree* temp;
		temp=root->right;
		delete(root);
		return temp;
	}
	else if(root->val<max && root->val>min)
	{
		return root;
	}
	return root;
}
void print(tree* root)
{
	if(root==NULL)
		return;
	print(root->left);
	cout << root->val << " ";
	print(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int min,max;
	root=insert(root,6);
	insert(root,-13);
	insert(root,-8);
	insert(root,-6);
	insert(root,14);
	insert(root,13);
	insert(root,7);
	insert(root,15);
	cin >> min >> max;
	remove(root,min,max);
	print(root);
	cout << endl;
	return 0;
}
