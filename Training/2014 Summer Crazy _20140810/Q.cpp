#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int co[4];
queue<int> q;

int main()
{
	int n,cnt=0;	cin>>n;
	memset(co,0,sizeof co);
	while(!q.empty())q.pop();
	for(int i=0;i<n;i++)
	{
		int now;	cin>>now;
		if(now==4) cnt++;
		else co[now]++;
	}
	if(co[3]!=0)
	{
		int min31=min(co[3],co[1]);
		co[3]-=min31;
		co[1]-=min31;
		cnt+=min31;
		if(co[3]!=0) cnt+=co[3],co[3]=0;
	}
	if(co[2]!=0)
	{
		int m22=co[2]/2;
		co[2]-=m22*2;
		cnt+=m22;
		if(co[2]!=0 && co[1]!=0)
		{
			if(co[1]==1)
			{
				co[1]-=1;
				co[2]-=1;
				cnt++;
				cout<<cnt;
				return 0;
			}
			co[2]-=1;
			co[1]-=2;
			cnt++;
		}
		else if(co[2]!=0 && co[1]==0)
		{
			co[2]=0;
			cnt++;
		}
	}
	if(co[1]!=0)
	{
		int m1111=co[1]/4;
		co[1]-=m1111*4;
		cnt+=m1111;
		if(co[1]!=0)
		{
			co[1]=0;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
