#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

bool judge(ll n)
{
	ll nn=abs(n);
	while(nn)
	{
		int now=nn%10;
		if(now==8)return true;
		else nn/=10;
	}
	return false;
}

int main()
{
	ll n;	cin>>n;
	for(ll i=1;;i++)
	{
		if(judge(n+i))
		{
			printf("%d",i);
			return 0;
		} 
	}
	return 0;
}
