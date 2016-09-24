#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,rmax,cmax,n,m,q,rmin,cmin;
	long long int count,amax,amin;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		int a,b,i;

		set<int>r,c;
		r.insert(1);
		c.insert(1);
		r.insert(n);
		c.insert(m);

		for(i=0;i<q;i++)
		{
			scanf("%d%d",&a,&b);
			r.insert(a);
			c.insert(b);
		}	

		set<int>::iterator it1=r.begin();
		set<int>::iterator it2=c.begin();
		it2++;

		rmax=0;
		cmax=0;
		rmin=n;
		cmin=m;

		for(;it2!=r.end();it1++,it2++)
		{
			rmax=max(rmax,*it2-*it1);
			rmin=min(rmin,*it2-*it1);
		}
		it1=c.begin();
		it2=it1;
		it2++;
		for(;it2!=c.end();it1++,it2++)
		{
			cmax=max(cmax,*it2-*it1);
			cmin=min(cmin,*it2-*it1);

		}
		count=(long long int)(r.size()-1)*(c.size()-1);
		amax=((long long int)rmax*cmax);
		amin=((long long int)rmin*cmin); 
		printf("%lld %lld %lld\n",count,amin,amax);
	}
	return 0;
}
