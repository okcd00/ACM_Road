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

bool usd[100086];

int main()
{
	int n,k,f=1,now;	
	scanf("%d%d",&n,&k);
	memset(usd,false,sizeof usd);
	for(int i=1;i<=k;i++)
	{
		if(f) now=(i+1)/2;
		else now=2+k-i/2;
		f=1-f;
		if(i-1)	printf(" %d",now);
		else printf("%d",now);
		usd[now]=true;
	}
	//cout<<"then"<<endl;
	for(int i=1;i<=n;i++)
	{
		if(usd[i]==false)
		printf(" %d",i);
	}
	return 0;
}
