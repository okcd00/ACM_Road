#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
int n,m,map[505][505],prime[MAXN];

void init()
{
	int k=1;
	memset(prime,1,sizeof(prime));
	prime[0]=prime[1]=0;
	for(int i=2;i<=MAXN;i++)if(prime[i])	for(int j=i+i;j<=MAXN;j+=i)	prime[j]=0;
}

int find(int x)
{
	int i=x+1;	for( ;!prime[i];i++);
	return i-x;
}

int main()
{
	init();
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		int e;	cin>>e;
		if(!prime[e])	map[i][j]=find(e);
		else			map[i][j]=0;
	}
	int ans=INF;
	for(int j=0;j<m;j++)
	{
		int tempans=0;
		for(int i=0;i<n;i++)	tempans+=map[i][j];
		ans=min(tempans,ans);
	}
	for(int i=0;i<n;i++)
	{
		int tempans=0;
		for(int j=0;j<m;j++)	tempans+=map[i][j];
		ans=min(tempans,ans);
	}
	cout<<ans<<endl;
	return 0;
}
