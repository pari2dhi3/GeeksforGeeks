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
}tree;
void search(int in[], int y, int x)
{
	for(i=0;i<x;i++)
	{
		if(in[i]==y)
			return i;
	}
	return NULL;
}
void make_bt(int in[], int pre[])
{
	x=6;
	for(i=0;i<6;i++)
	{
		j=search(in,pre[i],x);
		x=j;
		root=newnode(j);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int in[]={4,2,5,1,3,6}, pre[]={1,2,4,5,3,6};
	make_bt(in,pre);


