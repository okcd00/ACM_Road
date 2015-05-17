#include <queue>
#include <cmath> 
#include <memory> 
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

int a[100001];
int dp[100001];

int cmp(const void *a, const void *b)
{
	return(*(int *)a-*(int *)b);
}

void arr_rev(int s,int e)
{
	int temp[100001];
	for(int i=s;i<=e;i++)
	{
		temp[i]=a[e+s-i];
	}
	for(int i=s;i<=e;i++)
	{
		a[i]=temp[i];
	}
}

int main()
{
	int n;	cin>>n;
	memset(a,0,sizeof a);
	memset(dp,0,sizeof dp);
	cin>>a[0];
	bool flag=true;
	int pos_start=0;
	for(int ni=1;ni<n;ni++)
	{
		cin>>a[ni];
		if(a[ni]>a[ni-1]) dp[ni]=dp[ni-1]+1;
		else 
		{
			dp[ni]=0;
			flag=false;
			if(pos_start==0)pos_start=ni;
		}
	}
	if(flag)
	{
		cout<<"yes"<<endl<<"1 1";
		return 0;
	}
	//for(int i=0;i<n;i++)cout<<dp[i]<<" ";
	int start=0,end=0;
	if(dp[1]==0)
	{
		end=1;
		int sup[100001];
		memset(sup,0,sizeof sup);
		while(dp[end]==0)
		{
			end++;
			if(end==n)break;
		}
		arr_rev(0,end-1);
	}
	else
	{
		start=pos_start-1;
		end=pos_start;
		while(dp[end]==0)
		{
			end++;
			if(end==n)break;
		}
		arr_rev(start,end-1);
	} 
	bool aflag=true;
	for(int i=1;i<n;i++)
	{
		//cout<<a[i]<<endl;
		if(a[i]<a[i-1])aflag=false;
	}
	puts(aflag?"yes":"no");
	if(aflag)cout<<start+1<<" "<<end<<endl;
	return 0;
}
