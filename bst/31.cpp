//Merge Two Balanced Binary Search Trees
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
void inorder(tree* &root, vector<int> &v)
{
	if(root==NULL)
		return;
	inorder(root->left,v);
	v.push_back(root->val);
	inorder(root->right,v);
	return;
}
tree* build_bst(vector<int> v, tree* &root, int start, int end)
{
	int curr;
	if(start>end)
		return NULL;
	curr=(start+end)/2;
	root=newnode(v[curr]);
	root->left=build_bst(v,root->left,start,curr-1);
	root->right=build_bst(v,root->right,curr+1,end);
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
	tree* root1=NULL, *root2=NULL, *root=NULL;
	int key;
	vector<int> v1;
	root1=insert(root1,50);
	root2=insert(root2,30);
	insert(root1,20);
	insert(root2,40);
	insert(root1,70);
	insert(root2,60);
	insert(root1,80);
	inorder(root1,v1);
	inorder(root2,v1);
	sort(v1.begin(),v1.begin()+7);
	root=build_bst(v1,root,0,v1.size()-1);
	print(root);
	cout << endl;
	return 0;
}

