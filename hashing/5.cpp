//Find whether an array is subset of another array | Added Method 3
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n1,n2,p,flag=0;
	vector<int> arr1;
	vector<int> arr2;
	map<int,bool> m;
	map<int,bool>::iterator it;
	cout << "Enter array 1 size and its values : \n";
	cin >> n1;
	for(i=0;i<n1;i++)
	{
		cin >> p;
		arr1.push_back(p);
	}
	cout << "Enter array2 size and its values : \n";
	cin >> n2;
	for(i=0;i<n2;i++)
	{
		cin >> p;
		arr2.push_back(p);
	}
	for(i=0;i<arr1.size();i++)
		m[arr1[i]]=false;
	for(i=0;i<arr2.size();i++)
	{
		it=m.find(arr2[i]);
		if(it==m.end())
		{
			flag=1;
			break;
		}
		else
			it->second=true;
	}
	if(flag==1)
		cout << "Arr2 is not a subset of Arr1\n";
	else
		cout << "Arr2 is a subset of Arr1\n";
	return 0;
}
	
