#include <cmath>   
#include <vector>  
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define MAXN 51
#define _run(x) for(;p[t=x];x=p[x],p[t]=(p[x]?p[x]:x))
#define _run_both _run(i);_run(j)
using namespace std;

int in[MAXN];
int rct[MAXN][MAXN];

class DSet
{
public:
	int p[MAXN],t;
	void init()
	{
		memset(p,0,sizeof p);
	}	
	void setFriend(int i,int j)
	{
		_run_both;
		p[i]=(i==j?0:j);
	}
	bool isFriend(int i,int j)
	{
		_run_both;
		return i==j && i;
	}
}

int main()
{
	int n,m,dan=1;
	scanf("%d%d",&n,&m);
	memset(in,0,sizeof in);
	memset(rct,0,sizeof react);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		rct[a][b]=rct[b][a]=1;
	}
	for(int it=1;it<=m;it++)
	{
		int flag=0;
		for(int _i=1;_i<=n;_i++)
		{
			if(in[_i]==1)continue;
			for(int _j=1;_j<=n;_j++)
			{
				if(_j==_i)continue;
				if(rct[_i][_j]==1) //DEAD IN DSET 并查集学习决定 
				{
					setFriend(_i,_j);
					in[_j]=1;
					dan*=2;
					flag=1;
					break;
				}
				else continue;
			}
			if(flag==1)break;
			else
			{
					
			}
		}
	}
	
	return 0;
} 
