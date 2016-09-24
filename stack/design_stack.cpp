#include<bits/stdc++.h>
using namespace std;
typedef struct dll
{
	dll *next;
	dll *prev;
	int key;
}dll;
void push(dll **head_ref, int a, dll *&mid, int &len)
{
	dll *node;
	node=(dll *)malloc(sizeof(dll));
	node->next=NULL;
	node->prev=NULL;
	node->key=a;
	if(*(head_ref)!=NULL)
		node->next=(*head_ref);
	(*head_ref)=node;
	len++;
	if(mid==NULL)
		mid=node;
	else if(len%2!=0)
		mid=mid->prev;
	return;
}
void pop(dll **head_ref, int &len, dll *&mid)
{
	dll *curr;
	curr=(*head_ref);
	if(curr==NULL)
		return;
	else
	{
		(*head_ref)=(*head_ref)->next;
		free(curr);
		len--;
		return;
	}
}
void del_middle(dll *&mid, int &len)
{
	dll *temp;
	temp=mid;
	if(len==1)
	{
		free(mid);
		return;
	}
	else if(len%2==0)
	{
		mid=mid->prev;
		free(temp);
		len--;
	}
	else
	{
		mid=mid->next;
		free(temp);
		len--;
	}
	return;
}
void print(dll **head_ref)
{
	dll *curr;
	curr=(*head_ref);
	cout << "The Stack is : ";
	while((curr)!=NULL)
	{
		cout << curr->key << "  ";
		curr=curr->next;
	}
	cout << endl;
	return;
}
int main()
{
	int ops,ele,len=0;
	dll *head=NULL, *mid=NULL;
	cout << "Enter 1 to push a number in a stack\n";
	cout << "Enter 2 to pop a number from a stack\n";
	cout << "Enter 3 to find the middle element in a stack\n";
	cout << "Enter 4 to delete the middle element in a stack\n";
	cout << "Enter -1 to exit the program\n";
	while(1)
	{
		cin >> ops;
		if(ops==1)
		{
			cout << "Enter the element to push\n";
			cin >> ele;
			push(&head,ele,mid,len);
			//cout << "middle is  : " << mid->key << endl;
			print(&head);
		}
		else if(ops==2)
		{
			pop(&head, len, mid);
			print(&head);
		}
		else if(ops==3)
		{
			cout << "Middle element is : " << mid->key << endl;
		}
		else if(ops==4)
		{
			del_middle(mid, len);
			print(&head);
		}
		else if(ops==-1)
			break;
	}
	return 0;
}


