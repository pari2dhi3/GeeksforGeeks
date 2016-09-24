#include<bits/stdc++.h>
using namespace std;
int arr[50], ind=0, c;
string str;
vector<char> vec;
stack<char> sta;
stack<int> stai;
stack<int> aux;
stack<int> act;
typedef struct node
{
	node *next;
	node *prev;
	int val;
}node;
node *mid;
int push(int data)
{
	if(ind<50)
	{
		arr[ind]=data;
		ind++;
		return 0;
	}
	else
		return -1;
}
int pop()
{
	if(ind==0)
		return -1;
	arr[ind-1]=-1;
	ind--;
	return 0;
}
int peek()
{
	if(ind==0)
		return -1;
	cout << "THE TOP ELEMENT IN THE STACK IS : " << arr[ind-1] << endl;
	return 0;
}
void print_array()
{
	int i;
	if(ind==0)
	{
		cout << "STACK IS EMPTY\n";
		return;
	}
	cout << "THE STACK IS : ";
	for(i=0;i<ind;i++)
	{
		cout << arr[i] << " ";
	}
}
int prece(char ch)
{
	if((ch==43)||(ch==45)) 
		return 1;
	if((ch==42)||(ch==47))
		return 2;
	if((ch==94))
		return 3;
	else
		return -1;
}
void infixtopostfix()
{
	stack<char> sta;
	int i;
	for(i=0;i<vec.size();i++)
	{
		if(vec[i]==40)
			sta.push(vec[i]);
		else if(vec[i]==41)
		{
			while(sta.top()!=40)
			{
				cout << sta.top();
				sta.pop();
			}
			sta.pop();
		}
		else if(vec[i]>=97&&vec[i]<=122)
		{
			cout << vec[i];
		}
		else if(vec[i]==42||vec[i]==43||vec[i]==45||vec[i]==47||vec[i]==94)
		{
			if(sta.empty())
				sta.push(vec[i]);
			else if(prece(vec[i])>prece(sta.top()))
			{
				sta.push(vec[i]);
			}
			else
			{
				while(prece(vec[i])>prece(sta.top()))
				{
					cout << sta.top();
					sta.pop();
				}
				sta.push(vec[i]);
			}
		}
	}
	while(!sta.empty())
	{
		cout << sta.top();
		sta.pop();
	}
	return;
}
int evaluate_postfix()
{
	stack<int> sta;
	char op;
	int a,b,ans,i;
	for(i=0;i<vec.size();i++)
	{
		if(vec[i]==42||vec[i]==43||vec[i]==45||vec[i]==47||vec[i]==94)
		{
			op=vec[i];
			b=sta.top();
			sta.pop();
			a=sta.top();
			sta.pop();
			if(vec[i]==42)
				ans=a*b;
			else if(vec[i]==43)
				ans=a+b;
			else if(vec[i]==45)
				ans=a-b;
			else if(vec[i]==47)
				ans=a/b;
			else if(vec[i]==94)
				ans=a^b;
			sta.push(ans);
		}
		else
			sta.push(vec[i]-48);
	}
	ans=sta.top();
	sta.pop();
	return ans;
}
void reverse_string()
{
	stack<int> sta;
	char a;
	cin >> str;
	while(!str.empty())
	{
		a=str[0];
		str.erase(0,1);
		sta.push(a);
	}
	while(!sta.empty())
	{
		str.push_back(sta.top());
		sta.pop();
	}
	return;
}
int balancing()
{
	cin >> str;
	stack<int> sta;
	int i,flag=0;
	for(i=0;i<str.size();i++)
	{
		if(str[i]==91||str[i]==123||str[i]==40)
			sta.push(str[i]);
		else if(str[i]==')')
		{
			if(sta.top()!='(')
			{
				flag=1;
				break;
			}
			else
				sta.pop();
		}
		else if(str[i]==']')
		{
			if(sta.top()!='[')
			{
				flag=1;
				break;
			}
			else
				sta.pop();
		}
		else if(str[i]=='}')
		{
			if(sta.top()!='{')
			{
				flag=1;
				break;
			}
			else
				sta.pop();
		}
	}
	if(flag==0)
		return 1;
	return -1; 
}
void insertatbottom(char item)
{
	char temp;
	if(sta.empty())
		sta.push(item);
	else
	{
		temp=sta.top();
		sta.pop();
		insertatbottom(item);
		sta.push(temp);
	}
	return;
}
void reverse()
{
	char temp;
	if(!sta.empty())
	{
		temp=sta.top();
		sta.pop();
		reverse();
		insertatbottom(temp);
	}
	return;
}
void compare(int item)
{
	int temp;
	if((stai.empty())||(item>=stai.top()))
		stai.push(item);
	else
	{
		temp=stai.top();
		stai.pop();
		compare(item);
		stai.push(temp);
	}
	return;
}
void sort()
{
	int temp;
	if(!stai.empty())
	{
		temp=stai.top();
		stai.pop();
		sort();
		compare(temp);
	}
	return;
}
void splpush()
{
	int p;
	cin >> p;
	if((aux.empty())&&(act.empty()))
	{
		aux.push(p);
		act.push(p);
	}
	else
	{
		act.push(p);
		if(p>aux.top())
			aux.push(aux.top());
		else
			aux.push(p);
	}
	return;
}
void splpop()
{
	if((!aux.empty())&&(!act.empty()))
	{
		aux.pop();
		act.pop();
	}
	else
		cout << "STACK UNDERFLOW\n";
	return;
}
int splgetmin()
{
	if(!aux.empty())
		return aux.top();
	else
		return -1;
}
void splprint()
{
	if(act.empty()&&(aux.empty()))
	{
		cout << "STACK IS EMPTY\n";
		return;
	}
	cout << "THE STACK IS : \n";
	while(!act.empty())
	{
		cout << act.top() << endl;
		act.pop();
	}
	return;
}
int spltop()
{
	if(act.empty())
		return -1;
	return act.top();
}
void dllpush(node **headref, int data)
{
	node *curr;
	curr=(*headref);
	if(curr==NULL)
	{
		curr=(node *)malloc(sizeof(node));
		curr->val=data;
		curr->next=NULL;
		curr->prev=NULL;
		(*headref)=curr;
		mid=curr;
		return;
	}
	curr=(node *)malloc(sizeof(node));
	curr->val=data;
	curr->next=(*headref);
	(*headref)->prev=curr;
	curr->prev=NULL;
	(*headref)=curr;
	c++;
	if(c%2!=0)
		mid=mid->prev;
	return;
}
void dllpop(node **headref)
{
	node *curr;
	curr=(*headref);
	if(curr->next!=NULL)
	{
		(*headref)=curr->next;
		(*headref)->prev=NULL;
		free(curr);
		if((c%2==0)&&(mid->next!=NULL))
			mid=mid->next;
		c--;
		return;
	}
	else
	{
		free(curr);
		cout << "THE STACKK IS EMPTY\n";
		return;
	}
}
void dll_delete_middle()
{
	node *p;
	p=mid;
	if(c%2==0)
		p=mid->prev;
	else 
		p=mid->next;
	if(mid!=NULL)
	{
		mid->prev->next=mid->next;
		mid->next->prev=mid->prev;
		free(mid);
	}
	c--;
	mid=p;
}
void dll_find_middle()
{
	if(mid!=NULL)
	{
		cout << "THE MIDDLE ELEMENT IS : " << mid->val << endl;
		return;
	}
	else
		cout << "TE STACK IS EMPTY\n";
}
void dll_print(node **headref)
{
	node *curr;
	curr=(*headref);
	cout << "THE STACK IN FORM OF DLL IS : " << endl;
	while(curr!=NULL)
	{
		cout << curr->val << endl;
		curr=curr->next;
	}
	return;
}
int length_of_valid_parenthesis()
{
	int max,count,i,flag;
	flag=0;
	max=0;
	count=0;
	for(i=0;i<str.size();i++)
	{
		if(str[i]=='(')
		{
			sta.push(str[i]);
			flag=1;
		}
		else if((str[i]==')')&&(!sta.empty()))
		{
			sta.pop();
			count=count+2;
			flag=1;
		}
		else
			flag=0;
		if(count>max)
			max=count;
		if(flag==0)
			count=0;
	}
	return max;
}
int main()
{
	int ret, data, i, ans, len ,q, j;
	char p;
	node *head=NULL;
	node *mid=NULL;
	cout << "PRESS 0 TO TERMINATE\n";
	cout << "PRESS 1 TO PUSH AN ELEMENT IN A STACK\n";
	cout << "PRESS 2 TO POP AN ELEMENTFROM A STACK\n";
	cout << "PRESS 3 TO PEEK THE TOP ELEMENT OF THE STACK\n";
	cout << "PRESS 4 TO DISPLAY THE STACK IMPLEMENTED BY AN ARRAY\n";
	cout << "PRESS 5 TO CONVERT INFIX TO POSTFIX EQUATION\n";
	cout << "PRESS 6 TO EVALUATE THE POSTFIX EXPRESSION\n";
	cout << "PRESS 7 TO REVERSE A STRING USING STACKS\n";
	cout << "PRESS 8 TO CHECK THE BALANCING OF PARENTHESIS\n";
	cout << "PRESS 9 TO REVERSE THE ELEMENTS IN STACK\n";
	cout << "PRESS 10 TO SORT THE STACK\n";
	cout << "PRESS 11 TO USE SPECIAL STACK OPERATIONS\n";
	cout << "PRESS 12 TO IMPLEMENT STACKS USING DOUBLY LINKED LIST\n";
	cout << "PRESS 13 TO FIND THE MAXIMUM LENGTH OF THE VALID PARENTHESIS\n"; 
	while(true)
	{
		cin >> i;
		if(i==1)
		{
			cout << "ENTER THE DATA TO PUSH IN A STACK\n";
			cin >> data;
			ret=push(data);
			if(ret==-1)
				cout << "STACK OVERFLOW\n";
		}
		if(i==2)
		{
			ret=pop();
			if(ret==-1)
				cout << "STACK UNDERFLOW\n";
		}
		if(i==3)
		{
			ret=peek();
			if(ret==-1)
				cout << "EMPTY STACK\n";
		}
		if(i==4)
		{
			print_array();
			cout << "\n";
		}
		if(i==5)
		{
			cout << "ENTER THE EQUATION TO BE CONVERTED INTO POSTFIX\n";
			while(true)
			{
				cin >> p;
				if(p=='0')
					break;
				else
					vec.push_back(p);
			}
			infixtopostfix();
			vec.clear();
			cout << "\n";
		}
		if(i==6)
		{
			cout << "ENTER THE POSTFIX EXPRESSION\n";
			cin >> str;
			for(i=0;i<str.size();i++)
				vec.push_back(str[i]);
			ans=evaluate_postfix();
			cout << "THE VALUE OF THE EXPRESSION IS: "<< ans << endl;
			vec.clear();
			str.clear();
		}
		if(i==7)
		{
			cout << "ENTER THE STRING TO BE REVERSED\n";
			reverse_string();
			cout << str << endl;
			str.clear();
		}
		if(i==8)
		{
			cout << "ENTER THE EXPRESSION \n";
			ans=balancing();
			if(ans==1)
				cout << "BALANCED\n";
			else if(ans==-1)
				cout << "IMBALANCED\n";
			str.clear();
		}
		if(i==9)
		{
			cout << "ENTER THE ELEMENTS IN THE STACK\n";
			cin >> str;
			for(i=0;i<str.size();i++)
				sta.push(str[i]);
			reverse();
			cout << "THE REVERSE STACK IS : \n";
			while(!sta.empty())
			{
				cout << sta.top() << endl;
				sta.pop();
			}
			str.clear();
		}
		if(i==10)
		{
			cout << "ENTER THE LENGTH AND THE  ELEMENTS IN THE STACK\n";
			cin >> len;
			while(len--)	
			{
				cin >> q;
				stai.push(q);
			}
			sort();
			cout << "THE SORTED STACK IS :\n";
			while(!stai.empty())
			{
				cout << stai.top() << endl;
				stai.pop();
			}
		}
		if(i==11)
		{
			cout << "PRESS 1 TO PUSH AN ELEMENT IN A STACK\n";
			cout << "PRESS 2 TO POP AN ELEMENT FROM THE STACK\n";
			cout << "PRESS 3 TO GET MIN OF THE STACK\n";
			cout << "PRESS 4 TO GET THE TOP OF THE STACK\n";
			cout << "PRESS 5 TO PRINT THE ACTUAL STACK\n";
			cout << "PRESS 0 TO HALT THE PROGRAM\n";
			while(true)
			{
				cin >> j;
				if(j==1)
					splpush();
				if(j==2)
					splpop();
				if(j==3)
				{
					ans=splgetmin();
					if(ans!=-1)
						cout << "THE MIN IS : " << ans << endl;
					else
						cout << "STACK IS EMPTY" << endl;
				}
				if(j==4)
				{
					ans=spltop();
					if(ans==-1)
						cout << "STACK IS EMPTY\n";
					else
						cout << "THE TOP OF THE STACK IS : " << ans << endl;
				}
				if(j==5)
					splprint();
				if(j==0)
					break;
			}
		}
		if(i==12)
		{
			cout << "PRESS 1 TO PUSH AN ELEMENT IN A STACK\n";
			cout << "PRESS 2 TO POP AN ELEMENT FROM THE STACK\n";
			cout << "PRESS 3 TO FIND MIDDLE ELEMENT IN A STACK\n";
			cout << "PRESS 4 TO DELETE MIDDLE ELEMENT IN A STACK\n";
			cout << "PRESS 5 TO PRINT THE ELEMENTS OF THE STACK\n";
			cout << "PRESS 0 TO HALT THE PROGRAM\n";
			while(true)
			{
				cin >> j;
				if(j==1)
				{
					cout << "ENTER THE DATA\n";
					cin >> data;
					dllpush(&head,data);
				}
				if(j==2)
					dllpop(&head);
				if(j==3)
					dll_find_middle();
				if(j==4)
					dll_delete_middle();
				if(j==5)
					dll_print(&head);
				if(j==0)
					break;
			}
		}
		if(i==13)
		{
			cout << "ENTER THE STRING TO FIND THE LENGTH OF THE VALID PARENTHESIS OPERATION\n";
			cin >> str;
			ans=length_of_valid_parenthesis();
			cout << "THE LENGTH OF VALID PARENTHESIS IS : " << ans << endl;
			str.clear();
		}
	}
	return 0;
}
