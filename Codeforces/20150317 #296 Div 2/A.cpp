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
	long long a=0,b=0,c=0,t=0;
	cin>>a>>b;
	while(a!=b)
	{
		if(a%b)
		{
			c+=(a/b);
			a=a%b;
			t=a;
			a=b;
			b=t;
		}
		else
		{
			c+=(a/b);
			a=b;
		}
	}
	cout<<c<<endl; 
	return 0;
}
