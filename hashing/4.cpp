//Print a Binary Tree in Vertical Order | Set 2 (Hashmap based Method)
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	int key;
	tree *left;
	tree *right;
}tree;
tree * newnode(int val)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->key=val;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void vertical_order_util(tree* root, map<int, vector<int> > &m, int hd)
{
	if(root==NULL)
		return;
	m[hd].push_back(root->key);
	vertical_order_util(root->left,m,hd-1);
	vertical_order_util(root->right,m,hd+1);
	return;
}
void vertical_order(tree *root, map<int, vector<int> > &m)
{
	int hd=0,i;
	vertical_order_util(root,m,hd);
	map<int, vector<int> >::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		for(i=0;i<it->second.size();i++)
			cout << it->second[i] << "   ";
		cout << endl;
	}
	return;
}
int main()
{
	tree *root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->right->left->right=newnode(8);
	root->right->right->right=newnode(9);
	
	map<int, vector<int> > m;
	vertical_order(root,m);
	return 0;
}
