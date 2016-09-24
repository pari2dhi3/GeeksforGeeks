//Binary Search Tree | Set 2 (Delete)//
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
	tree* root;
	root=(tree* )malloc(sizeof(tree));
	root->left=NULL;
	root->right=NULL;
	root->val=data;
	return root;
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
tree* leftmost(tree* &root, int *m)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right==NULL)
	{
		(*m)=root->val;
		free(root);
		return NULL;
	}
	if(root->left)
		root->left=leftmost(root->left,m);
	else if(root->right)
		root->right=leftmost(root->right,m);
	return root;
}
tree* del(tree* &root, int key)
{
	if(root==NULL)
		return NULL;
	if(root->val==key && root->left==NULL && root->right==NULL)
	{
		free(root);
		return NULL;
	}
	else if(root->val==key && (root->left==NULL || root->right==NULL))
	{
		if(!root->left)
		{
			root->val=root->right->val;
			root->right=del(root->right,root->right->val);
		}
		if(!root->right)
		{
			root->val=root->left->val;
			root->left=del(root->left,root->left->val);
		}
	}
	else if(root->val==key && root->left && root->right)
	{
		int m;
		root->right=leftmost(root->right, &m);
		root->val=m;
	}
	root->left=del(root->left,key);
	root->right=del(root->right,key);
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
	int key;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	cout << "ENTER THE KEY TO BE DELETED\n";
	cin >> key;
	root=del(root,key);
	print(root);
	cout << endl;
	return 0;
}
