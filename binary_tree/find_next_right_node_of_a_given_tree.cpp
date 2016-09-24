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
int height(tree *root, int level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return level;
	return max(height(root->left,level+1), height(root->right,level+1));
}
int flag=0;
void next_right1(tree *root, int key, int level)
{
	if(root==NULL)
		return;
	if(level==1)
	{
		if(flag==1)
		{
			cout << root->val << endl;
			flag=0;
		}
		if(root->val==key)
			flag=1;
		return;
	}
	else if(level>1)
	{
		next_right1(root->left,key,level-1);
		next_right1(root->right,key,level-1);
	}
	return;
}
void next_right(tree *root, int key)
{
	int h,i;
	h=height(root,1);
	for(i=1;i<=h;i++)
	{
		flag=0;
		next_right1(root,key,i);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int key=0;
	root=newnode(10);
	root->left=newnode(2);
	root->right=newnode(6);
	root->left->left=newnode(8);
	root->left->right=newnode(4);
	root->right->right=newnode(5);
	cout << "ENTER THE KEY\n";
	cin >> key;
	next_right(root,key);
	return 0;
}
