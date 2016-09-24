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
bool isisomorphism(tree *root1, tree *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	if(root1->val!=root2->val)
		return false;
	return((isisomorphism(root1->left, root2->left)&&isisomorphism(root1->right, root2->right))||(isisomorphism(root1->left,root2->right)&&isisomorphism(root1->right,root2->left)));
}
int main()
{
	tree *root1=NULL, *root2=NULL;
	root1=newnode(1);
	root1->left=newnode(2);
	root1->right=newnode(3);
	root1->left->left=newnode(4);
	root1->left->right=newnode(5);
	root1->left->right->left=newnode(7);
	root1->left->right->right=newnode(8);
	root1->right->left=newnode(6);

	root2=newnode(1);
	root2->left=newnode(3);
	root2->right=newnode(2);
	root2->left->right=newnode(6);
	root2->right->left=newnode(4);
	root2->right->right=newnode(5);
	root2->right->right->left=newnode(8);
	root2->right->right->right=newnode(7);

	if(isisomorphism(root1,root2)==true)
		cout << "Yes the B-Tree is isomorphism\n";
	else 
		cout << "No the B-Tree is not isomorphism\n";
	return 0;
}





