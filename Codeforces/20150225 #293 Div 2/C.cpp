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

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

map<int,int> fdpos,fdnum; //num->pos & pos->num

int main()
{
	fdpos.clear();
	fdnum.clear();
	long long ans=0; // LL大法好……
	int n,m,k;	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int now;	scanf("%d",&now);
		fdpos[now]=i;
		fdnum[i]=now;
	}
	for(int i=1;i<=m;i++)
	{
		int now;	scanf("%d",&now);
		int pos=fdpos[now];
		ans+=(pos/k)+(pos%k==0?0:1);
		//swap
		if(pos>1)
		{
			int t=fdnum[pos-1];
			fdnum[pos-1]=now;
			fdpos[now]=pos-1;
			fdnum[pos]=t;
			fdpos[t]=pos;
		}
	}
	cout<<ans;
	return 0;
}
