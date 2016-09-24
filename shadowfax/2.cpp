#include<bits/stdc++.h>
#include<set>
using namespace std;
/*void remove(vector<int> &vec) // This can be used in place of sets by removing duplicates an dafter sorting it//
  {
     sort( vec.begin(), vec.end() );
     vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
          return;
  }
*/
int main()
{
	ios_base::sync_with_stdio(false);
	int t,cmax,rmax,n,m,q,cmin,rmin; // cmax->max column's element difference, rmax-> max row's element difference 
	long long int regions,area_max,area_min;
	cin >> t;
	while(t--)
	{
		set<int> r,c; // to remove duplicates and sort the coordinates
		set<int>::iterator it1, it2;		
		scanf("%d %d %d",&n,&m,&q);
		int a,b,i;
		r.insert(1);
		c.insert(1);
		r.insert(n);
		c.insert(m);
		for(i=0;i<q;i++) // inserting the coordinates in a sorted way
		{
			scanf("%d %d", &a, &b);
			r.insert(a);
			c.insert(b);
		}
		regions=((long long int)((r.size()-1)*(c.size()-1))); // total number of regions
		it1=c.begin();
		it2=it1;
		it2++;
		rmax=0;
		cmax=0;
		rmin=n;
		cmin=m;
		for(;it2!=c.end();it1++,it2++) //finding max and min difference b/w 2 consecutive column elements
		{
			cmax=max(cmax,(*it2-*it1)); //using inbuilt fxn max
			cmin=min(cmax,(*it2-*it1));// using inbuilt fxn min
		}
                it1=r.begin();
                it2=it1;
                it2++;
		for(;it2!=r.end();it1++,it2++) //finding max andmin diff b/w 2 consecutive row elements
		{
			rmax=max(rmax,(*it2-*it1)); // inbuilt fxn max
			rmin=min(rmin,(*it2-*it1)); // inbuil fxn min
		}
		area_min=((long long int)rmin*cmin); // Multiplying to get min area and max area.
		area_max=((long long int)rmax*cmax);
		printf("%lld %lld %lld\n",regions,area_min,area_max);
	}
	return 0;
}
