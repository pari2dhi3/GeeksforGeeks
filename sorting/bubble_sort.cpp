#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={5,9,12,3,4,1,0,10,6,13};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i,j;
	bool swapped;
	for(i=0;i<size;i++)
	{
		swapped=false;
		for(j=0;j<(size-i-1);j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=true;
			}
		}
		if(swapped==false)
			break;
	}
	for(i=0;i<size;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

