//Write a program to print all permutations of a given string
#include<bits/stdc++.h>
using namespace std;
void print(string s, int l, int r)
{
	int i;
	if(l==r)
	{
		cout << s << endl;
		return;
	}
	for(i=l;i<=r;i++)
	{
		swap(s[l],s[i]);
		print(s,l+1,r);
		swap(s[l],s[i]);
	}
	return;
}
int main()
{
	string s;
	cin >> s;
	int size=s.length();
	print(s,0,size-1);
	return 0;
}
