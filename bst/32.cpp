//Binary Tree to Binary Search Tree Conversion
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
void inorder(tree* &root, vector<int> &temp)
{
	if(root==NULL)
		return;
	inorder(root->left,temp);
	temp.push_back(root->val);
	inorder(root->right,temp);
	return;
}
void inorder1(tree* &root, vector<int> &temp)
{
	if(root==NULL)
		return;
	inorder1(root->left,temp);
	root->val=temp.front();
	temp.erase(temp.begin());
	inorder1(root->right,temp);
	return;
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
	tree* root=NULL;
	vector<int> temp;
	root=newnode(10);
	root->left=newnode(2);
	root->right=newnode(7);
	root->left->left=newnode(8);
	root->left->right=newnode(4);
	inorder(root,temp);
	sort(temp.begin(),temp.begin()+5);
	inorder1(root,temp);
	print(root);
	cout << endl;
	return 0;
}
