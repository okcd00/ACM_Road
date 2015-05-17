#include <cmath> 
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[2000086]={0};
int b[2000086]={0};
int frt[2000086]={0};
int bnd[2000086]={0};
int ans[2000086]={0};
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n=0;	cin>>n;
	int head,tail;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		frt[b[i]]=a[i];
		bnd[a[i]]=b[i];
		if(a[i]==0) head=b[i];
		if(b[i]==0) tail=a[i];
	}
	int now=head,pos=1,tmp=0;
	while(now)
	{
		ans[pos]=now;
		now=bnd[now];
		if(now) frt[now]=0;
		pos+=2; 
	}
	if(n%2==0) 
	{
		now=tail,pos=n-2;
		while(now)
		{
			ans[pos]=now;
			now=frt[now];
			pos-=2;
		}
	}
	else 
	{
		int pi;
		for(int i=0;i<n;i++)
		{
			if(frt[b[i]] && b[i]!=0)
			{
				pi=b[i];
				while(frt[pi])
				{
					pi=frt[pi];
				}
				break;
			}
		}
		int now=pi,pos=0,tmp=0;
		while(now)
		{
			ans[pos]=now;
			now=bnd[now];
			if(now) frt[now]=0;
			pos+=2; 
		}
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d",ans[i]);
		if(i<n-1)printf(" ");
	}
	return 0;
}
