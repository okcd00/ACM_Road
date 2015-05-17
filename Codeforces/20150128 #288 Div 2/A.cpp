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

int mp[1002][1002]={0};

bool judge(int r,int c)
{
	if(mp[r-1][c]==1)
	{
		if(mp[r][c-1]==1)
		{
			if(mp[r-1][c-1]==1)return true;
		}
		if(mp[r][c+1]==1)
		{
			if(mp[r-1][c+1]==1)return true;
		}
	}
	if(mp[r+1][c]==1)
	{
		if(mp[r][c-1]==1)
		{
			if(mp[r+1][c-1]==1)return true;
		}
		if(mp[r][c+1]==1)
		{
			if(mp[r+1][c+1]==1)return true;
		}
	}
	return false;
}

int main()
{
	int n,m,k;	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int r,c;	scanf("%d%d",&r,&c);
		mp[r][c]=1;
		if(judge(r,c))
		{
			cout<<i;
			return 0;
		} 
	}
	cout<<0;
	return 0;
}
