//Count BST subtrees that lie in given range
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
void counter(tree* root, int min, int max, int* key)
{
	if(root==NULL)
		return;
	if(root->val<=max && root->val>=min)
	{
		(*key)+=1;
		counter(root->left,min,max,key);
		counter(root->right,min,max,key);
	}
	if(root->val>max)
		counter(root->left,min,max,key);
	if(root->val<min)
		counter(root->right,min,max,key);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int key=0,min,max;
	root=insert(root,10);
	insert(root,5);
	insert(root,50);
	insert(root,1);
	insert(root,40);
	insert(root,100);
	cin >> min >> max;
	counter(root,min,max,&key);
	cout << key << endl;
	return 0;
}
