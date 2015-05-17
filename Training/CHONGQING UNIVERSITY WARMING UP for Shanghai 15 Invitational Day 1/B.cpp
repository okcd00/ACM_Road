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

struct Node
{
	int x;
	int y;
};

map<Node,int> mn;
int xpos[10086]={0};
int ypos[10086]={0};

int main()
{
	int n,w,h;
	while(scanf("%d",&n)!=EOF && n>0)
	{
		mn.clear();
		memset(xpos,0,sizeof xpos);
		memset(ypos,0,sizeof ypos);
		scanf("%d%d",&w,&h);
		for(int i=0;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
		}
		
		printf("%d\n",ans); 
	} 
	return 0;
}
