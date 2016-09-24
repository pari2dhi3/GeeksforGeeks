//Print Common Nodes in Two Binary Search Trees
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
void inorder(tree* &root, vector<int> &v)
{
	if(root==NULL)
		return;
	inorder(root->left,v);
	v.push_back(root->val);
	inorder(root->right,v);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root1=NULL, *root2=NULL;
	vector<int> v1, v2;
	int i=0, j=0, size=0;
	root1=insert(root1,5);
	insert(root1,1);
	insert(root1,10);
	insert(root1,0);
	insert(root1,4);
	insert(root1,7);
	insert(root1,9);

	root2=insert(root2,10);
	insert(root2,7);
	insert(root2,20);
	insert(root2,4);
	insert(root2,9);
	inorder(root1,v1);
	inorder(root2,v2);
	if(v1.size()<v2.size())
		size=v2.size();
	else
		size=v1.size();
	cout << "COMMON ELEMENTS ARE : ";
	for(i=0;i<size;)
	{
		if(v1[i]<v2[j])
			i++;
		else if(v1[i]>v2[j])
			j++;
		else if(v1[i]==v2[j])
		{
			cout << v1[i] << " ";
			i++;
			j++;
		}
	}
	cout << endl;
	return 0;
}
