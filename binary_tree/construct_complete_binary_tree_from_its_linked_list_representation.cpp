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
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void push(ll **head_ref,int data)
{
	ll *node;
	node=(ll *)malloc(sizeof(ll *));
	node->val=data;
	node->next=(*head_ref);
	(*head_ref)=node;
}
void ll_to_bt(ll *head, tree *root)
{
	queue<int> q;
	if(head)
		q.push(head->val);
	else
		return;
	while(!q.empty())
	{
		root->val=q.front();
		root->left=NULL;
		root->right=NULL;
		head=head->next;
		q.pop();
		if(head)
		{
			q.push(head->val);
			root->left->val=head->val;
			head=head->next;
		}
		if(head)
		{
			q.push(head->val);
			root->right->val=head->val;
			head=head->next;
		}
		root=root->left;
	}
	return;
}
void print(tree *root)
{
	if(!root)
		return;
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL;
	ll *head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	ll_to_bt(head,root);
	print(root);
	return 0;
}

