//Binary heap basic functions
#include<bits/stdc++.h>
using namespace std;
void swap(int* x, int* y)
{
	int temp;
	temp=(*x);
	(*x)=(*y);
	(*y)=temp;
}
void bubble_up(vector<int> &a)
{
	int i,p;
	i=(a.size()-1);
	p=(i-1)/2;
	while(p>=0)
	{
		if(a[i]<a[p])
			swap(&a[i],&a[p]);
		else
			return;
		i=p;
		p=(i-1)/2;
	}
	return;
}
void bubble_down(vector<int> &a, int p)
{
	int min;
	int l=2*p+1;
	int r=2*p+2;
	min=p;
	if(l>=(a.size()-1))
		return;
	if(a[min]>a[l])
		min=l;
	if(a[min]>a[r])
		min=r;
	if(min!=p)
	{
		swap(&a[min],&a[p]);
		bubble_down(a,min);
	}
	return;
}
void insert(vector<int> &a, int k)
{
	a.push_back(k);
	bubble_up(a);
	return;
}
void delete_min(vector<int> &a)
{
	int temp,size;
	if(a.size()==0)
		return;
	size=a.size();
	a[0]=a[size-1];
	a.pop_back();
	bubble_down(a,0);
	return;
}
int find_min(vector<int> &a)
{
	if(a.empty())
		return INT_MIN;
	return a[0];
}
void heapify(vector<int> &v)
{
	int size,i;
	size=v.size();
	if(size==0)
		return;
	for(i=size-1;i>=0;i--)
		bubble_down(v,i);
}
int main()
{
	vector<int> a;
	int i,k,j,flag=0;
	cout << "1 to insert in Binary Heap\n";
	cout << "2 to delete min\n";
	cout << "3 to find min\n";
	cout << "4 to convert random array in a heap\n";
	while(1)
	{
		cin >> i;	

		if(i==1)
		{
			cin >> k;
			insert(a,k);
		}
		else if(i==2)
		{
			delete_min(a);
			cout << "the modified heap is : ";
			for(j=0;j<a.size();j++)
				cout << a[j] << " ";
			cout << endl;
		}
		else if(i==3)
		{
			cout << "MINIMUM IS : " << find_min(a) << endl;
		}
		else if(i==4)
		{
			vector<int> v;
			cout << "enter 6 random numbers to convert in a heap\n";
			for(j=0;j<6;j++)
			{
				cin >> k;
				v.push_back(k);
			}
			heapify(v);
			for(j=0;j<v.size();j++)
				cout << v[j] << " ";
			cout << endl;
		}
		else if(i==-1)
		{
			flag=1;
			break;
		}

	}
	return 0;
}


