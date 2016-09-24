//k largest(or smallest) elements in an array | added Min Heap method
#include<bits/stdc++.h>
using namespace std;
void heapsort(vector<int> &v)
{
	int i;
	priority_queue< int, vector<int>, less<int> > heap;
	for(i=0;i<v.size();i++)
		heap.push(v[i]);
	for(i=0;i<v.size();i++)
	{
		v[i]=heap.top();
		heap.pop();
	}
	return;
}
int main()
{
	int k,i;
	vector<int> v(7);
	v.push_back(1);
	v.push_back(23);
	v.push_back(12);
	v.push_back(9);
	v.push_back(30);
	v.push_back(2);
	v.push_back(50);
	heapsort(v);
	cin >> k;
	for(i=0;i<k;i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}
