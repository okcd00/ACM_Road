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

ll ans=0LL,tmp=0LL;
int dp[200086]={0};
int mrk[200086]={0};

int main()
{
	int n=0, now=0, i;	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&dp[i]);
	}
	int m=0;	cin>>m;
	for(i=0;i<m;i++)
	{
		scanf("%d",&now);
		mrk[now]++;
	}
	while(mrk[i]==0)i++; 
	for(i=1;i<=n;i++)
	{
		
	}
	return 0;
}
