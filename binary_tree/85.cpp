//check whether that given 2 nodes are cousins or not//
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
	node->left==NULL;
	node->right==NULL;
	node->val=data;
	return node;
}
int find(tree *root, int num, tree **ptr, int level)
{
	if(root==NULL)
		return 0;
	if(root->val==num)
	{
		(*ptr)=root;
		return level;
	}
	return max(find(root->right,num,ptr,level+1),find(root->left,num,ptr,level+1));
}
bool find_next(tree *root, tree **ptr1, tree **ptr2)
{
	if(root==NULL)
		return true;
	if((root->left==(*ptr1)&&root->right==(*ptr2))||(root->left==(*ptr2)&&root->right==(*ptr1)))
		return false;
	return (find_next(root->left,ptr1,ptr2)&&find_next(root->right,ptr1,ptr2));
}
bool check(tree *root, int n1, int n2)
{
	tree *ptr1=NULL, *ptr2=NULL;
	int l1,l2,flag;
	l1=find(root,n1,&ptr1,1);
	l2=find(root,n2,&ptr2,1);
	if(l1==l2)
		return (find_next(root,&ptr1,&ptr2));
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int n1, n2;
	root=newnode(6);
	root->left=newnode(3);
	root->right=newnode(5);
	root->left->left=newnode(7);
	root->left->right=newnode(8);
	root->right->left=newnode(1);
	root->right->right=newnode(4);
	cout << "ENTER THE TWO NODES TO CHECK WHETHER THEY ARE COUSINS OR NOT" << endl;
	cin >> n1 >> n2;
	if(check(root,n1,n2))
		cout << "YES THEY'RE COUSINS\n";
	else
		cout << "THEY'RE NOT COUSINS\n";
	return 0;
}
