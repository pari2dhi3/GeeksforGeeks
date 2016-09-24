#include<bits/stdc++.h>
using namespace std;
void heapsort(vector<int> &a)
{
	priority_queue<int, vector<int>, greater<int> > heap;
	int i;
	for(i=0;i<a.size();i++)
		heap.push(a[i]);
	for(i=0;i<a.size();i++)
	{
		a[i]=heap.top();
		heap.pop();
	}
}
int main()
{
	vector<int> a;
	int i,p;
	cout << "enter 6 numbers\n";
	for(i=0;i<6;i++)
	{
		cin >> p;
		a.push_back(p);
	}
	heapsort(a);
	for(i=0;i<a.size();i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
