#include<bits/stdc++.h>
using namespace std;
stack<int> sort_stack_util(stack<int> s, int temp)
{
	int temp1;
	if(s.empty()||s.top()>=temp)
	{
		s.push(temp);
		return s;
	}
	else
	{
		temp1=s.top();
		s.pop();
		s=sort_stack_util(s,temp);
	}
	s.push(temp1);
	return s;
}
stack<int> sort_stack(stack<int> s)
{
	int temp;
	if(s.empty())
		return s;
	else
	{
		temp=s.top();
		s.pop();
		s=sort_stack(s);
	}
	return sort_stack_util(s,temp);
}
int main()
{
	stack<int> s;
	int i,size,p;
	cout << "Enter the size and value\n";
	cin >> size;
	for(i=0;i<size;i++)
	{
		cin >> p;
		s.push(p);
	}
	s=sort_stack(s);
	while(!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
	return 0;
}
