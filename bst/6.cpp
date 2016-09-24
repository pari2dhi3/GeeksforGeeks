//Inorder predecessor and successor for a given key in BST//
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree* left;
	tree* right;
	int val;
}tree;
tree* newnode(int data)
{
	tree* node;
	node=(tree *)malloc(sizeof(tree));
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
int predecessor(tree* root)
{
	if(root->left==NULL && root->right==NULL)
		return root->val;
	if(root->right)
		return predecessor(root->right);
}
int successor(tree* root)
{
	if(root->left==NULL && root->right==NULL)
		return root->val;
	if(root->left)
		return successor(root->left);
}
bool find(tree* root, int key, int *pre, int *succ)
{
	if(root==NULL)
		return false;
	if(root->val==key)
	{
		if(root->left)
			(*pre)=predecessor(root->left);
		if(root->right)
			(*succ)=successor(root->right);
		return true;
	}
	if(root->val>key)
	{
		(*succ)=root->val;
		return find(root->left,key,pre,succ);
	}
	if(root->val<key)
	{
		(*pre)=root->val;
		return find(root->right,key,pre,succ);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int key,pre=0,succ=0;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	cout << "ENTER THE KEY\n";
	cin >> key;
	if(find(root,key,&pre,&succ))
		cout << "FOUND\n" << "SUCCESSOR IS : " << succ << " PREDECESSOR IS : " << pre << endl;
	else
		cout << "NOT FOUND\n" << "SUCESSOR IS : " << succ << " PREDECESSOR IS : " << pre << endl;
	return 0;
}
