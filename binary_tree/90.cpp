//Convert Binary Tree into Threaded Binary Tree//
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
	bool isthreaded;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	node->isthreaded=false;
	return node;
}
queue<tree *>q;
void inorder(tree *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	q.push(root);
	inorder(root->right);
	return;
}
void inorder1(tree *root)
{
	if(root==NULL)
		return;
	if((root->left==NULL)&&(root->right==NULL)&&(!q.empty()))
	{	
		while((root->val!=q.front()->val)&&(!q.empty()))
			q.pop();
		q.pop();
		root->right=q.front();
		root->isthreaded=true;
		return;
	}
	inorder1(root->left);
	inorder1(root->right);
	return;
}
tree *leftmost(tree *root)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->isthreaded)
		return root;
	else
		return leftmost(root->left);
}
void threaded(tree *root)
{
	tree *curr;
	inorder(root);
	inorder1(root);
	if(root==NULL)
		return;
	curr=leftmost(root);
	while(curr!=NULL)
	{
		cout << curr->val << " ";
		if(curr->isthreaded)
			curr=curr->right;
		else
			curr=leftmost(curr->right);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(6);
	root->left=newnode(3);
	root->right=newnode(8);
	root->left->left=newnode(1);
	root->left->right=newnode(5);
	root->right->left=newnode(7);
	root->right->right=newnode(11);
	root->right->right->left=newnode(9);
	root->right->right->right=newnode(13);
	cout << "THE INORDER TRAVERSAL OF THE MODIFIED TREE IS : ";
	threaded(root);
	cout << endl;
	return 0;
}

