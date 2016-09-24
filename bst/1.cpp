//Binary Search Tree | Set 1 (Search and Insertion)//
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
void print(tree* root)
{
	if(root==NULL)
		return;
	print(root->left);
	cout << root->val << " ";
	print(root->right);
	return;
}
bool find(tree* root, int key)
{
	if(root==NULL)
		return false;
	if(root->val==key)
		return true;
	else if(root->val>key)
		return find(root->left,key);
	else if(root->val<key)
		return find(root->right,key);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int key;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);

	print(root);
	cout << endl;
	cout << "ENTER THE KEY TO BE SEARCHED\n";
	cin >> key;
	if(find(root,key))
		cout << "FOUND\n";
	else
		cout << "NOT FOUND\n";
	return 0;
}

