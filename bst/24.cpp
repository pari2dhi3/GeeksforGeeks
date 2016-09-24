//Construct BST from given preorder traversal | Set 1
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
void build(tree* &root, int arr[], int min, int max,int i)
{
	if(root==NULL && min<arr[i] && arr[i]<max)
	{
		root=newnode(arr[i]);
		return;
	}
	if(arr[i]<root->val)
		build(root->left,arr,min,root->val,i);
	if(arr[i]>root->val)
		build(root->right,arr,root->val,max,i);
	return;
}
void print(tree* &root)
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
	int arr[]={10, 5, 1, 7, 40, 50};
	int min=INT_MIN, max=INT_MAX,i;
	for(i=0;i<6;i++)
		build(root,arr,min,max,i);
	print(root);
	cout << endl;
	return 0;
}
