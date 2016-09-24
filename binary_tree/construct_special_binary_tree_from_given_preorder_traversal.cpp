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
tree * build_tree1(int pre[], char preLN[], int *ind, int n)
{
	tree *node;
	int index=*ind;
	if(index==n)
		return NULL;
	node=newnode(pre[index]);
	*ind=*ind+1;
	if(preLN[index]=='N')
	{
		node->left=build_tree1(pre,preLN,ind,n);
		node->right=build_tree1(pre,preLN,ind,n);
	}
	return node;
}
tree * build_tree(int pre[], char preLN[], int n)
{
	int index=0;
	return build_tree1(pre,preLN,&index,n);
}
void print_preorder(tree *node)
{
	if(node==NULL)
		return;
	cout << node->val << " ";
	print_preorder(node->left);
	print_preorder(node->right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int pre[5]={10,30,20,5,15};
	char preLN[5]={'N', 'N', 'L', 'L', 'L'};
	root=build_tree(pre,preLN,5);
	cout << "THE PREORDER TRAVERSAL IS : ";
	print_preorder(root);
	cout << endl;
	return 0;
}
