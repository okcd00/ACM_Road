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

int rec[1001];
char graph[1001][1001];

int main()
{
	memset(rec,0,sizeof(rec));
	memset(graph,' ',sizeof(graph));
	int cases=0,max=0,min=0,now=0,width=0;
	scanf("%d",&cases);
	for(int _case=0;_case<cases;_case++)
	{
		scanf("%d",&rec[_case]);
			if(_case%2==0) now+=rec[_case];
			else now-=rec[_case];
		width+=rec[_case];
			if(now>max) max=now;
			else if(now<min) min=now;
	}
	int height=max-min;
	//graph is a width_Row x height_Col picture
	
	int record=0,count=rec[0],ypos=max-1,dir=0;
	char sig;
	for(int x=0;x<width;x++)
	{
		if(record%2==0)sig='/';
		else sig='\\';
		graph[ypos][x]=sig;
		count--;
		if(count==0)
		{
			record++;
			count=rec[record];
		}
		else
		{
			if(record%2==0) ypos--;
			else ypos++;
		}
	}
	
	for(int _i=0;_i<height;_i++)
	{
		for(int _j=0;_j<width;_j++)
		{
			printf("%c",graph[_i][_j]);
		}
		if(_i!=height-1)printf("\n");
	}
	
	return 0;
}
