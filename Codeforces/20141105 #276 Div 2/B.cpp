#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=(int)1e9+10086;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n;	cin>>n;
	int up=-inf,down=inf,left=inf,right=-inf;
	for(int i=0;i<n;i++)
	{
		int x,y;	cin>>x>>y;
		if(x<left)	left=x;
		if(x>right)	right=x;
		if(y<down)	down=y;
		if(y>up)	up=y;
	}
	int len=max(up-down,right-left);
	cout<<(long long)len*len;
	return 0;
}
