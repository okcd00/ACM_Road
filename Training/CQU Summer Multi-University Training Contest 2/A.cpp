#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int p[5001];
int pro[50001];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(p,0,sizeof p);
		memset(pro,0,sizeof pro);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);	
		}
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			pro[a][b]=pro[b][a]=c;
		}
		
	}
	return 0;
} 
