#include <map>
#include <stack>
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

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int cmp(const void *a, const void *b)
{
	return(*(int *)a-*(int *)b);
}

int que[101];

int main()
{
	int n=0,m=0;
	scanf("%d%d",&n,&m);
	memset(que,0,sizeof(que));
	//queue<int> q;
	//while(!q.empty()) q.pop();
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		scanf("%d",&tmp);
		que[i]=tmp;
	}
	int rest=m,cnt=0,now=0;
	while(que[n-1]!=0)
	{
		if(rest<que[now])
		{
			cnt++;
			rest=m;
		}
		else
		{
			rest-=que[now];
			que[now]=0;
			now++;
		}
	}
	if(rest!=m)cnt++; 
	printf("%d",cnt);
	return 0;
}
