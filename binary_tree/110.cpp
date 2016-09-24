//Construct Binary Tree from given Parent Array representation
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
	node->right==NULL;
	node->val=data;
	return node;
}
int arr[]={1,5,5,2,2,-1,3};
int find(int key, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==key)
		{
			arr[i]=-1;
			return i;
		}
	}
	return -1;
}
void build1(tree *root,int key, int size)
{
	int left, right;
	if(root==NULL)
		return;
	left=find(key,size);
	right=find(key,size);
	if(left!=-1)
		root->left=newnode(left);
	else
		root->left=NULL;
	if(right!=-1)
		root->right=newnode(right);
	else
		root->right=NULL;
	build1(root->left,left,size);
	build1(root->right,right,size);
	return;
}
tree * build(tree *root,int key, int size)
{
	int index;
	index=find(key,size);
	root=newnode(index);
	key=index;
	build1(root,key,size);
	return root;
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
	tree *root=NULL;
	root=build(root,-1,7);
	cout << "THE INORDER TRAVERSAL OF THE BUILT TREE IS : ";
	print(root);
	cout << endl;
	return 0;
}
