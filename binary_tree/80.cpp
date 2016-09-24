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
	node->left==NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void dist_k_down(tree *root, int k)
{
	if(root==NULL)
		return;
	if(k==0)
		cout << root->val << " ";
	else if(k>0)
	{
		dist_k_down(root->left,k-1);
		dist_k_down(root->right,k-1);
	}
	return;
}
int flag=0; 
void find_key(tree *root, int key, int k)
{
	if(root==NULL)
		return;
	if(root->val==key)
	{
		dist_k_down(root,k);
		flag=1;
		return;
	}
	if(!flag)
		find_key(root->left,key,k);
	if(!flag)
		find_key(root->right,key,k);
	else
		return;
}
void dist_k_up(tree *root, int key, int k)
{
	if(root==NULL)
		return;
	if(k==0 && root->val!=key)
		cout << root->val << " ";
	if(root->val==key)
		return;
	else if(k>0)
	{
		dist_k_up(root->left,key,k-1);
		dist_k_up(root->right,key,k-1);
	}
	return;
}
void find_key1(tree *root, int key, int k)
{
	if(root==NULL)
		return;
	if(root->val==key)
	{
		flag=1;
		return;
	}
	if(!flag)
		find_key1(root->left,key,k);
	if(!flag)
		find_key1(root->right,key,k);
	if(flag && (k-flag)>=0)
	{
		dist_k_up(root,key,k-flag);
		flag++;
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int key, k;
	root=newnode(20);
	root->left=newnode(8);
	root->right=newnode(22);
	root->left->left=newnode(4);
	root->left->right=newnode(12);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);
	cout << "ENTER THE VALUE OF KEY AND K \n";
	cin >> key >> k;
	find_key(root,key,k);
	flag=0;
	find_key1(root,key,k);
	return 0;
}

