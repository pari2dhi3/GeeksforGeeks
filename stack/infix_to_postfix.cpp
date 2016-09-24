#include<bits/stdc++.h>
using namespace std;
int prec(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}
int main()
{
	int i;
	string str;
	string vec;
	stack<char> s;
	cout << "Enter the expression\n";
	cin >> str;
	for(i=0;i<str.length();i++)
	{
		if(str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-' || str[i]=='^')
		{
			if(s.empty()||prec(str[i])>=prec(s.top()))
				s.push(str[i]);
			else
			{
				while(!(s.empty()) && prec(str[i])<prec(s.top()))
				{
					vec.push_back(s.top());
					s.pop();
				}
				s.push(str[i]);
			}
		}
		else if(str[i]=='(')
			s.push(str[i]);
		else if(str[i]==')')
		{
			while(!(s.empty()) && s.top()!='(')
			{
				vec.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else
			vec.push_back(str[i]);
	}
	while(!s.empty())
	{
		vec.push_back(s.top());
		s.pop();
	}
	for(i=0;i<vec.size();i++)
		cout << vec[i];
	cout << endl;
	return 0;
}

