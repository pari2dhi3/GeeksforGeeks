#include<bits/stdc++.h>
using namespace std;
void next_greater(vector<int> &vec, int size)
{
	int i;
	stack<int> s;
	vector<int> res;
	if(size==0)
		return;
	s.push(vec[0]);
	for(i=1;i<size;i++)
	{
		if(s.empty()==false)
		{
			while(vec[i]>s.top())
			{
				res.push_back(vec[i]);
				s.pop();
				if(s.empty())
					break;
			}
		}
		s.push(vec[i]);
	}
	while(!s.empty())
	{
		res.push_back(-1);
		s.pop();
	}
	cout << "The next greater elements are : \n";
	for(i=0;i<res.size();i++)
		cout << res[i] << " ";
	cout << endl;
	return;
}
int main()
{
	cout << "Enter the size and value in the array\n ";
	int i,size,p;
	vector<int> vec;
	cin >> size;
	for(i=0;i<size;i++)
	{
		cin >> p;
		vec.push_back(p);
	}
	next_greater(vec,size);
	return 0;
}

