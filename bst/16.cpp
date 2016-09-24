//Check for Identical BSTs without building the trees
#include<bits/stdc++.h>
using namespace std;
int find_small(int arr[],int curr,int size)
{
	int i;
	for(i=curr+1;i<=size;i++)
	{
		if((arr[i]<arr[curr])&&(arr[i]!=-1))
		{
			arr[i]=-1;
			return i;
		}
	}
	return 0;
}
int find_big(int arr[], int curr, int size)
{
	int i;
	for(i=curr+1;i<=size;i++)
	{
		if((arr[i]>arr[curr])&&(arr[i]!=-1))
		{
			arr[i]=-1;
			return i;
		}
	}
	return 0;
}
bool check(int arr1[], int arr2[],int curr1, int curr2, int size)
{
	
	int l_in1=0,l_in2=0,r_in1=0,r_in2=0;
	l_in1=find_small(arr1,curr1,size);
	l_in2=find_small(arr2,curr2,size);
	r_in1=find_big(arr1,curr1,size);
	r_in2=find_big(arr2,curr2,size);
	if((l_in1==0 && l_in2==0) ||(r_in1==0 && r_in2==0))
		return true;
	if(arr1[l_in1]==arr2[l_in2] && arr1[r_in1]==arr2[r_in2])
	{
		return check(arr1,arr2,l_in1,l_in2,size) && check(arr1,arr2,r_in1,r_in2,size);
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int arr1[9]={8,3,6,1,4,7,10,14,13}, arr2[9]={8,10,14,3,6,4,1,7,13};
	int size=(sizeof(arr1)/sizeof(arr1[0]));
	if(check(arr1,arr2,0,0,size))
		cout << "THEY FORM IDENTICAL BST\n";
	else
		cout << "THEY DONOT FORM IDENTICAL BST\n";
	return 0;
}
