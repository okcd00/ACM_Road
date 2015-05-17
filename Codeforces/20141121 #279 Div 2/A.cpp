#include <cmath> 
#include <cctype>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int t[10086]={0};
int a[5]={0};
vector<int> q[5];
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n=0;	cin>>n;
	for(int i=0;i<5;i++)q[i].clear();
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t[i]);
		a[t[i]]++;
		q[t[i]].push_back(i+1);
	}
	int minv=min(a[1],min(a[2],a[3]));
	printf("%d\n",minv);
	for(int i=0;i<minv;i++)
	{
		printf("%d %d %d\n",q[1][i],q[2][i],q[3][i]);
	}
	return 0;
}
