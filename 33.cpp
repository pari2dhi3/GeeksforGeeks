//Transform a BST to greater sum tree
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
void transform(tree* &root, int *sum)
{
	int temp;
	if(root==NULL)
		return;
	transform(root->right,sum);
	temp=root->val;
	root->val=(*sum);
	(*sum)+=temp;
	transform(root->left,sum);
	return;
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
	int sum=0;
	root=insert(root,11);
	insert(root,2);
	insert(root,29);
	insert(root,1);
	insert(root,7);
	insert(root,15);
	insert(root,40);
	insert(root,35);
	transform(root,&sum);
	print(root);
	cout << endl;
	return 0;
}
