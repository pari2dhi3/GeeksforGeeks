#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
tree *lca(tree *root, int n1, int n2)
{
	tree *left_lca, *right_lca;
	if(root==NULL)
		return NULL;
	if(root->val==n1 || root->val==n2)
		return root;
	left_lca=lca(root->left,n1,n2);
	right_lca=lca(root->right,n1,n2);
	if(left_lca && right_lca)
		return root;
	return ((left_lca!=NULL) ? left_lca : right_lca);
}
int dist(tree *root, int x, int level, int *num)
{
	if(root==NULL)
		return 0;
	if(root->val==x)
	{
		(*num)=level;
		return (*num);
	}
	return max(dist(root->right,x,level+1,num),dist(root->left,x,level+1,num));
}
int dist1(tree *root, int x)
{
	int level=0, num=0;
	return dist(root,x,level,&num);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root, *ances;
	int distance=0,n1,n2;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->right->left->right=newnode(8);
	cout << "ENTER THE TWO NODES WHOSE DISTANCE YOU WANT TO CALCULATE\n";
	cin >> n1 >> n2;
	ances=lca(root,n1,n2);
	distance=dist1(root,n1)+dist1(root,n2)-2*dist1(root,ances->val);
	cout << "THE DISTANCE BETWEEN THE GIVEN NODES IS : " << distance << endl;
	return 0;
}
