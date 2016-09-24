//In-place conversion of Sorted DLL to Balanced BST
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
bool find_pair(tree *roo1, tree *root2, stack<int> &s1, stack<nt> &s2, int *sum)
{
	while(root1!=NULL && root2!=NULL)
	{
		s1.push(root1);
		s2.push(root2);
	}
	while(root1!=NULL)
	{
		s1.push(root1);
		root1=roo1->left;
	}
	while(roo2!=NULL)
	{
		s2.push(root2);
		root2=root2->left;
	}
	if(s1.top()->val+s2.top()->val==(*sum))
		return true;
	if(s1.top()->val+s2.top()->val>(*sum))
	{
		tree *temp;
		temp=s1.front();
		s1.pop();
		find_pair(temp->right,root2,s1,s2,sum);


int main()
{
	ios_base::sync_with_stdio(false);
	tree* root=NULL;
	int sum;
	stack<tree *> s1, s2;
	root=insert(root,15);
	insert(root,10);
	insert(root,20);
	insert(root,8);
	insert(root,12);
	insert(root,16);
	insert(root,25);
	cin >> sum;
	if(find_pair(root,root,s1,s2,&sum))
		cout << "FOUNTD\n";
	else
		cout << "NOT FOUND\n";
	return 0;
}
