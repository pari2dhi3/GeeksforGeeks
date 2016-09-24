//Print BST keys in the given range
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
void print(tree* root, int k1, int k2)
{
	if(root==NULL)
		return;
	else if(root->val>k2)
		print(root->left,k1,k2);
	else if(root->val<k1)
		print(root->right,k1,k2);
	else if(root->val>=k1 && root->val<=k2)
	{
		print(root->left,k1,k2);
		cout << root->val << " ";
		print(root->right,k1,k2);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int k1,k2;
	root=insert(root,20);
	insert(root,8);
	insert(root,4);
	insert(root,12);
	insert(root,22);
	cin >> k1 >> k2;
	print(root,k1,k2);
	cout << endl;
	return 0;
}

