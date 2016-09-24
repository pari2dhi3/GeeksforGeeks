//Connect n ropes with minimum cost
#include<bits/stdc++.h>
using namespace std;
void heapsort(vector<int> &a)
{
	int i, size;
	size=a.size();
	priority_queue<int, vector<int>, greater<int> >heap;
	for(i=0;i<size;i++)
		heap.push(a[i]);
	for(i=0;i<size;i++)
	{
		a[i]=heap.top();
		heap.pop();
	}
	return;
}
int main()
{
	int sum,i,k=0;
	vector<int> a;
	vector<int> supersum;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(6);
	heapsort(a);
	sum=a[0];
	for(i=1;i<a.size();i++)
	{
		sum+=a[i];
		supersum.push_back(sum);
	}
	while(!supersum.empty())
	{
		k+=supersum.front();
		supersum.erase(supersum.begin());
	}
	cout << "cost is : " << k << endl;
	return 0;
}


