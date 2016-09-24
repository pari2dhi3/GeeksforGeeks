#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,p1,p2,set1,set2,xo,n;
	cout << "Enter the number, its position, and width\n";
	cin >> x >> p1 >> p2 >> n;
	set1 = (x >> p1) & ((1U << n)-1);
	set2 = (x >> p2) & ((1U << n)-1);
	xo = set1 ^ set2;
	xo = (xo << p1) | (xo << p2);
	x = x ^ xo;
	cout << "x = " << x << endl;
	return 0;
}
