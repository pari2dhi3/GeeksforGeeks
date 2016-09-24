#include<bits/stdc++.h>
using namespace std;
bool findanagram(string a, string b)//correct,checked on leetcode
{
	map<char,int> hash;
	int i,n=a.length();
	for(i=0;i<n;i++)
	{
		if(hash.count(a[i]))
			hash[a[i]]++;
		else
			hash[a[i]]=1;
	}
	n=b.length();
	for(i=0;i<n;i++)
	{
		if(hash.count(b[i]))
			hash[b[i]]--;
		else
			return false;
	}
	map<char,int>::iterator it=hash.begin();
	for(;it!=hash.end();it++)
	{
		if(it->second!=0)
			return false;
	}
	return true;
}
vector<string> findlist( vector<string> list)
{
	int i,j,n=list.size(),start=0;
	vector<string> ans(n);
	if(n==0)
		return ans;
	vector<bool> iscounted(n,false);
	for(i=0;i<n;i++)
	{
		if(!iscounted[i])
		{
			for(j=i+1;j<n;j++)
			{
				if(!iscounted[j])
				{
					if(findanagram(list[i],list[j]))
					{
						iscounted[j]=true;
					}
				}
			}
			iscounted[i]=true;
			ans[start]=list[i];
			start++;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	vector<string> a,b;
	int i;
	a.push_back("car");
	a.push_back("tool");
	a.push_back("arc");
	a.push_back("loot");
	a.push_back("box");
	b=findlist(a);
	for(i=0;i<b.size();i++)
		cout << b[i] << endl;
	return 0;
}
