//to find maximum path sum between two leaves of a binary tree//
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
int left_max_sum(tree *root, int *max_l, int sum)
{
	if(root==NULL)
		return 0;
	if((sum+root->val>(*max_l))&&(root->left==NULL && root->right==NULL))
	{
		(*max_l)=sum+root->val;
		return (*max_l);
	}
	return max(left_max_sum(root->right,max_l,sum+root->val),left_max_sum(root->left,max_l,sum+root->val));
}
int right_max_sum(tree *root, int *max_r, int sum)
{
	if(root==NULL)
		return 0;
	if((sum+root->val>(*max_r)) && root->left==NULL && root->right==NULL)
	{
		(*max_r)=sum+root->val;
		return (*max_r);
	}
	return max(right_max_sum(root->right,max_r,sum+root->val),right_max_sum(root->left,max_r,sum+root->val));
}
int fxn(tree *root, int *maxi)
{
	int w, max_l, max_r;
	if(root==NULL)
		return 0;
	w=left_max_sum(root->left,&max_l,0)+right_max_sum(root->right,&max_r,0)+root->val;
	if(w>(*maxi))
		(*maxi)=w;
	return max(fxn(root->right,maxi),fxn(root->left,maxi));
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int maxi=0, w=0;
	root=newnode(-15);
	root->left=newnode(5);
	root->right=newnode(6);
	root->left->left=newnode(-8);
	root->left->right=newnode(1);
	root->right->left=newnode(3);
	root->right->right=newnode(9);
	root->left->left->left=newnode(2);
	root->left->left->right=newnode(6);
	root->right->right->right=newnode(0);
	root->right->right->right->left=newnode(4);
	root->right->right->right->right=newnode(-1);
	root->right->right->right->right->left=newnode(10);
	w=fxn(root,&maxi);
	cout << "THE MAXIMUM SUM BETWEEN 2 LEAVES IN A B-TREE IS : " << maxi << endl;
	return 0;
}
