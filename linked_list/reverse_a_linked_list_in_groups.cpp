#include<bits/stdc++.h>
using namespace std;
typedef struct ll
{
	ll *next;
	ll *prev;
	int key;
}ll;
void reverse(ll **head_ref, int k)
{
	int grp_size=k;
	ll *prev=NULL, *curr, *next;
	curr=(*head_ref);
	while(1)
	{
		while((grp_size--)&&(curr!=NULL))
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		end1=prev;
		start=curr;
		prev=NULL;
		while((grp_size--)&&curr!=NULL)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		end2=prev;
		end2->next=end1;
	}
	

	}


		int main()
		{
			ll *head=NULL;
			int k;
			push(&head,1);
			push(&head,2);
			push(&head,3);
			push(&head,4);
			push(&head,5);
			push(&head,6);
			push(&head,7);
			push(&head,8);

			cout << "Enter the group size\n";
			cin >> k;
			cout << "The linked list is : \n";
			print(&head)
				reverse(&head,k);
			cout << "The modified linked list is : \n";
			print(&head);
			return 0;
		}


