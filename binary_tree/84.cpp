//Reverse alternate level of  perfect binary tree//
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
int height(tree *root, int level, int *max_level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL&&(*max_level)<level)
	{
		(*max_level)=level;
		return (*max_level);
	}
	return max(height(root->right,level+1,max_level),height(root->left,level+1,max_level));
}
stack<int> s;
void level_order(tree *root, int level) 
{
	if(root==NULL)
		return;
	if(level==1)
		s.push(root->val);
	else if(level>1)
	{
		level_order(root->left,level-1);
		level_order(root->right,level-1);
	}
	return;
}
void rev_level_order(tree *root, int level)
{
	if(root==NULL)
		return;
	if((level==1)&&(!s.empty()))
	{
		root->val=s.top();
		s.pop();
	}
	else if(level>1)
	{
		rev_level_order(root->left,level-1);
		rev_level_order(root->right,level-1);
	}
	return;
}
void modify(tree *root)
{
	int h,level=1,max_level=0,i;
	int arr[]={0};
	h=height(root,level,&max_level);
	for(i=1;i<=h;)
	{
		level_order(root,i);
		rev_level_order(root,i);
		i=i+2;
	}
	return;
}
void print(tree *root)
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
	tree *root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->left->left->left=newnode(8);
	root->left->left->right=newnode(9);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(11);
	root->right->left->left=newnode(12);
	root->right->left->right=newnode(13);
	root->right->right->left=newnode(14);
	root->right->right->right=newnode(15);
	modify(root);
	cout << "THE MODIFIED TREE IS : ";
	print(root);
	cout << endl;
	return 0;
}
