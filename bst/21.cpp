//Find if there is a triplet in a Balanced BST that adds to zero
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
void merge(tree* root1, tree* root2, stack<tree *> &s1, stack<tree *> &s2)
{
	if(root1==NULL && root2==NULL)
		return;
	if(root1==NULL||root2==NULL)
		return;
	if(root1 && root2)
	{
		s1.push(root1)

}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root1=NULL, root2=NULL;
	int key;
	stack<tree *> s1, s2;
	root1=insert(root1,8);
	insert(root1,2);
	insert(root1,1);
	insert(root1,10);
	
	root2=insert(root2,5);
	insert(root2,3);
	insert(root2,0);

	v=merge(root1,root2,s1,s2);
	
