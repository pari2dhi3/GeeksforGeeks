//remove duplicates from a vector
#include<bits/stdc++.h>
using namespace std;
void remove(vector<int> &a)
{
	vector<int>::iterator it;
	sort(a.begin(), a.end());
	for(it=a.begin();it!=a.end();it++)
	{
		if(*it==(*(it+1)))
			a.erase(it);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	vector<int> a;
	int i;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	a.push_back(10);
	a.push_back(20);
	remove(a);
	for(i=0;i<a.size();i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

