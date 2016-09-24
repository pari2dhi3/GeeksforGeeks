//Inorder Successor in Binary Search Tree
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
int leftmost(tree* root)
{
	if(root->left==NULL)
		return root->val;
	return leftmost(root->left);
}
void successor(tree* root,int key, int *succ)
{
	if(root==NULL)
		return;
	if(root->val==key)
	{
		if(root->right)
		{
			(*succ)=leftmost(root->right);
			return;
		}
	}
	else if(root->val>key)
	{
		(*succ)=root->val;
		successor(root->left,key,succ);
	}
	else if(root->val<key)
		successor(root->right,key,succ);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int key,succ=0;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	cin >> key;
	successor(root,key,&succ);
	cout << "SUCESSOR IS : " << succ << endl;
	return 0;
}
