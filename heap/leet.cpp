#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	cin >> n;
	int heapsort(vector<int> &v)

	{

		priority_queue<int, vector<int>, greater<int> >heap;

		int i, size;

		size=v.size();

		for(i=0;i<size;i++)

			heap.push(v[i]);

		return heap.top();

	}

	int nthSuperUglyNumber(int n, vector<int>& primes) 

	{

		int i,j,value,size;

		size=primes.size();

		vector< vector<int> > a;

		for(i=0;i<size;i++)

			a[i].push_back(1);

		for(i=0;i<n;i++)

		{

			vector<int> v;

			for(j=0;j<size;j++)

				v.push_back(a[j][0]);

			value=heapsort(v);

			for(j=0;j<size;j++)

			{

				if(value==a[j][0])

					a[j].erase(a[j].begin());

				a[j].push_back(value*primes[j]);

			}

		}

		return value;

	}
