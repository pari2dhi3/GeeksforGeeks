//How to check if a given array represents a Binary Heap?
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[] = {90, 15, 10, 7, 12, 11};
	int size=6;
	int flag=0;
	int i=0,l=0,r=0;
	while(1)
	{
		l=2*i+1;
		r=2*i+2;
		if(l>(size-1))
			break;
		if(a[i]<a[l]||a[i]<a[r])
		{
			flag=1;
			break;
		}
		i++;
	}
	if(flag==1)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}
