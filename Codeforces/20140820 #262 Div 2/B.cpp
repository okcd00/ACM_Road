#include <cmath> 
#include <queue>
#include <vector>
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
ll a,b,c;
ll vpow[88][8];
priority_queue< int,vector<int>,greater<int> > pq;

int s(ll x)
{
	ll tmp=x;
	ll ret=0;
	while(tmp)
	{
		ret+=tmp%10;
		tmp/=10;
	} 
	return ret;
}

void init()
{
	while(!pq.empty())pq.pop();
	for(int i=1;i<=81;i++)
	{
		vpow[i][1]=i;
		for(int j=2;j<=5;j++)
			vpow[i][j]=vpow[i][j-1]*i;
	}
	
}

void solve()
{
	ll temp;
	for(int i=1;i<=81;i++)
	{
		temp=(ll)vpow[i][a]*(ll)b+(ll)c;
		if(s(temp)==i && temp>0 && temp<(int)1e9) 
		{
			int tmp=vpow[i][a]*b+c;
			pq.push(tmp);
		}
	}
	if(pq.empty())	printf("0\n");
	else
	{
		printf("%d\n",pq.size());
		while(!pq.empty())
		{
			int a=pq.top();
			printf("%d ",a);
			pq.pop(); 
		}
	}
}

int main()
{
	cin>>a>>b>>c; 
	init();
	solve();
	return 0;
}
