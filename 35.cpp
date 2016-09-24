//K’th Largest Element in BST when modification to BST is not allowed
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
void k_largest(tree* root, stack<int> &s)
{
	if(root==NULL)
		return;
	k_largest(root->left,s);
	s.push(root->val);	
	k_largest(root->right,s);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int k,temp,w;
	stack<int> s;
	root=insert(root,20);
	insert(root,8);
	insert(root,22);
	insert(root,4);
	insert(root,12);
	insert(root,10);
	insert(root,14);
	cin >> k;
	w=k;
	k_largest(root,s);
	while(k)
	{
		temp=s.top();
		s.pop();
		k--;
	}
	cout << w << "th LARGEST IS : " << temp << endl;
	return 0;
}
