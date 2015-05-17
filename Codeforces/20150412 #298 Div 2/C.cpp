#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int n=0,d[200086]={0};
ll  a=0,b[200086]={0},s=0;

int main()
{
	scanf("%d%I64d",&n,&a);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
		s+=d[i];
	}
	for(int i=0;i<n;i++)
	{
		//不能取的有两种情况： 
		ll si=a-s+d[i]-1; //small_impossible=其他都取最大时，不能小于某值 
		ll bi=d[i]-a+n-1;//big_impossible=其他都取最小值1时，不能大于某值 
		ll ai=0LL;	//all_impossible 
		if(si>=0 && bi>=0) ai=si+bi;
		else if(si>=0) ai=si;
		else if(bi>=0) ai=bi;
		else ai=0LL;
		b[i]=max(0LL,ai);
		printf("%I64d",b[i]);
		if(i<n-1)printf(" "); 
	}
	return 0;
}
