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
int n,m,c0,d0;
int a[1001],b[1001],c[1001],d[1001];
int stime[1001],

int main()
{
	cin>>n>>m>>c0>>d0;
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	memset(d,0,sizeof d);
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		stime[i]=a[i]/b[i];
		
	} 
	return 0;
} 
