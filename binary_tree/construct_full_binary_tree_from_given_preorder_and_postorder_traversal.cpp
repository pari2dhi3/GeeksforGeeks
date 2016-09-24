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
tree * get_fbt1(int pre[], int post[], int *preind, int l, int h, int size)
{
	int i;
	tree *node;
	if((l>h)||(*preind>=size))
		return NULL;
	node=newnode(pre[*preind]);
	*preind=*preind+1;
	if(l==h)
		return node;
	for(i=l;i<=h;i++)
	{
		if(pre[*preind]==post[i])
			break;
	}
	if(i<=h)
	{
		node->left=get_fbt1(pre,post,preind,l,i,size);
		node->right=get_fbt1(pre,post,preind,i+1,h,size);
	}
	return node;
}
tree * get_fbt(int pre[], int post[], int size)
{
	int preindex=0;
	return get_fbt1(pre,post,&preindex,0,size-1,size);
}
void print(tree *node)
{
	if(node==NULL)
		return;
	print(node->left);
	cout << node->val << " ";
	print(node->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int pre[9]={1,2,4,8,9,5,3,6,7}, post[9]={8,9,4,5,2,6,7,3,1};
	root=get_fbt(pre,post,9);
	cout << "The inorder tree traversal is : ";
	print(root);
	cout << endl;
	return 0;
}
