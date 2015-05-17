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

int sta[1024];
int dp[1024];

int main()
{
	int n;	cin>>n;
	memset(sta,0,sizeof sta);
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sta[i]);
		if(sta[i]==1 && sta[i-1]==1) dp[i]=dp[i-1]+1;
		else if(sta[i]==1 && sta[i-1]==0) dp[i]=dp[i-1]+1;
		else if(sta[i]==0 && sta[i-1]==1) dp[i]=dp[i-1]+1;
		else if(sta[i]==0 && sta[i-1]==0) dp[i]=dp[i-1];
		if(sta[n]==0 && dp[n]!=0)	dp[n]--;
		//cout<<dp[i]<<" ";
	}
	cout<<dp[n]<<endl;
	
	return 0;
}
