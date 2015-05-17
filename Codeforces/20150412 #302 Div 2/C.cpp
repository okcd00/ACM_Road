#include <map>
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

map<int,int> mii;

int main()
{
	mii.clear();
	int t,n,m,b,vmod;	scanf("%d%d%d%d",&n,&m,&b,&vmod);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		mii[t]++;
	}
	//cout<<mii.begin()->first<<":"<<mii.begin()->second<<endl;
	if(mii.begin()->first * ) 
	return 0;
}
