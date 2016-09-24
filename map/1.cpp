#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	map<string,int> mymap;
	map<string,int>::iterator it;
	vector<string> v;
	v.push_back("111000");
	v.push_back("110011");
	v.push_back("101010");
	v.push_back("000111");
	v.push_back("101010");
	v.push_back("111000");
	for(i=0;i<v.size();i++)
	{
		mymap[v[i]]=i;
	}
	for(it=mymap.begin();it!=mymap.end();++it)
	{
		cout << it->first << "=>" << it->second << endl;
	}
	cout << endl;
	return 0;
}
