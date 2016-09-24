#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree *newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void find_min_max(tree *root, int curr, int *min, int *max)
{
	if(root==NULL)
		return;
	if(curr<(*min))
		(*min)=curr;
	if(curr>(*max))
		(*max)=curr;
	find_min_max(root->left,curr-1,min,max);
	find_min_max(root->right,curr+1,min,max);
	return;
}
void print(tree *root, int i, int curr)
{
	if(root==NULL)
		return;
	if(curr==i)
		cout << root->val << " ";
	print(root->left,i,curr-1);
	print(root->right,i,curr+1);
	return;
}
void vertical(tree *root)
{
	int min=0, max=0, curr=0, i;
	find_min_max(root,curr,&min,&max);	
	for(i=min;i<=max;i++)
	{
		print(root,i,curr);
		cout << endl;
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->right->left->right=newnode(8);
	root->right->right->right=newnode(9);
	vertical(root);
	return 0;
}
