#include<stdio.h>
long top[100000],a,max;
int bsearch(long int *top,int low,int high,int val)
{
	int mid = (low+high)/2;
	if(low==high)
		return low;
	if(top[mid]>val && (mid==0 || top[mid-1]<=val ))
		return mid;
	else if(top[mid]<=val)
		bsearch(top,mid+1,high,val);
	else
		bsearch(top,low,mid-1,val);
}
int main()
{
	int t,n,s,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		i=n;
		s=0;
		while(i--)
		{
			scanf("%ld",&a);
			if(i==n-1 || max <= a )
			{
				max = a;
				top[s++]=a;
				continue;
			}
			j = bsearch(top,0,s-1,a);
			if(top[j]==max)
				max=a;
			top[j]=a;
		}
		printf("%d ",s);
		for(i=0;i<s;i++)
			printf("%ld ",top[i]);
		printf("\n");
	}
return 0;
}	
