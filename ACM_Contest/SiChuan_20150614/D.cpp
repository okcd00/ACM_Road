#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
bool vis[505];
vector<int> vt[505];
int n,m,u,v,pre[505],ans;

void init()
{
	ans=0;
	memset(pre,-1,sizeof pre);
	for(int i=1;i<=500;i++)	vt[i].clear();
}

int find(int x) 
{
	for(int i=0;i<vt[x].size();i++) 
	{
		int to=vt[x][i];
		if (vis[to]) continue;
		vis[to]=1;
		if (pre[to]==-1||find(pre[to])) 
		{
			pre[to]=x;
			return 1;
		}
	}
	return 0;
}
int main() 
{
	while (~scanf("%d%d",&n,&m)) 
	{
		init();	
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,false,sizeof vis);
			ans+=find(i);
		}
		printf("%d\n",ans/2);
	}
	return 0;
}

