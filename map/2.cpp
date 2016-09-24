#include<bits/stdc++.h>
using namespace std;
int main()
{
	string b, a;
	cin >> b;
	cin >> a;
	int i,flag=0,size1,size2;
	map<char,int> mymap;
	map<char,int>::iterator it;
	size1=a.length();
	size2=b.length();
	for(i=0;i<size1;i++)
	{
		char c=a[i];
		for(c='a';c<='z';c++)
		{
			if(c<=0)
				mymap[c]=1;
			else
				mymap[c]++;
		}
	}
	for(i=0;i<size2;i++)
	{
		char c=b[i];
		for(c='a';c<='z';c++)
		{
			if(c<=0)
				mymap[c]=1;
			else
				mymap[c]--;
		}
	
	}
	if(flag==0)
	{
		for(it=mymap.begin();it!=mymap.end();it++)
		{
			if(it->second!=0)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
		cout << "two strings are not anagram\n";
	else
		cout << "Hurray!! They are Anagram and I LOVE SACHIN!! :* \n";
	return 0;
	//PS : Stop Blushing! ;)
}

