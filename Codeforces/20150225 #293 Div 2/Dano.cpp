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

int n,t;
double p=0.0,ans=0.0,v=0.0;
double vpow[2222][2222]={0};

bool cmp(const int a, const int b)
{
	return a > b;
}

void dfs(int l,int r)
{
	if(l==n || l+r==t)	//no other people OR at bottom
	{
		if(vpow[l][r]==0)
		{
			v=pow(p,(double)l)*pow(1.0-p,(double)r);
			vpow[l][r]=v;
		}
		else v=vpow[l][r];
		ans+=(double)l*v;
	}
	else
	{
		dfs(l+1,r);
		dfs(l,r+1);
	}
}

int main()
{
	cin>>n>>p>>t;
	if(t<=n){printf("%.9f",p*t);return 0;}
	dfs(0,0);
	printf("%.9f",ans);
	return 0;
}
