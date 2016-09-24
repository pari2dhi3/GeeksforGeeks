//Sorted Linked List to Balanced BST
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
typedef struct ll
{
	ll *next;
	int val;
}ll;
tree* newnode_tree(int data)
{
	tree* node;
	node=(tree* )malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
ll* newnode_ll(ll **node_ref,int data)
{
	ll *node;
	if(node==NULL)
	{
		node=(ll *)malloc(sizeof(ll));
		node->next=NULL;
		node->val=data;
		(*node_ref)=node;
		return (*node_ref);
	}
	node=(ll *)malloc(sizeof(ll));
	node->next=(*node_ref);
	node->val=data;
	(*node_ref)=node;
	return (*node_ref);
}
tree* build_bst(tree* &root,ll *start,ll *end)
{
	if(start==end)
		return NULL;
	ll *slow, *fast;
	slow=start;
	fast=start;
	if(root==NULL)
	{
		while(fast!=end && fast->next!=end)
		{
			slow=slow->next;
			if(fast->next!=end)
				fast=fast->next->next;
		}
		root=newnode_tree(slow->val);
	}
	root->left=build_bst(root->left,start,slow);
	root->right=build_bst(root->right,slow->next,end);
	return root;
}
void print(tree* root)
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
	tree *root;
	ll *node;
	node=newnode_ll(&node,5);
	node=newnode_ll(&node,4);
	node=newnode_ll(&node,3);
	node=newnode_ll(&node,2);
	node=newnode_ll(&node,1);
	ll *start, *end;
	start=node;
	end=node;
	while(end->next!=NULL)
	{
		start=start->next;
		if(end->next!=NULL)
			end=end->next->next;
	}
	root=build_bst(root,node,end);
	print(root);
	cout << endl;
	return 0;
}
