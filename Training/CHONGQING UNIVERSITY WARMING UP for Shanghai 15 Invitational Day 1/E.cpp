#include <map>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct loc
{
	int x;
	int y;
	loc(int a,int b)
	{
		x=a;
		y=b;
	}
};

typedef pair<loc,loc> pll;
map<pll,int> pdor;
map<loc,int> pkey;

int vis[64][64]={0};
queue<loc> qp;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		while(!qp.empty()) qp.pop();
		memset(vis,0,sizeof vis);
		
		int m,p,k;	scanf("%d%d%d",&m,&p,&k);
		int x1,y1,x2,y2,g;
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
			
			loc t1(x1,y1),t2(x2,y2);
			pdor[make_pair(t1,t2)]=1;
		}
		int s;	scanf("%d",&s);
		int xx,yy,q;
		for(int i=0;i<s;i++)
		{
			scanf("%d%d%d",&xx,&yy,&q);
			loc t(xx,yy);
			pkey[t]=1;
		} 
		
	}
	return 0;
}
