#include <map>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int  n=0,pos=0,ans1=0,ans2=0;
bool vis	[111];
int  chain	[111];
int  cost	[111][111];

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

void dfs(int now)// make a linked chain of nodes
{
	vis[now]=true;
	chain[pos++]=now;
	for(int k=1;k<=n;k++)// find next
	{
		if(vis[k]==false && (cost[k][now]>0 || cost[now][k]>0))
		dfs(k);
	}
}

int main()
{
	memset(cost,0,sizeof(cost));
	memset(vis,false,sizeof(vis));
	int total_cost=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int _start=0,_end=0;
		scanf("%d%d",&_start,&_end);
		scanf("%d",&cost[_start][_end]);
		total_cost+=cost[_start][_end];
	}
	dfs(1);// start from 1,make a chain until 1 ends
	chain[pos]=1;// when end, we get back to 1
	for(int j=0;j<pos;j++)		ans1+= cost[chain[j]][chain[j+1]];
	for(int j=pos;j>=1;j--)		ans2+= cost[chain[j]][chain[j-1]];
	//cout<<total_cost<<endl<<ans1<<endl<<ans2<<endl;
	printf("%d",Min(ans1,ans2));
	return 0;
}
