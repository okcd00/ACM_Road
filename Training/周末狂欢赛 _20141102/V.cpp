#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n,x;	cin>>n>>x; 
	int l=0,	r=1000;
	for(int i=0;i<n;i++)
	{
		int a,b;	cin>>a>>b;
		if(a>b)		swap(a,b);
		l=max(l,a),	r=min(r,b);
	}
	if(l>r)puts("-1");
	else if(r<x)printf("%d\n",x-r);
	else if(x<l)printf("%d\n",l-x);
	else puts("0");
	return 0;
}
