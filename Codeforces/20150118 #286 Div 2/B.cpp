#include <cmath> 
#include <queue>
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
int n,m,q;
int ans[101]={0};
int map[101][101][101]={0};

int bfs(int j,int u,int v)
{
	int vis[101]={0};
	queue<int> q;
	while(!q.empty())q.pop();
	q.push(u);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		if(now==v) return 1;
		vis[now]=1;
		for(int i=0;i<=n;i++)
		{
			if(map[j][now][i]==1 && vis[i]==0)
			{
				vis[i]==1;
				q.push(i);
			}
		}
	}
	return 0;
} 

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;	scanf("%d%d%d",&a,&b,&c);
		map[c][a][b]=1;
		map[c][b][a]=1;
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int tu,tv;	scanf("%d%d",&tu,&tv);
		int u=min(tu,tv),v=max(tu,tv);
		for(int j=1;j<=m;j++)
		{
			ans[i]+=bfs(j,u,v);
		}
		cout<<ans[i]<<endl;
	} 
	return 0;
}
