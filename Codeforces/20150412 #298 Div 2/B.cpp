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

int v[128]={0};

int getsum(int t)
{
	int s=0;	//就这里忘了初始化0，就给我算错么Q^Q 
	for(int i=0;i<t;i++)
	{
		s+=v[i];
		//cout<<i<<":"<<v[i]<<endl;
	}
	return s;
}

int main()
{
	int v1=0,v2=0,t=0,d=0,l=0,r=0;
	scanf("%d%d%d%d",&v1,&v2,&t,&d);
	v[0]=v1,v[t-1]=v2,r=t-1;//r=t-1 forgotten
	for(int i=1;i<t-i-1;i++)
	{
		l=i,r=t-i-1;
		v[l]=v[l-1]+d;
		v[r]=v[r+1]+d;
		//cout<<v[l]<<":"<<v[r]<<endl;
	}
	if(t%2)
	{
		l++;
		v[l]=v[l-1]+d;
	}
	//cout<<l<<":"<<r<<endl;
	while(abs(v[l]-v[r])>d)
	{
		if(v[l]>v[r]) v[l--]=v[r--]+d;
		else v[r++]=v[l++]+d;
	}
	cout<<getsum(t)<<endl;
	return 0;
}
