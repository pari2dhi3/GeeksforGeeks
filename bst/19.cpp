//Check if each internal node of a BST has exactly one child
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
bool all_small(int v[], int curr, int i, int size)
{
	int j;
	for(j=i+1;j<=size-1;j++)
	{
		i++;
		if(v[j]>curr)
			return false;
	}
	return true;
}
bool all_big(int v[], int curr, int i, int size)
{
	int j;
	for(j=i+1;i<=size-1;j++)
	{
		i++;
		if(v[j]<curr)
			return false;
	}
	return true;
}
bool check(int v[], int size)
{
	int i;
	for(i=0;i<=size-2;i++)
	{
		if(!(all_small(v,v[i],i,size) || all_big(v,v[i],i,size)))
			return false;
	}
	return true;
}	
int main()
{
	ios_base::sync_with_stdio(false);
	int v[]={20,10,11,13,12};
	int size=sizeof(v)/sizeof(v[0]);
	if(check(v,size))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
