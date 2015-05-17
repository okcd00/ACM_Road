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

int main()
{
	int n,k;	cin>>n>>k;
	int v[4]={1,2,3,5};
	printf("%d\n",(n*6-1)*k);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(j==0) printf("%d",v[j]*k);
			else printf(" %d",v[j]*k);
			v[j]+=6;
		}
		printf("\n");
	}
	return 0;
}
