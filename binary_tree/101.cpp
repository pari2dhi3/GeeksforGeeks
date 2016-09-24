//Remove nodes on root to leaf paths of length < k//
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
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
tree *modify1(tree *root, int k, int level)
{
	if(root==NULL)
		return NULL;
	root->left=modify1(root->left,k,level+1);
	root->right=modify1(root->right,k,level+1);
	if(root->left==NULL && root->right==NULL)
	{
		if(level<k)
		{
			delete(root);
			return NULL;
		}
	}
	return root;
}
tree *modify(tree *root, int k)
{
	int level=1;
	return modify1(root,k,level);
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
	tree *root;
	int k;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->right=newnode(6);
	root->left->left->left=newnode(7);
	root->right->right->left=newnode(8);
	cout << "ENTER THE VALUE OF K\n";
	cin >> k;
	root=modify(root,k);
	cout << "INORDER TRAVERSAL OF MODIFIED TREE IS : ";
	print(root);
	cout << endl;
	return 0;
}
