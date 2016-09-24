//Given an array A[] and a number x, check for pair in A[] with sum as x
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout << "Enter the size and elements of array: \n";
	int n,i,p,x;
	vector<int> arr;
	map<int,bool> m;
	map<int,bool>::iterator it;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> p;
		arr.push_back(p);
		m[p]=false;
	}
	cout << "Enter the sum : \n";
	cin >> x;
	for(i=0;i<arr.size();i++)
	{
		it=m.find(x-arr[i]);
		if(it!=m.end())
			cout << "Sum of " << it->first << " and " << arr[i] << " = " << x << endl;
	}
	return 0;
}
		

