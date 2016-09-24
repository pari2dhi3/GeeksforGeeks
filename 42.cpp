//	How to implement decrease key or change key in Binary Search Tree?
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
tree* delete_t(tree* &root, int old)
{
	if(root==NULL)
		return NULL;
	if(root->val==old)
	{
		tree* temp;
		temp=root->left;
		free(root);
		return temp;
	}
	if(root->val>old)
		root->left=delete_t(root->left,old);
	if(root->val<old)
		root->right=delete_t(root->right,old);
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
	int old_k,new_k;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	cin >> old_k >> new_k;
	root=delete_t(root,old_k);
	insert(root,new_k);
	print(root);
	cout << endl;
	return 0;
}
