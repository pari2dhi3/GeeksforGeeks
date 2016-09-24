//Check if given array can represent preorder traversal of Binary Search Tree//
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
bool check(int arr[], int size)
{
	stack<int> s;
	int root=INT_MIN, i;
	for(i=0;i<size;i++)
	{
		if(arr[i]<root)
			return false;
		while(!s.empty() && s.top()<arr[i])
		{
			root=s.top();
			s.pop();
		}
		s.push(arr[i]);
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int arr1[]={40,30,35,80,100}, arr2[]={40,30,35,20,80,100};
	if(check(arr1,5))
		cout << "ARRAY1 REPRESENT PREORDER TRAVERSAL OF A B-TREE\n";
	else
		cout << "ARRAY1 DOES NOT REPRESENT PREORDER TRAVERSAL OF A B-TREE\n";
	if(check(arr2,6))
		cout << "ARRAY2 REPRESENT PREORDER TRAVERSAL OF A B-TREE\n";
	else
		cout << "ARRAY2  DOES NOT REPRESENT PREORDER TRAVERSAL OF A B-TREE\n";
	return 0;
}
