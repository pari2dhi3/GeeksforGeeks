//Print nodes between two given level numbers of a binary tree//
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
queue<int> q;
void levelorder(tree *root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
	{
		q.push(root->val);
		return;
	}
	else if(level>1)
	{
		levelorder(root->left,level-1);
		levelorder(root->right,level-1);
	}
	return;
}
void fxn(tree *root, int l1, int l2)
{
	int i;
	for(i=l1;i<=l2;i++)
		levelorder(root,i);
	cout << "THE NODE BETWEEN " << l1 << " AND " << l2 << " ARE  : ";
	while(!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int l1,l2;
	root=newnode(20);
	root->left=newnode(8);
	root->right=newnode(22);
	root->left->left=newnode(4);
	root->left->right=newnode(12);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);
	cout << "ENTER 2 LEVELS\n";
	cin >> l1 >> l2;
	fxn(root,l1,l2);
	return 0;
}
