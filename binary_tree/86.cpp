//find whether one tree is subtree of another or not set-2//
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
void inorder(tree *root, int **ptr)
{
	if(root==NULL)
		return;
	inorder(root->left,ptr);
	(**ptr)=root->val;
	(*ptr)=(*ptr)+1;
	inorder(root->right,ptr);
	return;
}
void preorder(tree *root, int **ptr)
{
	if(root==NULL)
		return;
	(**ptr)=root->val;
	(*ptr)=(*ptr)+1;
	preorder(root->left,(ptr));
	preorder(root->right,(ptr));
	return;
}
bool is_sub_string(int *ptr1, int *ptr2)
{
	int flag=0;
	while((*ptr1)!=0 && (*ptr2)!=0)
	{
		if((*ptr1)==(*ptr2))
		{
			flag=1;
			ptr1++;
			ptr2++;
		}
		else if((*ptr1)!=(*ptr2) && flag==0)
			ptr1++;
		else if((*ptr1)!=(*ptr2) && flag==1)
			return false;
	}
	return true;
}
bool check(tree *root1, tree *root2)
{
	int in1[10]={0}, in2[5]={0}, pre1[10]={0}, pre2[5]={0}, *ptr1, *ptr2, *ptr3, *ptr4;
	ptr1=&in1[0];
	ptr2=&in2[0];
	ptr3=&pre1[0];
	ptr4=&pre2[0];
	inorder(root1, &ptr1);
	inorder(root2, &ptr2);
	preorder(root1, &ptr3);
	preorder(root2, &ptr4);
	return (is_sub_string(&in1[0], &in2[0]) && is_sub_string(&pre1[0],&pre2[0]));
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root1,*root2;
	root1=newnode(1);
	root1->left=newnode(2);
	root1->right=newnode(3);
	root1->left->left=newnode(4);
	root1->left->right=newnode(5);
	root1->right->left=newnode(6);
	root1->right->right=newnode(7);

	root2=newnode(2);
	root2->left=newnode(4);
	root2->right=newnode(5);
	if(check(root1,root2))
		cout << "ONE TREE IS A SUBTREE OF ANOTHER TREE\n";
	else
		cout << "THE TREE IS NOT A SUBTREE OF ANOTHER TREE\n";
	return 0;
}
