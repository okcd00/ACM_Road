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


int  lbval[100002];
int**  sup=new int*[100002]; //0-no 1-val
bool used[100002];
int lowbit(int x){return x&(-x);}

bool cmp_0(int *a,int* b){	return a[0]>b[0];}
bool cmp_1(int *a,int* b){	return a[1]<b[1];}

void lb_init()
{
	for(int i=1;i<=100000;i++)
	lbval[i]=lowbit(i);
}

int main()
{
	for(int i=0;i<=100001;i++)	{		sup[i]=new int[2];   	}
	//freopen("in.txt","r",stdin);
	memset(sup,0,sizeof(sup));
	memset(lbval,0,sizeof(lbval));
	memset(used,false,sizeof(used));
	lb_init();
	int sum=0,limit=0,total=0;
	scanf("%d%d",&sum,&limit);
	for(int i=1;i<=limit;i++)		
	{
		sup[i]=new int[2];
		sup[i][0]=i;
		total+=sup[i][1]=lbval[i];
	}
	if(total<sum)
	{
		printf("-1");
		return 0;
	}
	else if(total==sum)
	{
		printf("%d\n",limit);
		for(int i=1;i<=limit;i++)
		{
			printf("%d",i);
			if(i!=limit)printf(" ");
		}
		return 0;
	}
	sort(sup+1,sup+limit,cmp_1);
	int cnt=0;
	for(int i=limit;i>1&&sum>=0;i--)
	{
		if(sum>=sup[i][1])
		{
			sum-=sup[i][1];
			used[sup[i][0]]=true;
			cnt++;
		}
		if(sum==0)break;
	}
	printf("%d\n",cnt);
	sort(sup+1,sup+limit,cmp_0);
	for(int i=1;i<=limit;i++)
	{
		if(used[i]==true)
		{
			printf("%d",i);
			if(i!=limit)printf(" ");
		}
	}
	return 0;
}
