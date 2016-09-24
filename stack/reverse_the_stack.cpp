#include<bits/stdc++.h>
using namespace std;
stack<int> push_at_bottom(stack<int> s, int temp)
{
	int temp1;
	if(s.empty())
	{
		s.push(temp);
		return s;
	}
	else
	{
		temp1=s.top();
		s.pop();
		s=push_at_bottom(s,temp);
	}
	s.push(temp1);
	return s;
}
stack<int> reverse(stack<int> s)
{
	int temp;
	if(s.empty())
		return s;
	if(!s.empty())
	{
		temp=s.top();
		s.pop();
		s=reverse(s);
	}
	return push_at_bottom(s,temp);
}
int main()
{
	int size,i,p;
	stack<int> s;
	cout << "Enter the size and  values in the stack\n";
	cin >> size;
	for(i=0;i<size;i++)
	{
		cin >> p;
		s.push(p);
	}
	s=reverse(s);
	while(!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
	return 0;
}
