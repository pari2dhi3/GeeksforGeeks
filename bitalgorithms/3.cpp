//Set bits in all numbers from 1 to n
#include<bits/stdc++.h>
using namespace std;
int set_bits1(int x)
{
	if(x<=0)
		return 0;
	return (((x%2==0)?0:1)+set_bits1(x/2));
}
int set_bits(int a)
{
	int bit_count=0,i;
	for(i=1;i<=a;i++)
		bit_count+=set_bits1(i);
	return bit_count;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int a;
	cin >> a;
	cout << "COUNT IS : " << set_bits(a) << endl;
	return 0;
}
