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

int army[1024];

int cnt_s(int a)
{
	int cnt=0,	tmp=a;
	while(tmp!=0)
	{
		cnt+=tmp%2;
		tmp/=2;
	} 
	return cnt;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	memset(army,0,sizeof army); 
	for(int i=1;i<=m+1;i++)
		scanf("%d",&army[i]);
	int cnt=0;
	for(int i=1;i<=m;i++)
		if(cnt_s(army[i]^army[m+1])<=k)cnt++;
	cout<<cnt;
	return 0;
}
